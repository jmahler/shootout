#!/usr/bin/python3

import sys

if 3 != len(sys.argv):
    print("usage: " + sys.argv[0] + " <start> <n>", file=sys.stderr)
    sys.exit(1)

num = int(sys.argv[1])
max = int(sys.argv[2])

count = 0
while (count < max):

    found = 1
    for i in list(range(2, num)):
        if (0 == (num % i)):
            found = 0
            break

    if (found):
        print(num)
        count += 1

    num += 1
