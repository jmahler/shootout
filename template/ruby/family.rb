#!/usr/bin/ruby

require 'mustache'

class Child
	attr_reader :name

	def initialize(name)
		@name = name
	end
end

class Family < Mustache
	attr_reader :name, :kids

	self.template_path = __dir__  # find .mustache files in current dir

	def initialize(name, kids)
		@name = name
		@kids = []
		for kid in kids
			@kids.push(Child.new(kid))
		end
	end

	def num_kids
		kids.length
	end
end

family = Family.new('Jeff', ['Jim', 'Lisa'])

puts family.render
