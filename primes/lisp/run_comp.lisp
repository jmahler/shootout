#!/usr/bin/sbcl --script

(load "primes.fasl")

(print (primes 2 200))
