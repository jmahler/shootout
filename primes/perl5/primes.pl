#!/usr/bin/perl
use strict;

if (2 != @ARGV) {
	die("usage: $0 <start> <n>\n");
}

my $num = shift @ARGV;  # number to start from
my $max = shift @ARGV;  # number of primes to find

my $count = 0;
while ($count < $max) {

	my $found = 1;  # default, found=true
	for (my $i = 2; $i < $num; $i++) {
		if (0 == ($num % $i)) {
			$found = 0;
			last;
		}
	}

	if ($found) {
		print "$num\n";
		$count++;
	}

	$num++;
}
