# Училище: ТУЕС ( http://www.elsys-bg.org/ )
# Клас: 11 Б
# Номер: 16
# Име:  Едуард Федев Калфов

#Задача: "Да се създаде програма, която да запълва празните места в самолет,
#       като х да е в интервала 1<=х<=3 (пътниците). Всяка група пътници не треябва да са
#      разделени от пътеката, или реда. Пример : 100 000 (да), 122 000 (да) ,133 300 (не), 223 330 (не), 221 333 (да)." 

class Airplane
	@@seats = Hash.new {0}
	@@total = 0
	@@check = false

	def	add(rvalue)
		@@check = false
		j = 0
		i = 0
		
		while i<27
			j = 0
			while j<6
				if @@seats[[j,i]] == 0
					if rvalue == 1
						@@seats[[j,i]] = 1
						@@total += rvalue
						@@check = true
						break
					end
					
					if rvalue == 2  && j<=4
						if @@seats[[j+1,i]] == 0 && j%3<=1
							@@seats[[j,i]] = 2
							@@seats[[j+1,i]] = 2
							@@total = @@total + rvalue
							@@check = true
							break
						end
					end
					
					if rvalue == 3 && j<=3
						if @@seats[[j+1,i]] == 0 && @@seats[[j+2,i]] == 0 && j%3 == 0
							@@seats[[j,i]] = 3
							@@seats[[j+1,i]] = 3
							@@seats[[j+2,i]] = 3
							@@total = @@total + rvalue
							@@check = true
							break
						end
					end
					
					j = j + 1
				else
					j = j + 1
				end
			end
			if @@check == true
				i = 27
			else
				i = i + 1
			end
		end
		if @@check == false
			print "The plane is full..."
		end
	end

	def free_seats()
		if @@total < 162
			freeseats = 162 - @@total
			return freeseats
		else 
			puts "There are no freeseats left"
			return 0
		end
	end

	def printSeats()
		for  j in 0..26
				for i in 0..5
					
					print @@seats[[i,j]]
					if i==2
						print " "
						
					end
					
				end
			print "\n"
		end
	end
	
	air = Airplane.new
	people = 0
while air.free_seats() > 0
	people = rand(3) + 1
	air.add(people)
end
	air.printSeats
	puts air.free_seats
end