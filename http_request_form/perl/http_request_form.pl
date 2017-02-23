#!/usr/bin/perl

use LWP::Simple;
use URI;

my $url = 'http://pgp.mit.edu/pks/lookup';
my %form_vals = (
	search => 'jmmahler@gmail.com',
	op => 'index',
);

my $uri = URI->new($url);
$uri->query_form(%form_vals);

my $res = get $uri;

if ($res =~ /Jeremiah Mahler/) {
	print "OK\n";
} else {
	print "ERROR Unexpected response\n";
}
