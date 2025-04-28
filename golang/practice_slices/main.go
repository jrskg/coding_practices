package main

import (
	"fmt"
)

func createAndPrint() {
	var slc = []int{1, 2, 3, 4, 5}
	for i := range len(slc) {
		fmt.Print(slc[i])
		fmt.Print(" ")
	}
	fmt.Println()
}

func appendInSlice() {
	var slc = []string{}
	slc = append(slc, "Go")
	slc = append(slc, "is")
	slc = append(slc, "awesome")

	for i := range len(slc) {
		fmt.Print(slc[i])
		fmt.Print(" ")
	}
	fmt.Println()
}

func sliceFromArray() {
	var arr = [5]int{10, 20, 30, 40, 50}
	var slc = arr[1:4]

	// for i := 1; i < len(arr)-1; i++ {
	// 	slc = append(slc, arr[i])
	// }

	fmt.Println(slc)
}

func sumOfSlice(nums []int) int {
	var sum = 0
	for i := range len(nums) {
		sum += nums[i]
	}
	return sum
}

func findMaximum(nums []int) int {
	var maxi = nums[0]
	for i := 1; i < len(nums); i++ {
		if maxi < nums[i] {
			maxi = nums[i]
		}
	}
	return maxi
}

func evensFromSlice(nums []int) []int {
	var evenSlice = []int{}
	for i := range len(nums) {
		if nums[i]%2 == 0 {
			evenSlice = append(evenSlice, nums[i])
		}
	}
	return evenSlice
}

func reverseSlice(nums []int) {
	i := 0
	j := len(nums) - 1
	var temp int
	for i < j {
		temp = nums[i]
		nums[i] = nums[j]
		nums[j] = temp
		i++
		j--
	}
}

func customRemove(nums []int, index int) []int {
	if index < 0 || index >= len(nums) {
		fmt.Println("Invalid index")
		return nums
	}

	for nextIndex := index + 1; nextIndex < len(nums); nextIndex++ {
		nums[index] = nums[nextIndex]
		index++
	}
	return nums[:len(nums)-1]
}

func uniqueElement(strs []string) []string {
	var maps = make(map[string]bool)
	var ans = []string{}

	for i := range len(strs) {
		_, ok := maps[strs[i]]
		if !ok {
			ans = append(ans, strs[i])
			maps[strs[i]] = true
		}
	}
	return ans
}

func mergeAndSort(s1 []int, s2 []int) []int {
	var merged = append(s1, s2...)
	for i := 1; i < len(merged); i++ {
		key := merged[i]
		j := i - 1
		for j >= 0 && merged[j] > key {
			merged[j+1] = merged[j]
			j--
		}
		merged[j+1] = key
	}
	return merged
}

func main() {
	// createAndPrint()
	// appendInSlice()
	// sliceFromArray()
	// var ans = sumOfSlice([]int{1, 2, 3, 4})
	// fmt.Println(ans)
	// var ans = findMaximum([]int{1, 2, 3, 4})
	// fmt.Println(ans)
	// var ans = evensFromSlice([]int{1, 2, 3, 4})
	// fmt.Println(ans)

	// var slc = []int{1, 2, 3, 4, 5}
	// reverseSlice(slc)
	// fmt.Println(slc)

	// var slc1 = []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	// fmt.Println(slc1)
	// customRemove(slc1, 4)
	// slc1 = customRemove(slc1, 7)
	// fmt.Println(slc1)

	// var strs = []string{"go", "go", "lang"}
	// var ans = uniqueElement(strs)
	// fmt.Println(ans)

	var s1 = []int{3, 1, 2, 5}
	var s2 = []int{3, 7, 8, 6}
	var s3 = mergeAndSort(s1, s2)
	fmt.Println(s3)
}
