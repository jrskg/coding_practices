package main

import "fmt"

func main() {
	var name string = "John Doe" // explicit type declaration
	var name2 = "Okay Gupta"     // type inference
	name3 := "Suraj Gupta"       // short-hand declaration of variable

	var age int = 23

	var isAdult bool = true

	fmt.Println(name)
	fmt.Println(name2)
	fmt.Println(name3)
	fmt.Println(age)
	fmt.Println(isAdult)
}
