#!/usr/bin/perl

my @lines = (<STDIN>);

my @sorted_lines = sort @lines;

print @sorted_lines;
