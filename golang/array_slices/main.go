package main

import "fmt"

func main() {
	arr := [5]int{1, 2, 3, 4, 5}
	fmt.Println(arr)

	name := [3]string{
		"okay",
		"shyam",
		"ram",
	}
	fmt.Println(name)

	for i := range len(name) {
		fmt.Print(name[i])
		fmt.Print(" ")
	}
	fmt.Println()

}
