#!/usr/bin/python2

from __future__ import print_function
import paramiko
import sys

try:
    host, cmd = sys.argv[1:3]
except:
    print("usage: {} <host> <cmd>".format(sys.argv[0]))
    sys.exit(1)

ssh = paramiko.SSHClient()

ssh.load_system_host_keys()
# - Be sure to ssh to the host first to add it to ~/.ssh/known_hosts
#ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
# - It is not safe to auto add keys, but if load_system_host_keys()
# doesn't work, it can be enabled as a temporary workaround.
# - If load_system_host_keys() doesn't work it might be because
# sshd is using ECDSA which Paramiko doesn't support.

ssh.connect(host)

stdin, stdout, stderr = ssh.exec_command(cmd)
print(stdout.read())
