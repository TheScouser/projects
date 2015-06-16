class Objects 
	
	# def value=(v)
	# 	@value = v
	# end
	# def value
	# 	@value
	# end

	attr_accessor :value

	def method
		i  = 10
		i-7
	end
	private 
	def method_private
		puts "something"
	end

	public 
	def method_public

	end



end

 o = Objects.new
 o.value
 o.value  = 10 
 p o.value