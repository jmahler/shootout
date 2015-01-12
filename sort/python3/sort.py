#!/usr/bin/python3

import sys

lines = sys.stdin.readlines()

sorted_lines = sorted(lines)

sys.stdout.writelines(sorted_lines)
