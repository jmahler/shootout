#!/usr/bin/perl
use strict;

if (2 != @ARGV) {
	die "usage: $0 <file1> <file2>\n";
}

my ($file1, $file2) = @ARGV;

open(FILE1, "< $file1")
	or die "open '$file1' failed: $!";

open(FILE2, "< $file2")
	or die "open '$file2' failed: $!";

my $sum1 = 0;
my $sum2 = 0;

while (my $line = <FILE1>) {
	chomp($line);
	$sum1 += $line;
}

while (my $line = <FILE2>) {
	chomp($line);
	$sum2 += $line;
}

my $n = ($sum2 > $sum1) ? ($sum2 - $sum1) : ($sum1 - $sum2);

print "$n\n";

close(FILE1);
close(FILE2);
