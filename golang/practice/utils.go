package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func TakeInputStr() string {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	return str
}

func PrintMessageForInput(message string) {
	fmt.Println(message)
	fmt.Print(">>> ")
}

func PrintMessageForOutPut(message ...interface{}) {
	fmt.Println()
	fmt.Println(message...)
	fmt.Println()
}
