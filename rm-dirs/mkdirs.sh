#!/bin/bash

for n in $(seq 1 10); do
	mkdir "test-$n" &&
	echo "HELLO" > "test-$n/HELLO"
done
