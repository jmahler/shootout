#!/usr/bin/perl
use strict;

=head1 NAME

getopt - show how to get argv options in Perl

=head1 DESCRIPTION

This program shows how to get either a flag option or a key/value pair
from argv.  The value of the arguments are printed as the result.

  $ getopt.pl -f -k abc
  flag = 1
  key = 'abc'

  $ getopt.pl -k abc
  flag = 0
  key = 'abc'

=head1 AUTHOR

 Jeremiah Mahler <jmmahler@gmail.com>
 http://github.com/jmahler

=head1 COPYRIGHT

 Copyright (c) 2014, Jeremiah Mahler. All Rights Reserved.
 This project is free software and released under the
 GNU General Public License.

=cut

use Getopt::Std;

my %opts = (
	f => 0,
	k => '',
);
getopts("fk:", \%opts);

print "flag = " . $opts{f} . "\n";
print " key = '" . $opts{k} . "'\n";
