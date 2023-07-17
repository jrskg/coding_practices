import random
import time

def compare(you , comp):
	if you == comp:
		return 0
	elif you == 0 and comp == 1:
		return 1
	elif you == 1 and comp == 0:
		return -1
	elif you == 0 and comp == 2:
		return -1
	elif you == 2 and comp == 0:
		return 1
	elif you == 1 and comp == 2:
		return 1
	elif you == 2 and comp == 1:
		return -1

name = input("Please enter your name.\n")
print("Hello",name,"\n\t\tWelcome to 'Snake Water and Gun' game")

start = input("\nPress c to continue\n")
if start.capitalize() == 'C':
	try:
		Your_score = 0
		CPU_score = 0
		list= ["Snake", "Water", "Gun"]
		i = 1
		while(i !=4):
			print("Round no.",i,"\nYours turn....")
			player = int(input("Press 0 for Snake, 1 for Water and 2 for Gun\n"))
			print("\nYou have choosen",list[player],"\n")
	
			print("CPU turns....")
			time.sleep(1)
			computer = random.randint(0, 2)
			print("CPU has choosen",list[computer],"\n")
			result = compare(player, computer)
			if result == 0:
				print("Its a draw !\n")
			elif result == 1:
				print("You got it.\n")
				Your_score += 1
			elif result == -1:
				print("CPU got it.\n")
				CPU_score += 1
			i =  i + 1
		if Your_score == CPU_score:
			print("Match draw !!\n")
		elif Your_score > CPU_score:
			print("Congrats",name,"You win.\n")
		else:
			print("Sorry",name,"You lose\n")
		print("Your score:",Your_score)
		print("CPU score:",CPU_score)
		print("\nThanks for playing..")
	except Exception:
		print("Something went wrong.Please try again...")
	
else:
	print("Something went wrong. please try again...")
