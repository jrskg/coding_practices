a = int(input("Enter the number of rows\n"))
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
"""
if b == True:
	for i in range(0, a+1):
		print(i * "*")
elif b == False:
	for i in range(a, 0, -1):
		print(i * "*")
		"""