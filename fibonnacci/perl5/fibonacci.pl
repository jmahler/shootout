#!/usr/bin/perl
use strict;

if (@ARGV != 1) {
	die "usage: $0 <n>\n";
}

my $n = shift @ARGV;

sub fibonacci {
	my $n = shift @_;
	my $n1;
	my $n2;
	my $sum;

	if (0 == $n) {
		return 0;
	} elsif ($n >= 1 && $n <= 2) {
		return 1;
	}

	$n -= 2;

	$n1 = 1;
	$n2 = 1;

	while ($n--) {
		$sum = $n1 + $n2;
		$n1 = $n2;
		$n2 = $sum;
	}

	return $sum;
}

$n = fibonacci($n);

print "$n\n";
