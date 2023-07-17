import multiprocessing
import requests
from concurrent.futures import ProcessPoolExecutor

def downloadFile(url, name):
    print(f"Started downloading {name}")
    response = requests.get(url)
    open(f"./files/{name}.jpg", "wb").write(response.content)
    print(f"Finished downloading {name}")

def multiProcesingDownload(urlList):
    pros = []
    for i, val in enumerate(urlList):
        # downloadFile(val, i+1)
        p = multiprocessing.Process(target=downloadFile, args=[val, i])
        p.start()
        pros.append(p)
    for p in pros:
        p.join()

def multiDownloadMap(urlList):
    with ProcessPoolExecutor() as executor:
        executor.map(downloadFile, urlList, [i for i in range(0, len(urlList))])

if __name__ == "__main__":
    url = "https://picsum.photos/2000/3000"
    urlsList = [url for i in range(5)]

    multiDownloadMap(urlsList)