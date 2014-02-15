#!/usr/bin/perl
use strict;

use Fcntl qw(:flock);

if (1 != @ARGV) {
	print "usage: $0 <file>\n";
	exit 1;
}

my $fd;

open($fd, "+>", $ARGV[0])
	or die "unable to open \"$ARGV[1]\": $!\n";

$|=1;  # turn on flush of stdout
print "acquiring lock...";
flock($fd, LOCK_EX)
	or die "Unable to create lock: $!\n";
print "done\n";

print "Enter data: ";
my $line = <STDIN>;
print $fd $line;

print "releasing lock...";
flock($fd, LOCK_UN)
	or die "Unable to release lock: $!\n";
print "done\n";

close($fd);
