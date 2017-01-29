package main

import "os"
import "fmt"

func main() {
	len_Args := len(os.Args)
	fmt.Printf("%v arguments", len_Args)

	for i := 0; i < len_Args; i++ {
		fmt.Printf("%v: '%v'\n", i, os.Args[i])
	}
}
