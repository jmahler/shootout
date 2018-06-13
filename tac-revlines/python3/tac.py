#!/usr/bin/env python3

import sys

if __name__ == '__main__':
    lines = []

    infd = sys.stdin
    if len(sys.argv) > 1:
        infd = open(sys.argv[1])

    for line in infd:
        lines.append(line)

    # print lines in reverse order
    for line in lines[::-1]:
        print(line, end='')
