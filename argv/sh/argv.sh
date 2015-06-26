#!/bin/sh

echo "$# arguments"

i=0
while [ "$#" -gt 0 ]; do
	echo "$i: '$1'"
	shift
	i=$(($i + 1))
done
