#!/bin/bash

echo "$# arguments"

i=0
while (($#)); do
	echo "$i: '$1'"
	shift
	((i++))
done
