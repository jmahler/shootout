#!/usr/bin/python2

from __future__ import print_function
import sys

if (len(sys.argv) != 3):
    print('usage: ' + sys.argv[0] + ' <file1> <file2>', file=sys.stderr)
    sys.exit(1)

file1 = open(sys.argv[1], 'r')
file2 = open(sys.argv[2], 'r')

sum1 = 0;
for line in file1:
    sum1 += int(line)

sum2 = 0;
for line in file2:
    sum2 += int(line)

if (sum2 > sum1):
    n = sum2 - sum1
else:
    n = sum1 - sum2

print(n)

file1.close()
file2.close()
