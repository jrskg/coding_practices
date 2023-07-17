import time
import random
import string

def getrandomString(num):
    letters = string.ascii_letters
    randomStr = ""
    for i in range(num):
        randomStr = randomStr+random.choice(letters)
    return randomStr

def getEN_DE_Code():
    while(True):
        num = int(input("Enter EN-DE code (2-10) : "))
        if(num > 10 or num < 2):
            print("ERR : Value must be in between (2 - 10)")
            continue
        else:
            return num

def encrypt(message, num):
    words = message.split(" ")
    newWords = []
    for word in words:
        if(len(word) >= 3):
            genWord = getrandomString(num)+word[1:]+word[0]+getrandomString(num)
        else:
            genWord = word[::-1]
        newWords.append(genWord)
    finalMessage = " ".join(newWords)
    print(finalMessage)


def decrypt(message, num):
    words = message.split(" ")
    newWords = []
    for word in words:
        if(len(word) >= 3):
            genWord = word[num:-num]
            genWord = genWord[len(genWord)-1]+genWord[:len(genWord)-1]
        else:
            genWord = word[::-1]
        newWords.append(genWord)
    finalMessage = " ".join(newWords)
    print(finalMessage)

if __name__ == "__main__":
    print("\nWelcome to EN-DE-CRYPTO\n")
    time.sleep(1)
    
    while(True):
        action = input("Press E for Encryption, D for Decryption and Q for Quit : ").lower()
        if(action != "q" and (action == "e" or action == "d")):
            text = input("Enter your message : ")
            en_de_Code = getEN_DE_Code()
            print(en_de_Code)

        match action:
            case "e":
                encrypt(text, en_de_Code)
            case "d":
                decrypt(text, en_de_Code)
            case "q":
                print("Quitting...")
                break
            case _:
                print("Invalid Input!!!")
