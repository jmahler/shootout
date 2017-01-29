package main

import (
	"fmt"
	"os"
	"strconv"
)

func parse_Args() (int, int) {

	if 3 != len(os.Args) {
		fmt.Printf("usage: %v <start> <n>\n", os.Args[0])
		os.Exit(1)
	}

	num, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println(err)
		os.Exit(2)
	}

	max, err := strconv.Atoi(os.Args[2])
	if err != nil {
		fmt.Println(err)
		os.Exit(3)
	}

	return num, max
}

func main() {

	num, max := parse_Args()

	count := 0
	for count < max {
		found := true

		// if anything else divides evenly, it is not a prime
		for i := 2; i < num; i++ {
			if 0 == (num % i) {
				found = false
				break;
			}
		}

		if found {
			fmt.Printf("%v\n", num)
			count++
		}

		num++
	}
}
