package main

import (
	"fmt"
	"github.com/pborman/getopt/v2"
	"os"
)

func main() {

	var (
		flag bool
		key string
		help bool
	)

	getopt.Flag(&help, 'h', "help")
	getopt.Flag(&flag, 'f', "flag")
	getopt.Flag(&key, 'k', "key")
	getopt.Parse()

	if help {
		getopt.PrintUsage(os.Stdout)
		os.Exit(1)
	}

	fmt.Printf("flag = %t\n", flag)
	fmt.Printf(" key = '%v'\n", key)
}
