package main

import (
	"fmt"
	"maps"
)

func createAndAccess() {
	var students = map[string]int{}
	students["Suraj"] = 99
	students["Arbind"] = 98

	fmt.Println(students["Suraj"])
}

func addAndUpdate() {
	var mp = map[string]int{}
	mp["ok"] = 1
	mp["okay"] = 2
	mp["oey"] = 3

	mp["oey"] = 10

	for k, v := range mp {
		fmt.Println(k, " => ", v)
	}
}

func checkKey() {
	var mp = map[string]int{}
	mp["name"] = 2

	_, ok := mp["don't"]
	if ok {
		fmt.Println("Key is present")
	} else {
		fmt.Println("Key is not present")
	}
}

func deleteKey() {
	var mp = map[string]int{}
	mp["key1"] = 1
	mp["key2"] = 1
	mp["key3"] = 1
	mp["key4"] = 1

	delete(mp, "key1")

	fmt.Println(mp)
}

func mapIteration() {
	var mp = map[string]int{}
	mp["key1"] = 1
	mp["key2"] = 1
	mp["key3"] = 1
	mp["key4"] = 1

	for k, v := range mp {
		fmt.Println(k, " => ", v)
	}
}

func wordFrequency(words []string) map[string]int {
	var mp = map[string]int{}
	for _, v := range words {
		mp[v]++
	}
	return mp
}

func invertMap(mp map[string]int) map[int]string {
	var ans = map[int]string{}

	for k, v := range mp {
		ans[v] = k
	}

	return ans
}

func groupStringByLetter(strs []string) map[string][]string {
	var mp = map[string][]string{}

	for _, s := range strs {
		var ch = s[:1]
		_, ok := mp[ch]
		if !ok {
			mp[ch] = []string{}
		}
		mp[ch] = append(mp[ch], s)
	}

	return mp
}

func mergeTwoMaps(m1 map[string]int, m2 map[string]int) map[string]int {
	ans := map[string]int{}
	maps.Copy(ans, m1)

	for k, v := range m2 {
		_, ok := ans[k]
		if ok {
			ans[k] = ans[k] + v
		} else {
			ans[k] = v
		}
	}

	return ans
}

func keyWithHighestValue(mp map[string]int) string {
	var key string
	var value = -1

	for k, v := range mp {
		if v > value {
			key = k
			value = v
		}
	}

	return key
}

func main() {
	// createAndAccess()
	// addAndUpdate()
	// checkKey()
	// deleteKey()
	// mapIteration()

	// var ans = wordFrequency([]string{"go", "go", "lang"})
	// fmt.Println(ans)

	// words := []string{"apple", "banana", "avocado", "blueberry", "apricot"}
	// ans := groupStringByLetter(words)
	// fmt.Println(ans)

	ans := mergeTwoMaps(map[string]int{"a": 1, "b": 4}, map[string]int{"a": 3, "c": 1})
	fmt.Println(ans)
}
