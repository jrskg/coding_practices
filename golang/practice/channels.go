package main

import (
	"fmt"
	"math/rand"
	"time"
)

func Producer(chan1 chan<- int) {
	for range 5 {
		chan1 <- rand.Intn(100)
	}
	close(chan1)
}
func Consumer(chan1 <-chan int, done chan<- bool) {
	defer func() {
		done <- true
	}()
	for num := range chan1 {
		fmt.Println("Processing number", num)
		time.Sleep(time.Second)
	}
}

func Worker(task chan int, result chan int) {
	workTime := rand.Intn(5) + 1
	time.Sleep(time.Duration(workTime) * time.Second)
	result <- workTime
}
func ChannelDriver() {
	// done := make(chan bool)

	// chan1 := make(chan int, 10)
	// go Producer(chan1)
	// go Consumer(chan1, done)

	// <-done

	task := make(chan int)
	result := make(chan int)

	go Worker(task, result)
	timeout := time.After(3 * time.Second)

	select {
	case res := <-result:
		fmt.Println("Task completed in", res, "second")
	case <-timeout:
		fmt.Println("Task timeout error")
	}
}
