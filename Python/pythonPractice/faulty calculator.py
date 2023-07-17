print("Enter the two numbers")
num1 = int(input())
num2 = int(input())
print("Which operator you want to use")
operator = input("+,  *,  /,  - \n")
if operator=='*':
	if num1==45 and num2==3 or num1==3 and num2==45:
		print("Your ans is 555.")
	else:
		print("Your answer is",num1*num2)
elif operator=='+':
	if num1==56 and num2==9 or num1==9 and num2==56:
		print("Your ans is 77.")
	else:
		print("Your answer is",num1+num2)
elif operator=='/':
	if num1==56 and num2==6 or num1==6 and num2==56:
		print("Your ans is 4.")
	else:
		print("Your answer is",num1/num2)
elif operator=='-':
	if num1==50 and num2==8 or num1==8 and num2==50:
		print("Your ans is 47.")
	else:
		print("Your answer is",num1-num2)
else:
	print("Error!! Please check the operator and enter again.")

