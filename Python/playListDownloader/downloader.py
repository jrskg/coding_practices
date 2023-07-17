import concurrent.futures
from pytube import Playlist, YouTube
import os

def download_media(url, media_type):
    yt = YouTube(url)
    try:
        if(media_type == 1):
            media = yt.streams.filter(progressive=True, file_extension="mp4", res="720p").first()
        else:
            media = yt.streams.filter(only_audio=True, mime_type="audio/mp4", abr="128kbps").first()
    except Exception as e:
        print(f"Error :- '{e}'-->Skipping...")
        return
    print(f"Downloading {media.title[:30]}...")
    out = media.download("./downloadedVideos")
    if(media_type == 2):
        base,ext = os.path.splitext(out)
        newFile = base+".mp3"
        os.rename(out, newFile)
    print(f"Finished downloading {media.title[:30]}...")

def multiThreadDownloading(urls, max_simultaneous_downloads, media_type):
    with concurrent.futures.ThreadPoolExecutor(max_workers=max_simultaneous_downloads) as executor:
        tasks = []
        for i in range(max_simultaneous_downloads):
            task = executor.submit(download_media, urls[i], media_type)
            tasks.append(task)
        
        for i in range(max_simultaneous_downloads, len(urls)):
            completed_task = concurrent.futures.as_completed(tasks)
        
            completed_url = next(completed_task)
            completed_index = tasks.index(completed_url)
            
            new_task = executor.submit(download_media, urls[i], media_type)
            tasks[completed_index] = new_task

if __name__ == "__main__":
    way = int(input("1 for Playlist\n2 for single : "))
    if(way != 1 and way != 2):
        print("Invalid input")
        exit()

    link = input(f"Enter {'playlist' if way == 1 else 'video'} url : ")
    media_type = int(input("Enter 1 for video and 2 for audio : "))
    if(media_type != 1 and media_type != 2):
        print("Invalid media type format")
        exit()
    
    if(way == 1):
        urls = list(Playlist(link.strip()))
        total = len(urls)
        maxToShow = 5 if total > 5 else total 
        max_simultaneous_downloads = int(input(f"Enter max simultaneous downloads count (1-{maxToShow}) : "))
        if(max_simultaneous_downloads > maxToShow):
            print("Maximum download is greater than suggestion")
            exit()
        multiThreadDownloading(urls, max_simultaneous_downloads, media_type)
    else:
        download_media(link.strip(), media_type)

            
            
    
    



