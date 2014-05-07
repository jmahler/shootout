#!/usr/bin/perl
use strict;

=head1 NAME

strcomb - Generate all combinations of a string of characters.

=head1 SYNOPSIS

  $ strcomb.pl abc
  abc
  acb
  bac
  bca
  cab
  cba
  Total: 6
  $

=cut

unless (@ARGV) {
	die "usage: $0 <string>\n";
}

my $str = $ARGV[0];

my @chars = split //, $str;

my $total_comb = 0;

sub next_comb {
	my ($cur, $left) = @_;

	if (@$left) {
		for (my $i = 0; $i < @$left; $i++) {
			my @next_left = @$left;
			splice(@next_left, $i, 1);

			next_comb([(@$cur, $left->[$i])], [@next_left]);
		}
	} else {
		my $res = join "", @$cur;
		print "$res\n";
		$total_comb++;
	}
}

next_comb([], [@chars]);

print "Total: $total_comb\n";

