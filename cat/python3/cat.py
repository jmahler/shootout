#!/usr/bin/env python3

import sys
import fileinput

if __name__ == '__main__':

    with fileinput.input() as infd:
        for line in infd:
            print(line, end='')
