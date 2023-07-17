from pytube import YouTube
import os
import moviepy.editor as mp

# for debugging only
def debugPrintForDownloads(medias):
    index = 1
    for media in medias:
        print(index, media)
        index+=1
    print("")


def printAvailableDownloads(medias, mediaType):
    print("Available downloads are : ")
    index = 1
    for media in medias:
        if(mediaType == 1):
            print(f"{index}.Size:{round(media.filesize/(1024*1024))}MB, Resolution:{media.resolution}, MimeType:{media.mime_type}, FPS:{media.fps}")
        else:
            print(f"{index}.Size:{round(media.filesize/(1024*1024))}MB, abr:{media.abr}, MimeType:{media.mime_type}")
        index+=1
    print("")

def renameFile(outMedia, medType):
    base, ext = os.path.splitext(outMedia)
    if(medType == "audio"):
        newFile = base+" audio.mp3"
    else:
        newFile = base+" video.mp4"
    os.rename(outMedia, newFile)
    return newFile

def mergeAudioVideo(video, audio, title):
    videoFile = mp.VideoFileClip(video)
    audioFile = mp.AudioFileClip(audio)

    videoFile = videoFile.set_audio(audioFile)
    videoFile.write_videofile(title+".mp4", threads=4)
# *************************************main starting here *****************************************************************************
link = input("Enter the video link : ")
yt = YouTube(link.strip())
mediaType = int(input("\nWhat you want to download ?\nPress 1 for video press 2 for audio : "))

if(mediaType == 1):
    print("\nPlease wait...")
    medias = yt.streams.filter(only_video=True)
    printAvailableDownloads(medias, mediaType)
    mediaIndex = int(input("Enter a number from above list to start download : "))

    if(medias[mediaIndex-1].is_progressive):
        print("Downloading your media...")
        medias[mediaIndex-1].download()
    else:
        audioStream = yt.streams.filter(only_audio=True, abr="128kbps", subtype="mp4")
        print("Downloading video...")
        videoFile = medias[mediaIndex-1].download()
        videoFile = renameFile(videoFile, "video")
        print("Now downloading audio...")
        audioFile = audioStream[0].download()
        audioFile = renameFile(audioFile, "audio")
        print("Now merging video and audio please wait...")
        mergeAudioVideo(videoFile, audioFile, medias[0].title)

elif(mediaType == 2):
    print("\nPlease wait...")
    medias = yt.streams.filter(only_audio=True)
    printAvailableDownloads(medias, mediaType)
    mediaIndex = int(input("Enter a number from above list to start download : "))
    print("\nDownloading your media...")
    audioFile = medias[mediaIndex-1].download()
    renameFile(audioFile, "audio")
else:
    print("Invalid input provided !!!")
    exit()

print("Media downloaded successfully")