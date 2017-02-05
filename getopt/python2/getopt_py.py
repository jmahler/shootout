#!/usr/bin/python2

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

import argparse

ap = argparse.ArgumentParser(description='Get command line arguments')
ap.add_argument('-k', dest='key', default="")
ap.add_argument('-f', dest='flag', action='store_true')

args = ap.parse_args()

print "flag = %i" % args.flag
print " key = '%s'" % args.key
