# import threading
import time
from concurrent.futures import ThreadPoolExecutor

def myFunc(sec, tag):
    print(f"Sleeping for {sec} seconds")
    time.sleep(sec)
    return tag

# def poolingDemo():
#     with ThreadPoolExecutor() as executor:
#         future1 = executor.submit(myFunc, 4, 'First')
#         future2 = executor.submit(myFunc, 3, 'Second')
#         future3 = executor.submit(myFunc, 2, 'Third')
        
#         print(future2.result())
#         print(future3.result())
#         print(future1.result())

# poolingDemo()




def pollingDemoWithMap():
    with ThreadPoolExecutor() as executor:
        l1 = [7, 4, 6, 3]
        l2 = ["First", "Second", "Third", "Fourth"]

        results = executor.map(myFunc, l1, l2)
        for result in results:
            print(result)

pollingDemoWithMap()

# print(myFunc(2, "first"))
# print(myFunc(3, "second"))
# print(myFunc(1, "third"))

# t1 = threading.Thread(target=myFunc, args=[2, "First"])
# t2 = threading.Thread(target=myFunc, args=[3, "Second"])
# t3 = threading.Thread(target=myFunc, args=[1, "Third"])

# t1.start()
# t2.start()
# t3.start()

# t1.join()
# t2.join()
# t3.join()
