#!/usr/bin/perl
use strict;

my @lines = (<STDIN>);

my @sorted_lines = insertion_sort(@lines);

print @sorted_lines;

sub insertion_sort {
	my @lines = @_;

	for (my $i = 1; $i < @lines; $i++) {
		my $key = $lines[$i];
		my $j;

		for ($j = $i - 1; $j >= 0; $j--) {
			last if ($key gt $lines[$j]);
			$lines[$j + 1] = $lines[$j]
		}
		$lines[$j + 1] = $key;
	}

	return @lines;
}
