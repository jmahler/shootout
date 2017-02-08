
/*
 * Calculate Fibonacci sequence using a function closure.
 *
 * https://tour.golang.org/moretypes/26
 */

package main

import "fmt"

// fibonacci is a function that returns
// a function that returns an int.
func fibonacci() func() int {
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

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
