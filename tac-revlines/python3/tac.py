#!/usr/bin/env python3

import fileinput

if __name__ == '__main__':
    lines = []

    with fileinput.input() as infd:
        for line in infd:
            lines.append(line)

    # print lines in reverse order
    for line in lines[::-1]:
        print(line, end='')
