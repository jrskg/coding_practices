import time

initial = time.time()

a = int(input("Enter the number of rows\n"))
print("Please wait. . .")
time.sleep(3)
b = bool(int(input("Enter 1 or 0 for changing pattern\n")))

def pattern(a, b):
	co = 1
	if b == True:
		while(co <= a):
			print(co * "*")
			co = co + 1
	elif b == False:
		while(a != 0):
			print(a * "*")
			a = a - 1
			
pattern(a, b)
print("It take",time.time()-initial,"second")

current = time.asctime(time.localtime(time.time()))
print(current)