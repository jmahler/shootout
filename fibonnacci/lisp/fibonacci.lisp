(defun fib (n &optional (n1 0) (n2 1) (sum 1))
  "Find nth Fibonacci number (sum of previous two numbers in sequence)."
  (if (<= n 0)
	n1
	(fib (- n 1) n2 sum (+ n2 sum))))
