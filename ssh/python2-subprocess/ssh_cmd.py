#!/usr/bin/python2

from __future__ import print_function
import subprocess
import sys

try:
    host, cmd = sys.argv[1:3]
except:
    print("usage: {} <host> <cmd>".format(sys.argv[0]), file=sys.stderr)
    sys.exit(1)

ssh_cmd = 'ssh {} "{}"'.format(host, cmd)
outb = subprocess.check_output(ssh_cmd, shell=True)
out = outb.decode('ascii')

print(out)
