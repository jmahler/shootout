#!/usr/bin/env python3

import sys

def avg(*xs):
    n = len(xs)
    if n == 0:  # avoid div by 0
        return 0

    return sum(xs) / n

def str_to_int(*xs):
    return [int(x) for x in xs]

def main():
    argc = len(sys.argv)

    try:
        print(avg(*str_to_int(*sys.argv[1:])))
    except Exception as e:
        print(e, file=sys.stderr)
        print("usage: {0} 1 2 3 [...]".format(sys.argv[0]), file=sys.stderr)
        sys.exit(1)

if __name__ == '__main__':
    main()
