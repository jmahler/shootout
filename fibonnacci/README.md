
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

The C version is slightly faster than the Lisp version.

    ~/shootout/fibonnacci/c$ time ./fibonacci 91
    4660046610375530309
    
    real	0m0.001s
    user	0m0.000s
    sys	0m0.000s
    ~/shootout/fibonnacci/c$
    
    ~/shootout/fibonnacci/lisp$ time ./run_comp.lisp 
    
    4660046610375530309 
    real	0m0.005s
    user	0m0.004s
    sys	0m0.000s
    ~/shootout/fibonnacci/lisp$ 


The C version is limited by the maximum size of a unsigned long.
The Lisp version has no such restriction and handles these large
numbers with no significant decrease in speed.

    ~/shootout/fibonnacci/c$ time ./fibonacci 93
    -6246583658587674878
    
    real	0m0.001s
    user	0m0.000s
    sys	0m0.000s
    ~/shootout/fibonnacci/c$
    
    ~/shootout/fibonnacci/lisp$ time ./run_comp.lisp 
    
    122001604151218767380
    real	0m0.005s
    user	0m0.004s
    sys	0m0.000s
    ~/shootout/fibonnacci/lisp$ 

