#!/usr/bin/python2

import sys

argc = len(sys.argv)

print argc, " arguments"

for i in xrange(0, argc):
    print "%d: '%s'" % (i, sys.argv[i])
