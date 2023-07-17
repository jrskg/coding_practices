num1 = input("Enter num1\n")
num2 = input("Enter num2\n")

try:
	print("The sum is",int(num1)+int(num2))
#except Exception as e: you even can write like this as well
except Exception:
	print("No internet connection")
	
print("Hello")