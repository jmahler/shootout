#!/usr/bin/awk -f

BEGIN {
	print ARGC " arguments"
	for (i = 0; i < ARGC; i++)
		print i ": '" ARGV[i] "'"
}
