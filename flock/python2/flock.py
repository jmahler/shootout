#!/usr/bin/python2

from __future__ import print_function
import fcntl
import sys

if (len(sys.argv) != 2):
    print('usage: ' + sys.argv[0] + ' <file>', file=sys.stderr)
    sys.exit(1)

fd = open(sys.argv[1], 'w+')

sys.stdout.write('acquiring lock...')
sys.stdout.flush()
fcntl.flock(fd.fileno(), fcntl.LOCK_EX)
sys.stdout.write('done\n')

line = raw_input('Enter data: ')

fd.write(line)

sys.stdout.write('releasing lock...')
fcntl.flock(fd.fileno(), fcntl.LOCK_UN)
sys.stdout.write('done\n')

fd.close()
