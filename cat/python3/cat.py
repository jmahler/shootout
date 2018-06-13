#!/usr/bin/env python3

import sys

if __name__ == '__main__':

    # read from a file or stdin
    infd = sys.stdin
    if len(sys.argv) > 1:
        infd = open(sys.argv[1])

    for line in infd:
        print(line, end='')
