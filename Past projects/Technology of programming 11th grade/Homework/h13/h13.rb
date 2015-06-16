# Училище: ТУЕС ( http://www.elsys-bg.org/ )
# Клас: 11Б
# Номер: 16
# Име:  Едуард Федев Калфов
# 
# Задача: "Да се направи калкулатор смятащ с reverse polish notation." 




def reverse_polish_notation
	puts "If you want to exit the program type \"exit\" " 
	stack = []
	stack = gets
	loop do
		arr = stack.split(" ")
		
		if arr.include?("exit")
			abort
		end


		if arr.include?("+") and stack.length < 3
			arr[0] = arr[0].to_i + arr[1].to_i
			puts arr[0]
		else
			p = 1
			for i in 1..arr.length
				if arr[i] == "+" 
					
						arr[0] = arr[0].to_i + arr[p].to_i
						p += 1
					while arr[p]=="+"
						p += 1
					end
				end
				if arr[i] == "-"
					arr[0] = arr[0].to_i - arr[p].to_i
					p += 1
					while arr[p]=="-"
						p += 1
					end
				end
				if arr[i] == "*"
					arr[0] = arr[0].to_i * arr[p].to_i
					p += 1
					while arr[p]=="*"
						p += 1
					end
				end
				if arr[i] == "/"
					arr[0] = arr[0].to_i / arr[p].to_i
					p += 1
					while arr[p]=="/"
						p += 1
					end
				end

			end
			puts arr[0]
		end
		stack = gets
	end
end

reverse_polish_notation()
