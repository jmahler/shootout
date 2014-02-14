#!/usr/bin/python

import fcntl
import sys

if (len(sys.argv) != 2):
    sys.stderr.write('usage: ' + sys.argv[0] + ' <file>\n')
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

sys.exit(0)
