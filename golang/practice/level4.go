package main

import (
	"context"
	"fmt"
	"math/rand"
	"time"
)

func Runner(ctx context.Context, done chan int, id, sleepTime int) {
	fmt.Println("Runner", id, "starting for", sleepTime, "seconds")
	select {
	case <-time.After(time.Duration(sleepTime) * time.Second):
		done <- id
	case <-ctx.Done():
		fmt.Println("Runner", id, "canceled")
		return
	}
}
func RaceRunner() {
	ctx, cancel := context.WithCancel(context.Background())
	defer cancel()
	done := make(chan int)

	for i := 1; i <= 5; i++ {
		randomNum := rand.Intn(5) + 1
		go Runner(ctx, done, i, randomNum)
	}

	completed := <-done
	fmt.Println("Runner", completed, "finished first")
	cancel()

	time.Sleep(time.Second)
}
