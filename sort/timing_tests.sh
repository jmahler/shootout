#!/bin/bash

set -v
time cat services | ./c/insertion_sort > /dev/null
time cat services | ./c/bubble_sort > /dev/null
time cat services | ./perl5/insertion_sort.pl > /dev/null
time cat services | ./perl5/sort.pl > /dev/null
time cat services | ./python2/sort.py > /dev/null
time cat services | ./python3/sort.py > /dev/null
