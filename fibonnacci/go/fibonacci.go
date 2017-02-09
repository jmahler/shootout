
/*
 * Calculate Fibonacci sequence using a function closure.
 *
 * https://tour.golang.org/moretypes/26
 */

package main

import (
	"os"
	"fmt"
	"strconv"
)

// A function that each time it is called
// returns the next Fibonacci number.
func fibonacci_step() func() int {
	a := 0
	b := 1

	return func() int {
		at := a
		// shift and calculate
		a = b
		b = at + b

		return at
	}
}

// Calculate the nth Fibonacci number.
func fibonacci(n int) int {
	fn := fibonacci_step()

	for i := 0; i < n; i++ {
		fn()
	}

	return fn()
}

func main() {
	if len(os.Args) != 2 {
		fmt.Printf("%v <n>\n", os.Args[0])
		os.Exit(2)
	}
	n, _ := strconv.Atoi(os.Args[1])
	fmt.Println(fibonacci(n))
}
