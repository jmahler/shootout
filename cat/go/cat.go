package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Fprintln(os.Stderr, "usage: cat <file>")
		os.Exit(1)
	}
	file := os.Args[1]

	fd, err := os.Open(file)
	if err != nil {
		log.Fatal(err)
	}

	rd := bufio.NewReader(fd)

	_, err = io.Copy(os.Stdout, rd)
	if err != nil {
		log.Fatal(err)
	}
}
