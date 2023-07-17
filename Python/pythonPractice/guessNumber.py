num = 20
attempt = 1
print("You have only 8 chance to guess the number")

while(attempt <= 8):
	guess = int(input("Guess the number\n"))
	if guess < num:
		print("Higher number please!")
	elif guess > num:
		print("Lower number please!")
	else:
		print("You win..")
		print("You got it in",attempt,"attempt")
		break
	print(8-attempt,"chance left")
	attempt = attempt + 1
	
if (attempt>8):
	print("Game over..")