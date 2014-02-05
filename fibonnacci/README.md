
NAME
----

fibonacci/

DESCRIPTION
-----------

These programs calculate the Fibonacci sequence starting
from zero.

    0, 1, 1, 2, 3, 5, 8, ...

Except for the first value it is the sum of the two previous values.

RESULTS
-------

The C version is the fastest and the Lisp version is the
slowest.  The Perl version is nearly as fast as the C
version.  There is no perceptible decrease in speed for
values up to 1000 and greater.

    ~/shootout/fibonnacci/lisp$ time ./run_comp.lisp 
    
    4660046610375530309 
    real	0m0.005s
    user	0m0.004s
    sys	0m0.000s
    ~/shootout/fibonnacci/lisp$ 

    ~/shootout/fibonnacci/c$ time ./fibonacci 91
    4660046610375530309
    
    real	0m0.001s
    user	0m0.000s
    sys	0m0.000s
    ~/shootout/fibonnacci/c$
    
    ~/shootout/fibonnacci/perl5$ time ./fibonacci.pl 91
    
    4660046610375530309 
    real	0m0.002s
    user	0m0.000s
    sys	0m0.000s
    ~/shootout/fibonnacci/perl5$ 

The C version is limited by the maximum size of a unsigned long.
The Lisp version has no such restriction and handles these large
numbers with no significant decrease in speed.
The Perl version also handles large numbers correctly.

    ~/shootout/fibonnacci/c$ ./fibonacci 93
    -6246583658587674878
    ~/shootout/fibonnacci/c$
    
    ~/shootout/fibonnacci/lisp$ ./run_comp.lisp 
    12200160415121876738
    ~/shootout/fibonnacci/lisp$ 

    ~/shootout/fibonnacci/perl5$ ./fibonacci.pl 93
    12200160415121876738
    ~/shootout/fibonnacci/perl5$ 

