#!/bin/bash

if [ ! -z "$1" ]; then
	cat "$1" | python3 -mjson.tool --sort-keys
else
	python3 -mjson.tool --sort-keys
fi
