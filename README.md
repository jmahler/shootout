
NAME
----

shootout - Computer language shootout.

DESCRIPTION
-----------

Programming problems solved in several different languages.
Useful for comparing metrics such as speed and code size.

Inspired by the now defunct "Great Computer Language Shootout".

INDEX
-----

  primes/ - display the first 200 prime numbers

  missing_numbers/ - Find missing number among two files.

  revbits/ - Reverse bits of a binary number.

METRICS
-------

There are two main metrics which can be used to gauge a
program: speed and code size.

To measure how fast a program is the `time` command can be used.

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

    primes/c$ time ./primes
    ...
    real    0m0.002s
    user    0m0.000s
    sys     0m0.000s

In this case Perl was slightly faster than Python.
And C was an order of magnitude faster than both of those.

To measure the code size of a program the `wc` command can be used.

    primes$ wc -l perl5/primes.pl 
    23 perl5/primes.pl

    primes$ wc -l python/primes.py
    19 python/primes.py

    primes$ wc -l c/primes.c
    31 c/primes.c

Here C has the largest code size and Python the smallest.
However for this small program they are all quite close.

COPYRIGHT
---------

Copyright &copy; 2014, Jeremiah Mahler.  All Rights Reserved.<br>
This project is free software and released under
the [GNU General Public License][gpl].

 [gpl]: http://www.gnu.org/licenses/gpl.html

