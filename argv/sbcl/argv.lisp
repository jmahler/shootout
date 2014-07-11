#!/usr/bin/sbcl --script

(format t "~D arguments~%" (length *posix-argv*))

(defun print-argv (argv &optional (n 0))
  (if argv
    (progn
      (format t "~D '~a'~%" n (car argv))
      (print-argv (cdr argv) (+ n 1)))))

(print-argv *posix-argv*)
