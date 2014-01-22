#!/usr/bin/python

#
# revbits.c
#
# Given a file of 16-bit numbers, read them in, reverse the bits,
# and output them to another file.
#
#   $ ./revbits.py ../input.bin output.bin
#
# To check the results do a checksum of a known good file.
#
#   $ md5sum output.bin ../output.bin.ok
#   f1b35239925edf5a0cf9a3ccd7e388b6  output.bin
#   f1b35239925edf5a0cf9a3ccd7e388b6  ../output.bin.ok
#
# hexedit is a good program for manually inspecting the values.
#

import sys
import struct

word_sz = 2  # word size in bytes (16-bits -> 2 bytes)
bits = word_sz*8

def revbits(n):
    "reverse the bits"
    i = 0
    nr = 0
    while (1):
        nr = nr | (n & 1)

        i = i + 1
        if (i >= bits):
            break

        nr = nr << 1
        n = n >> 1

    return nr

if (len(sys.argv) != 3):
    sys.stderr.write('usage: ' + sys.argv[0] + ' <in file> <out file>\n')
    sys.exit(1)

infd = open(sys.argv[1], 'rb')
outfd = open(sys.argv[2], 'wb')

while (1):
    s = infd.read(word_sz)
    if (s == ''):
        break
    n = struct.unpack("H", s)[0]
    nr = revbits(n)
    s = struct.pack("H", nr)
    outfd.write(s)

infd.close()
outfd.close()
