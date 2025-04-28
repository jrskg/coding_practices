package main

import (
	"fmt"
	"sort"
)

func countUnique(nums []int) int {
	count := 0
	m := make(map[int]bool)

	for _, num := range nums {
		if !m[num] {
			count++
			m[num] = true
		}
	}

	return count
}

func elementFrequency(nums []int) map[int]int {
	m := make(map[int]int)
	for _, num := range nums {
		m[num]++
	}

	return m
}

func groupWordByLength(words []string) map[int][]string {
	m := make(map[int][]string)

	for _, word := range words {
		m[len(word)] = append(m[len(word)], word)
	}

	return m
}

func filterSlice(strs []string) []string {
	m := make(map[string]int)
	ans := []string{}

	for _, str := range strs {
		m[str]++
	}

	for k, v := range m {
		if v == 1 {
			ans = append(ans, k)
		}
	}

	return ans
}

type Pair struct {
	Key   int
	Value int
}

func kMostFrequentElement(nums []int, k int) []int {
	if k > len(nums) {
		fmt.Println("Invalid k")
		return nums
	}
	ans := []int{}
	m := make(map[int]int)
	for _, num := range nums {
		m[num]++
	}
	pairs := make([]Pair, 0, len(m))

	for k, v := range m {
		pairs = append(pairs, Pair{Key: k, Value: v})
	}

	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].Value > pairs[j].Value
	})

	for i := range k {
		ans = append(ans, pairs[i].Key)
	}

	return ans
}

func firstNonRepeatingString(strs []string) string {
	m := make(map[string]int)
	var ans string
	for _, str := range strs {
		m[str]++
	}
	for _, str := range strs {
		if m[str] == 1 {
			ans = str
			break
		}
	}
	return ans
}

func commonElementInTwoSlice(s1 []int, s2 []int) []int {
	ans := []int{}
	m := make(map[int]bool)

	for _, num := range s1 {
		m[num] = true
	}
	for _, num := range s2 {
		m[num] = !m[num]
	}

	for k, v := range m {
		if !v {
			ans = append(ans, k)
		}
	}
	return ans
}

func sortStr(str string) string {
	arr := [26]bool{}
	var baseVal = 97
	var ans string
	for _, ch := range str {
		arr[ch-rune(baseVal)] = true
	}

	for i, el := range arr {
		if el {
			ans = ans + string(rune(baseVal+i))
		}
	}
	return ans
}

func anagramGroup(strs []string) map[string][]string {
	m := make(map[string][]string)

	for _, str := range strs {
		var sorted = sortStr(str)
		m[sorted] = append(m[sorted], str)
	}

	return m
}

type Score struct {
	User  string
	Score int
}

func leaderboard(data []Score) []Score {
	m := make(map[string]int)
	ans := []Score{}
	for _, el := range data {
		if m[el.User] < el.Score {
			m[el.User] = el.Score
		}
	}

	for k, v := range m {
		ans = append(ans, Score{User: k, Score: v})
	}

	sort.Slice(ans, func(i, j int) bool {
		return ans[i].Score > ans[j].Score
	})

	return ans
}

func flatten(m map[string][]int) []int {
	m1 := make(map[int]bool)
	ans := []int{}

	for _, v := range m {
		for _, num := range v {
			m1[num] = true
		}
	}

	for k, _ := range m1 {
		ans = append(ans, k)
	}

	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	return ans
}
func main() {
	// count := countUnique([]int{1, 2, 2, 3, 4, 1})
	// fmt.Println(count)

	// freqMap := elementFrequency([]int{1, 2, 2, 3, 4, 1})
	// fmt.Println(freqMap)

	// wordGroup := groupWordByLength([]string{"go", "java", "js", "node", "suraj"})
	// fmt.Println(wordGroup)

	// filtered := filterSlice([]string{"ok", "ok", "ob"})
	// fmt.Println(filtered)

	// mostFrequent := kMostFrequentElement([]int{1, 1, 1, 1, 4, 4, 4, 5, 5, 5, 6, 6, 8, 9, 0}, 4)
	// fmt.Println(mostFrequent)

	// firstNonRepeating := firstNonRepeatingString([]string{"ok", "ok", "r", "s", "o", "o"})
	// fmt.Println(firstNonRepeating)

	// commonElement := commonElementInTwoSlice([]int{1, 2, 3, 4}, []int{3, 4, 5, 6})
	// fmt.Println(commonElement)

	// anagrams := anagramGroup([]string{"bat", "tab", "listen", "silent"})
	// fmt.Println(anagrams)

	// leaderboardAns := leaderboard([]Score{
	// 	{User: "Alice", Score: 50},
	// 	{User: "Bob", Score: 70},
	// 	{User: "Alice", Score: 90},
	// 	{User: "Charlie", Score: 60},
	// 	{User: "Bob", Score: 65},
	// })
	// fmt.Println(leaderboardAns)

	flattenAns := flatten(map[string][]int{
		"ok":  {6, 8, 2},
		"k1":  {1, 8, 4},
		"ok1": {9, 7, 6},
	})

	fmt.Println(flattenAns)
}
