print("Enter your age")
age = int(input())

if age < 10:
	print("You cannot drive.")
elif age == 10:
	print("We will think about you.")
elif age > 10 and age <=60:
	print("You can drive.")
else:
	print("You are too old to drive.")
	