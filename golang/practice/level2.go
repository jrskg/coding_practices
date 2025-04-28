package main

import (
	"errors"
	"fmt"
)

type Book struct {
	Title           string
	Author          string
	ISBN            int
	AvailableCopies int
}

func (b *Book) Borrow() (bool, error) {
	if b.AvailableCopies == 0 {
		return false, errors.New("book not available")
	}
	b.AvailableCopies -= 1
	return true, nil
}

func (b *Book) Return() (bool, error) {
	b.AvailableCopies += 1
	return true, nil
}

func (b Book) ShowBookDetails() {
	PrintMessageForOutPut(
		"Book Name\t", b.Title, "\n",
		"Author   \t", b.Author, "\n",
		"ISBN     \t", b.ISBN, "\n",
		"Copies   \t", b.AvailableCopies,
	)
}

type Library struct {
	books map[int]*Book
}

func NewLibrary() Library {
	return Library{
		books: make(map[int]*Book),
	}
}

func (l *Library) AddBook(title, author string, isbn, availableCopies int) {
	l.books[isbn] = &Book{
		Title:           title,
		Author:          author,
		ISBN:            isbn,
		AvailableCopies: availableCopies,
	}
}

func (l Library) GetBook(isbn int) (*Book, error) {
	book, ok := l.books[isbn]
	if !ok {
		return nil, errors.New("invalid isbn number")
	}
	return book, nil
}

func (l Library) ShowList(showHeader bool) {
	if len(l.books) == 0 {
		PrintMessageForOutPut("No books available!")
		return
	}
	if showHeader {
		fmt.Println("Available books")
	} else {
		fmt.Println()
	}
	for _, book := range l.books {
		book.ShowBookDetails()
	}
	fmt.Println()
}

func LibrarySystem() {
	myLibrary := NewLibrary()

	isbn := 0
	availableCopies := 0

	choice := 0

	flag := true
	for flag {
		fmt.Println("1. Add Book")
		fmt.Println("2. Borrow Book")
		fmt.Println("3. Return Book")
		fmt.Println("4. Show Book Details")
		fmt.Println("5. Show Available Books")
		fmt.Println("6. Exit")
		fmt.Print(">>> ")
		fmt.Scanln(&choice)

		switch choice {
		case 1:
			PrintMessageForInput("Enter book name")
			bookTitle := TakeInputStr()
			PrintMessageForInput("Enter author name.")
			bookAuthor := TakeInputStr()
			PrintMessageForInput("Enter book's ISBN number.")
			fmt.Scanln(&isbn)
			PrintMessageForInput("Enter available copies.")
			fmt.Scanln(&availableCopies)
			myLibrary.AddBook(bookTitle, bookAuthor, isbn, availableCopies)
			PrintMessageForOutPut("Book has been added successfully")
		case 2:
			PrintMessageForInput("Enter ISBN number.")
			fmt.Scanln(&isbn)
			book, err := myLibrary.GetBook(isbn)
			if err != nil {
				PrintMessageForOutPut(err)
				break
			}
			_, err2 := book.Borrow()
			if err2 != nil {
				PrintMessageForOutPut(err)
				break
			}
			PrintMessageForOutPut(book.Title, "borrowed successfully")
		case 3:
			PrintMessageForInput("Enter ISBN number.")
			fmt.Scanln(&isbn)
			book, err := myLibrary.GetBook(isbn)
			if err != nil {
				PrintMessageForOutPut(err)
				break
			}
			_, err3 := book.Return()
			if err3 != nil {
				PrintMessageForOutPut(err3)
				break
			}
			PrintMessageForOutPut(book.Title, "returned successfully")
		case 4:
			PrintMessageForInput("Enter ISBN number.")
			fmt.Scanln(&isbn)
			book, err := myLibrary.GetBook(isbn)
			if err != nil {
				PrintMessageForOutPut(err)
				break
			}
			book.ShowBookDetails()
		case 5:
			myLibrary.ShowList(true)
		case 6:
			PrintMessageForOutPut("Thanks for using")
			flag = false
		default:
			PrintMessageForOutPut("Invalid command")
		}
	}
}
