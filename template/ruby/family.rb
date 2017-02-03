#!/usr/bin/ruby

require 'mustache'

class Child
	def initialize(name)
		@name = name
	end

	def name
		@name
	end
end

class Family < Mustache
	self.template_path = __dir__  # find .mustache files in current dir

	def initialize(name, kids)
		@name = name
		@kids = []
		for kid in kids
			@kids.push(Child.new(kid))
		end
	end

	def name
		@name
	end

	def num_kids
		kids.length
	end

	def kids
		@kids
	end
end

family = Family.new('Jeff', ['Jim', 'Lisa'])

puts family.render
