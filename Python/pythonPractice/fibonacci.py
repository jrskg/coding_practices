def fib(n):
	if(n == 1 or n == 2):
		return n-1
	else:
		return fib(n-1)+fib(n-2)
	
m = int(input("Enter a number:\n"))
print("The number at position no",m,"is",fib(m))