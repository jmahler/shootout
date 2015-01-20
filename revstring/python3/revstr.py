#!/usr/bin/python3

import sys

argc = len(sys.argv)

if argc != 2:
    print("usage: %s <str>" % (sys.argv[0]))
    sys.exit(1)

print(sys.argv[1][::-1])
