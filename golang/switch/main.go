package main

import (
	"fmt"
	"time"
)

func main() {
	name := "John Doe"

	switch name {
	case "John Doe":
		fmt.Println("Hello John Doe")
	case "Jane Doe":
		fmt.Println("Hello Jane Doe")
	default:
		fmt.Println("Hello Stranger")
	}

	switch time.Now().Weekday() {
	case time.Saturday, time.Sunday:
		fmt.Println("It's the weekend!")
	default:
		fmt.Println("It's a weekday.")
	}

	getType := func(i interface{}) {
		switch i.(type) {
		case int:
			fmt.Println("It's an int")
		case string:
			fmt.Println("It's a string")
		case bool:
			fmt.Println("It's a bool")
		case float64:
			fmt.Println("It's a float64")
		case []int:
			fmt.Println("It's a slice of int")
		default:
			fmt.Println("Unknown type")
		}
	}

	getType(false)
}
