#!/usr/bin/perl

my $max = 200;  # number of primes to find
my $num = 2;
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
