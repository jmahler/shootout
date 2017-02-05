package main

import (
	"fmt"
	"github.com/pborman/getopt/v2"
	"os"
)

func main() {

	var num, max int
	var help bool

	getopt.Flag(&help, 'h', "help")
	getopt.Flag(&num, 'n', "num")
	getopt.Flag(&max, 'm', "max")
	getopt.Parse()

	if help {
		getopt.PrintUsage(os.Stdout)
		os.Exit(1)
	}

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
