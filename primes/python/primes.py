#!/usr/bin/python

max = 200
num = 2
count = 0

while (count < max):

    found = 1
    for i in list(range(2, num)):
        if (0 == (num % i)):
            found = 0
            break

    if (found):
        print(num)
        count += 1

    num += 1
