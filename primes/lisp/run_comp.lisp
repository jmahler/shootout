#!/usr/bin/sbcl --script

(load "primes.fasl")

(if (not (= 3 (length *posix-argv*)))
  (progn
	(format *error-output* "usage, ~a <start> <n>~%" (first *posix-argv*))
	(quit)))

(defvar start (parse-integer (second *posix-argv*)))
(defvar n (parse-integer (third *posix-argv*)))

(defvar ps (primes start n))

; print each result on its own line
(mapc (lambda (p) (format t "~a~%" p)) ps)
