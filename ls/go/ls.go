/*
A simplified ls command written in Go.

It behaves closest to `ls -a` and lists all
entries in a given directory including hidden
ones.

Usage:

ls [path ...]
*/
package main

import (
	"fmt"
	"os"
)

func main() {
	for i := 1; i < len(os.Args); i++ {
		dirs, err := os.ReadDir(os.Args[i])
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			os.Exit(1)
		}
		for _, dir := range dirs {
			fmt.Println(dir.Name())
		}
	}
}
