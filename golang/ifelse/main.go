package main

func getName() string {
	return "john"
}
func main() {
	var age = 20

	if age >= 18 {
		println("You are an adult.")
	} else {
		println("You are a minor.")
	}

	// Using if-else if-else
	if age < 13 {
		println("You are a child.")
	} else if age < 18 {
		println("You are a teenager.")
	} else if age < 65 {
		println("You are an adult.")
	} else {
		println("You are a senior citizen.")
	}

	if name := getName(); name == "john" {
		println("Hello, John!")
	} else {
		println("Hello, stranger!")
	}
}
