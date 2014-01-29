#!/usr/bin/sbcl --script

(defun fib (n)
  (if (<= n 1)
	1
	(+ (fib (- n 1))
	   (fib (- n 2)))))
		
(print (fib 30))
