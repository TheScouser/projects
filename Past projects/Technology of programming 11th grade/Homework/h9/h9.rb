# encoding: utf-8
# Училище: ТУЕС ( http://www.elsys-bg.org/ )
# Клас: 11 Б
# Номер: 16
# Име:  Едуард Федев Калфов

# Задача: "Да се създаде програма,която обработва множество CSV файлове и да се направи доклад за всеки ученик."
	
 def check
 
 test = Dir.glob("*.csv")

 	
 	test.each do |filename|
 	mycsv = CSV.read("#{filename}")
 	
 	CSV.open("report.csv", "a") do |csv|
		

 		mycsv.sort_by { |row| [row[2].to_i,row[3].to_s,row[0].to_s ] }.each do |row|

 			if row[1] == "11A" or row[1] == "11a" or row[1] == "11 A" or row[1] == "11 a" or row[1] == "11А" or row[1] == "11а" or row[1] == "11 A" or row[1] == "11 а" or row[1] == "XI А"  or row[1] == "11-a" or row[1] == "11-а" 
 				row[1] = "11A"
 				csv << [row[1],row[2],row[3],row[4],  "#{filename}",row[0] ,row[5],row[6]]
			end
			

		
			

			
 		end


 	end
 	end
 	CSV.open("report.csv", "a") do |csv|
		

 		mycsv.sort_by { |row| [row[2].to_i,row[3].to_s,row[0].to_s ] }.each do |row|

			
 			if row[1] == "11B" || row[1] == "11b" or row[1] == "11 B" or row[1] == "11 b" or row[1] == "11Б" or row[1] == "11б" or row[1] == "11 Б" or row[1] == "11 б" or row[1] == "11 ф"  or row[1] == "10b"
 				row[1] = "11B"
 				csv << [row[1],row[2],row[3],row[4],"#{filename}",row[0] ,row[5],row[6]]
			end

			
		end

 		csv <<["\n\n\n"]
 	end
 end
 







check


