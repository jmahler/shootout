
NAME
----

shootout - Computer language shootout.

DESCRIPTION
-----------

This is a collection of programming problems which are each solved in
several different programming languages.  It is useful for comparing
implementation code size, understandability and performance.

It was inspired by the now defunct "Great Computer Language Shootout".

The current languages used are: C, C++, Perl, Python (2 and 3),
Ruby, Haskell, Matlab (Octave), SBCL (Lisp), Bourne shell (sh),
Go, Bourne again shell (bash), Node.js, and Awk.

INDEX
-----

* hello - Hello, World!
* argv - Accessing command line arguments.
* getopt - Parsing options from command line arguments.
* primes - Calculate the first 200 prime numbers.
* missing_numbers - Find missing number among two files.
* revbits - Reverse bits of a binary number.
* revstring - Reverse a string.
* sort - Sort the lines in a file.
* strcomb - Generate all combinations of a "string".
* fibonacci - Find nth Fibonacci number.
* flock - File locking.
* inotify - Watch all the file operations on a file/directory.
* endian - Detect endianess of current system.
* backtrace - Generate a function call backtrace.
* binary_tree - Search of unordered binary trees.
* (www, sockets, web servers)
  * web_server - A simple "Hello, World!" web server.
  * ssh_cmd - ssh to a host and run a command.
  * echo - Echo client/server.
* count-char - Count the number of characters in a file.
* url-spreadsheet - Generate a spreadsheet with big urls for all OSes.
* rm-dirs - Remove all directories except the n newest.
* template - templates using Mustache, Handlebars, etc

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

AUTHOR
------

Jeremiah Mahler <jmmahler@gmail.com><br>
<http://github.com/jmahler>

COPYRIGHT
---------

Copyright &copy; 2015, Jeremiah Mahler.  All Rights Reserved.<br>
This project is free software and released under
the [GNU General Public License][gpl].

 [gpl]: http://www.gnu.org/licenses/gpl.html

