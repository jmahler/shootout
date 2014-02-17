#!/usr/bin/python2

import sys

if 2 != len(sys.argv):
    sys.stderr.write("usage: " + sys.argv[0] + " <n>\n")
    sys.exit(1)

n = int(sys.argv[1])

def fibonacci(n):
    if (0 == n):
        return 0
    elif (n >= 1 and n <= 2):
        return 1

    n -= 2

    s = 0  # sum
    n1 = 1
    n2 = 1
    while (0 != n):
        s = n1 + n2
        n1 = n2
        n2 = s

        n -= 1

    return s

n = fibonacci(n)

print(n)
