package main

import (
	"fmt"
	"github.com/pborman/getopt/v2"
)

var (
	key string
	flag bool
)

func init() {
	getopt.Flag(&flag, 'f', "flag")
	getopt.Flag(&key, 'k', "key")
}

func main() {
	getopt.Parse()

	fmt.Printf("flag = %v\n", flag)
	fmt.Printf(" key = '%v'\n", key)
}
