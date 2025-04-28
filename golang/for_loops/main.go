package main

import "fmt"

// for -> only construct in go for looping, we can use it in multiple ways (like while, do while, etc.)
func main() {
	// while loop
	i := 1
	for i <= 10 {
		fmt.Print(i)
		fmt.Print(" ")
		i++
	}
	fmt.Println()

	//infinite loop
	k := 1
	for {
		fmt.Print(k)
		fmt.Print(" ")
		k++
		if k > 10 {
			break
		}
	}
	fmt.Println()

	// for loop with range
	for i := 1; i <= 10; i++ {
		if i == 5 {
			continue
		}
		fmt.Print(i)
		fmt.Print(" ")
	}
	fmt.Println()

	//range
	for i := range 11 {
		fmt.Print(i)
		fmt.Print(" ")
	}
	fmt.Println()
}
