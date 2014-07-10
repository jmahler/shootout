#!/usr/bin/python3

import sys

argc = len(sys.argv)

print(argc, " arguments")

for i in range(0, argc):
    print("%d: '%s'" % (i, sys.argv[i]))
