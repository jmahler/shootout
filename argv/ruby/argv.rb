#!/usr/bin/ruby

argc = ARGV.length

puts "#{argc} arguments"

for i in 0..(argc - 1)
	puts "#{i}: '#{ARGV[i]}'"
end
