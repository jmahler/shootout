#!/bin/sh

# cat <somefile> | ./count-char.sh

./count-char | sort -g -k2 | tail -n 10
