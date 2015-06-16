#Училище: ТУЕС ( http://www.elsys-bg.org/ )
#Клас: 11 Б
#Номер: 16
#Име:  Едуард Федев Калфов

#Задача: Програма,която чете от .csv файл след това записва в друг random генерирано число. 

require 'csv'



def work
	
	
	ARGV.each do|a|
		p a		
		CSV.open("new_belt.csv", "wb") do |csv|
			CSV.foreach("#{a}") do |row|
				csv<<[row[0],row[1],rand(row[1].to_i/2)]
			end
		
		end
	
	end
end



work