package main

import "fmt"

func main() {
	const name = " Golang"
	// name = "javascript"

	// var name  = "ok"

	//constant grouping

	const (
		host = "localhost"
		port = 3000
	)
	// port = 9000 // cannot assign to port
	fmt.Println(host, port)

}
