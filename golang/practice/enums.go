package main

import "fmt"

type OrderStatus int

const (
	Pending OrderStatus = iota
	Processing
	Shipped
	Delivered
	Cancelled
)

func ReturnStatus() OrderStatus {
	return Cancelled
}

func EmumDriver() {
	if ReturnStatus() == Processing {
		fmt.Println("Yes its Processing")
	}
}
