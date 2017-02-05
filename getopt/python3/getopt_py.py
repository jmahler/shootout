#!/usr/bin/python3

# NAME
# 
# getopt_py - show how to get argv options in Python
# 
# DESCRIPTION
# 
# This program shows how to get either a flag option or a key/value pair
# from argv.  The value of the arguments are printed as the result.
# 
#   $ getopt_py -f -k abc
#   flag = 1
#   key = 'abc'
# 
#   $ getopt_py -k abc
#   flag = 0
#   key = 'abc'
# 
# AUTHOR
# 
# Jeremiah Mahler <jmmahler@gmail.com>
# http://github.com/jmahler
# 
# COPYRIGHT
# 
# Copyright (c) 2014, Jeremiah Mahler. All Rights Reserved.
# This project is free software and released under the
# GNU General Public License.
# 

import sys, getopt

options, args = getopt.getopt(sys.argv[1:], "fk:")

key = ""
flag = 0

for opt, val in options:
    if opt == '-k':
        key = val
    elif opt == '-f':
        flag = 1

print("flag = ", flag, sep="")
print(" key = '", key, "'", sep="")
