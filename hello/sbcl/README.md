
NAME
----

lisp/hello - Hello World in Lisp

DESCRIPTION
-----------

This example prints "Hello, World!" using Lisp.
It was designed to use [Steel Bank Common Lisp][sbcl].

  [sbcl]: http://www.sbcl.org

Running programs from the command line using Lisp is a
bit more complicated than with C or Perl.
To run the interpreted version run:

    $ ./run_intr.lisp
    Hello, World!

To run the compiled version, first compile the program
using the compile.lisp script.

    $ ./compile.lisp

Then run it using the run_comp.lisp script.

    $ ./run_comp.lisp
    Hello, World!

This program can also be run from the Lisp interpreter as usual.

    $ sbcl
    * (load "hello.lisp")
    * (hello)
    Hello, World!
    NIL
    * (quit)

