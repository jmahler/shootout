
NAME
----

shootout - Computer language shootout.

DESCRIPTION
-----------

This is a collection of programming examples solved in various
languages.  It is useful for comparing speed and code size as
well as the more subjective metrics such as understandability.

It was inspired by the now defunct "Great Computer Language Shootout".

The current languages used are: C, Perl, Python and Lisp

INDEX
-----

  primes/ - Calculate the first 200 prime numbers.

  missing_numbers/ - Find missing number among two files.

  revbits/ - Reverse bits of a binary number.

  fibonacci/ - Find nth Fibonacci number.

  flock/ - File locking.

METRICS
-------

There are two main metrics which can be used to gauge a
program: speed and code size.

The `time` command can be used to see how fast a program is.

    primes/perl5$ time ./primes.pl
    ...
    real    0m0.019s
    user    0m0.016s
    sys     0m0.000s

    primes/python$ time ./primes.py
    ...
    real    0m0.028s
    user    0m0.024s
    sys     0m0.000s

    primes/lisp$ time ./primes.lisp
    ...
    real    0m0.016s
    user    0m0.012s
    sys     0m0.004s

    primes/c$ time ./primes
    ...
    real    0m0.002s
    user    0m0.000s
    sys     0m0.000s

In this case Perl was slightly faster than Python.
Lisp was slightly faster the Perl and Python.
And C was an order of magnitude faster than all of the others.

To measure the code size of a program the `wc` command can be used.

    primes$ wc -l perl5/primes.pl 
    23 perl5/primes.pl

    primes$ wc -l python/primes.py
    19 python/primes.py

    primes$ wc -l lisp/primes.lisp
    19 lisp/primes.lisp

    primes$ wc -l c/primes.c
    31 c/primes.c

Here C has the largest code size and Python and Lisp the smallest.

COPYRIGHT
---------

Copyright &copy; 2014, Jeremiah Mahler.  All Rights Reserved.<br>
This project is free software and released under
the [GNU General Public License][gpl].

 [gpl]: http://www.gnu.org/licenses/gpl.html

