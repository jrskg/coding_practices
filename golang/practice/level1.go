package main

import (
	"errors"
	"fmt"
)

type BankAccount struct {
	AccountHolderName string
	AccountNumber     int
	Balance           float64
}

func (b *BankAccount) Withdraw(amount float64) (bool, error) {
	if amount < 1 {
		return false, errors.New("invalid amount")
	} else if amount > b.Balance {
		return false, errors.New("insufficient balance")
	}

	b.Balance -= amount
	return true, nil
}

func (b *BankAccount) Deposit(amount float64) (bool, error) {
	if amount < 1 {
		return false, errors.New("invalid amount")
	}

	b.Balance += amount
	return true, nil
}

func (b BankAccount) CheckBalance() {
	PrintMessageForOutPut("Your balance is :", b.Balance)
}

func BankSystem() {
	accounts := make(map[int]BankAccount)

	var accNumber int
	var amount float64

	choice := 0

	flag := true
	for flag {
		fmt.Println("1. Create Account")
		fmt.Println("2. Deposit")
		fmt.Println("3. Withdraw")
		fmt.Println("4. Check Balance")
		fmt.Println("5. Exit")
		fmt.Print(">>> ")
		fmt.Scanln(&choice)

		switch choice {
		case 1:
			PrintMessageForInput("Enter account holder name.")
			accHolderName := TakeInputStr()
			PrintMessageForInput("Enter account number.")
			fmt.Scanln(&accNumber)
			PrintMessageForInput("Enter initial balance.")
			fmt.Scanln(&amount)
			accounts[accNumber] = BankAccount{
				AccountHolderName: accHolderName,
				AccountNumber:     accNumber,
				Balance:           amount,
			}
			PrintMessageForOutPut("Your account has been created successfully")
		case 2:
			PrintMessageForInput("Enter account number.")
			fmt.Scanln(&accNumber)
			currentAccount, ok := accounts[accNumber]
			if !ok {
				PrintMessageForOutPut("Error !! Account not found")
				break
			}
			PrintMessageForInput("Enter amount to deposit.")
			fmt.Scanln(&amount)
			_, err := currentAccount.Deposit(amount)
			if err != nil {
				PrintMessageForOutPut(err)
				break
			}
			accounts[accNumber] = currentAccount
			PrintMessageForOutPut(amount, "deposited successfully")
		case 3:
			PrintMessageForInput("Enter account number.")
			fmt.Scanln(&accNumber)
			currentAccount, ok := accounts[accNumber]
			if !ok {
				PrintMessageForOutPut("Error !! Account not found")
				break
			}
			PrintMessageForInput("Enter amount to withdraw")
			fmt.Scanln(&amount)
			_, err := currentAccount.Withdraw(amount)
			if err != nil {
				PrintMessageForOutPut(err)
				break
			}
			accounts[accNumber] = currentAccount
			PrintMessageForOutPut(amount, "withdrawn successfully")
		case 4:
			PrintMessageForInput("Enter account number.")
			fmt.Scanln(&accNumber)
			currentAccount, ok := accounts[accNumber]
			if ok {
				currentAccount.CheckBalance()
			} else {
				PrintMessageForOutPut("Error !! Account not found")
			}
		case 5:
			PrintMessageForOutPut("Thanks for using")
			flag = false
		default:
			PrintMessageForOutPut("Invalid command")
		}
	}
}
