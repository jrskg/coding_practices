package main

import (
	"fmt"
	"sync"
)

func sum(r1, r2 int64) int64 {
	ans := int64(0)

	for i := r1; i <= r2; i++ {
		ans += i
	}
	return ans
}
func SumSlice(num int64) int64 {
	totalThread := 5
	chunkSize := num / int64(totalThread)
	resultArray := make([]int64, totalThread)
	var wg sync.WaitGroup

	for i := range totalThread {
		start := (int64(i) * chunkSize) + 1
		end := int64(i+1) * chunkSize
		if i == totalThread-1 {
			end = num
		}
		wg.Add(1)
		go func(index int, start, end int64) {
			fmt.Println("Calculating for", index, "index from", start, "to", end)
			defer wg.Done()
			resultArray[index] = sum(start, end)
		}(i, start, end)
	}

	wg.Wait()
	ans := int64(0)
	for _, val := range resultArray {
		ans += val
	}

	return ans
}

func Fact(num int64) int64 {
	fact := int64(1)
	var i int64
	for i = 1; i <= num; i++ {
		fact *= i
	}
	return fact
}
func CalculateFactSum(r1, r2 int64) int64 {
	sum := Fact(r1)
	prevFact := sum
	for i := r1 + 1; i <= r2; i++ {
		prevFact = prevFact * i
		sum += prevFact * i
	}
	fmt.Println("ok ", sum)
	return sum
}

func FactorialSum(num int64) int64 {
	totalThread := 10
	chunkSize := num / int64(totalThread)
	resultArray := make([]int64, totalThread)
	var wg sync.WaitGroup

	for i := range totalThread {
		start := (int64(i) * chunkSize) + 1
		end := int64(i+1) * chunkSize
		if i == totalThread-1 {
			end = num
		}
		wg.Add(1)
		go func(index int, start, end int64) {
			defer wg.Done()
			fmt.Println("Calculating for", index, "index from", start, "to", end)
			resultArray[index] = CalculateFactSum(start, end)
		}(i, start, end)
	}
	wg.Wait()

	ans := int64(0)
	for _, val := range resultArray {
		ans += val
	}

	return ans
}

func RoutineDriver() {
	// total := SumSlice(100000)
	// fmt.Println(total)
	total := FactorialSum(10)
	fmt.Println(total)
}
