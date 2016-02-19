#!/bin/sh

# cat /etc/services | ./count-char.sh

fold -w1 | sort | uniq -c | sort -g -k1 | tail -n 10
