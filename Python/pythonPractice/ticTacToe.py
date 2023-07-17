def sum(a, b, c):
	return a+b+c
	
def printBoard(xState, zState):
	one = 'X' if xState[0] else ('0' if zState[0] else 1)
	two = 'X' if xState[1] else ('0' if zState[1] else 2)
	three = 'X' if xState[2] else ('0' if zState[2] else 3)
	four = 'X' if xState[3] else ('0' if zState[3] else 4)
	five = 'X' if xState[4] else ('0' if zState[4] else 5)
	six = 'X' if xState[5] else ('0' if zState[5] else 6)
	seven = 'X' if xState[6] else ('0' if zState[6] else 7)
	eight = 'X' if xState[7] else ('0' if zState[7] else 8)
	nine = 'X' if xState[8] else ('0' if zState[8] else 9)
	print("")
	print(f"{one} | {two} | {three}")
	print("--|---|---")
	print(f"{four} | {five} | {six}")
	print("--|---|---")
	print(f"{seven} | {eight} | {nine}")
	print("")
	
def checkWin(xState, zState):
	wins = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]
	
	for win in wins:
		if(sum(xState[win[0]], xState[win[1]], xState[win[2]]) == 3):
			return 1
		if(sum(zState[win[0]], zState[win[1]], zState[win[2]]) == 3):
			return 0
	return -1

if __name__ == "__main__":
	xState = [0, 0, 0, 0, 0, 0 , 0, 0, 0]
	zState = [0, 0, 0, 0, 0, 0 , 0, 0, 0]
	checkForGameOver = 0
	turn = 1
	print("Welcome to Tic-Tac-Toe")
	while (True):
		printBoard(xState, zState)
		if(turn == 1):
			print("X's turn")
			index = int(input("Enter a number (1-9):  "))
			xState[index-1] = 1
			checkForGameOver += 1
		else:
			print("O's turn")
			index = int(input("Enter a number(1-9) :  "))
			zState[index-1] = 1
			checkForGameOver += 1
		turn = 1-turn
		cwin = checkWin(xState, zState)
		if(cwin == 1):
			print("Player X wins.")
			break
		elif(cwin == 0):
			print("Player 0 wins")
			break
		if(checkForGameOver == 9):
			print("Game Over !!!")
			break

printBoard(xState, zState)