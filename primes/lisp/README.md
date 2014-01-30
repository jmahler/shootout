
NAME
----

lisp/primes - Calculate first n prime numbers using Lisp (SBCL).

DESCRIPTION
-----------

This example calculates the first n prime numbers using Lisp.
It was designed to use [Steel Bank Common Lisp][sbcl].

  [sbcl]: http://www.sbcl.org

The functions are defined in 'primes.lisp'.  Using a Lisp
interpreter these functions can be loaded and used.

    $ sbcl
    * (load "primes.lisp")
    * (primes 2 200)  ; first 200 primes starting from 2
    * ...
    * (quit)

The code can interpreted or compiled.
The 'compile.lisp' script shows how to compile the code.
The 'run_comp.lisp' and 'run_intr.lisp' scripts will run
the compiled version or the interpreted version respectively.
The compiled version is faster as expected.

    $ time ./run_intr.lisp
    ...
    real    0m0.018s
    user    0m0.016s
    sys     0m0.000s

    $ time ./run_comp.lisp
    ...
    real    0m0.009s
    user    0m0.004s
    sys     0m0.004s

