#!/usr/bin/perl
use strict;

use Linux::Inotify2;

die "usage: $0 <file or dir>\n" unless (1 == @ARGV);

my $node = $ARGV[0];

my $inotify = new Linux::Inotify2
	or die "Unable to create inotify object: $!";

$inotify->watch($node, IN_ALL_EVENTS)
	or die "Unable to watch '$node': $!";

while (1) {
	my @events = $inotify->read;

	foreach my $event (@events) {
		print "---\n";
		if ($event->name) {
			print $event->name . "\n";
		} else {
			print "(dir)\n";
		}

		if ($event->mask & IN_ACCESS) {
			print "IN_ACCESS\n";
		}
		if ($event->mask & IN_ATTRIB) {
			print "IN_ATTRIB\n";
		}
		if ($event->mask & IN_CLOSE_WRITE) {
			print "IN_CLOSE_WRITE\n";
		}
		if ($event->mask & IN_CLOSE_NOWRITE) {
			print "IN_CLOSE_NOWRITE\n";
		}
		if ($event->mask & IN_CREATE) {
			print "IN_CREATE\n";
		}
		if ($event->mask & IN_DELETE) {
			print "IN_DELETE\n";
		}
		if ($event->mask & IN_DELETE_SELF) {
			print "IN_DELETE_SELF\n";
		}
		if ($event->mask & IN_MODIFY) {
			print "IN_MODIFY\n";
		}
		if ($event->mask & IN_MOVE_SELF) {
			print "IN_MOVE_SELF\n";
		}
		if ($event->mask & IN_MOVED_FROM) {
			print "IN_MOVED_FROM\n";
		}
		if ($event->mask & IN_OPEN) {
			print "IN_OPEN\n";
		}
		if ($event->mask & IN_MOVE) {
			print "IN_MOVE\n";
		}
		if ($event->mask & IN_CLOSE) {
			print "IN_CLOSE\n";
		}
	}
}
