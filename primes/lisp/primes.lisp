#!/usr/bin/sbcl --script

(defun is_prime (num &optional (test 2))
  "test whether a number is a prime or not"
  (if (>= test num)
	t
	(if (= 0 (mod num test))
	  nil
	  (is_prime num (+ test 1)))))

(defun primes (&optional (num 2) (count 200))
  "find a certain number of primes"
  (if (= 0 count)
	nil
	(if (is_prime num)
	  (cons num (primes (+ num 1) (- count 1)))
	  (primes (+ num 1) count))))

(print (primes 2 200))
