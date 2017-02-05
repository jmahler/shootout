package main

import (
	"fmt"
	"github.com/pborman/getopt/v2"
)

func main() {

	var (
		flag bool
		key string
	)

	getopt.Flag(&flag, 'f', "flag")
	getopt.Flag(&key, 'k', "key")
	getopt.Parse()

	fmt.Printf("flag = %t\n", flag)
	fmt.Printf(" key = '%v'\n", key)
}
