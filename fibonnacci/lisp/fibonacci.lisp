(defun fib (n)
  "Fibonacci number, sum of previous two numbers in sequence"
  (if (<= n 2)
	(if (= n 0)
	  0
	  1)
	(+ (fib (- n 1))
	   (fib (- n 2)))))
