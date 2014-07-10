#!/usr/bin/perl
use strict;

my $argc = @ARGV;

print "$argc arguments\n";

for (my $i = 0; $i < $argc ; $i++) {
	print "$i: '" . $ARGV[$i] . "'\n";
}
