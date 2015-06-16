# Училище: ТУЕС ( http://www.elsys-bg.org/ )
# Клас: 11 Б
# Номер: 16
# Име:  Едуард Федев Калфов

#Задача:Кой е най-свързаният номер в клас - всеки ученик получава листа от друг. Написва си номера на него. Човекът, който е получил лист най-много пъти е най-свързаният номер в клас
#Кой е най-малко свързаният номер в клас - аналогично на горната, човекът написал най-малко пъти номера си е най-малко свързаният.


require 'csv'

def given_counter_max

                
                files=Dir.glob("*.csv")
                
                for i in 1..29
                        arr=Array.new(29,0)
                        files.each do |name|
                                help=0
                                CSV.foreach("#{name}") do |row|
                                        
                                        if Integer(row[0]) == i
                                                help=1  
                                                next
                                        end
                                        
                                        if help==1
                                                arr[Integer(row[0])-1] = arr[Integer(row[0])-1]+1 
                                                help=0
                                        end
                                        
                                
                                end
                        
                        end

                        for z in 0..28
                                
                                if arr.sort[-1]==0
                                        printf("Nomer %d ne e predal na nikoi !",i)
                                        break
                                end
                                if arr[z]==arr.sort[-1]
                                        
                                        printf("Nomer %d, e predal nai-mnogo na %d [%d puti]\n",i,z+1,arr[z])
                                        
                                end
                        end
                        puts
                end
end

def number_given
	i = 1
	test = Dir.glob("*.csv") 
	arr = Array.new(0)
	arr2 = Array.new(0) 
	arr3 = Hash.new(0)
	arr4 = Array.new(0)
	for p in 0..30
		arr[p] = 0
	end
	
	test.each do |filename|
		CSV.foreach("#{filename}") do |row|
		arr[row[0].to_i] += 1

		end
	end

	test.each do |filename|
		CSV.foreach("#{filename}") do |row|
		arr2[i] = row[0].to_i
		arr3[[arr2[i-1],arr2[i]]] += 1
		i = i + 1
		
		end
	end


	for i in 1...31
	#	print i, " - ", arr[i], "\n"
	end
	min = arr.index(arr.min)
	max = arr.index(arr.max) 
	
	for i in 1..29
		if arr[i] == arr[max]
		print "The most popular is: ", i, " - ", arr[i], "\n"
		end
	end
	
	for i in 1..29
		if arr[i] == arr[min]
		print "The least popular is: ", i, " - ", arr[i], "\n"
		end
	end
	top = 0
	maxr = 0
	maxs = 0
	p  = 1
	s = 1
	count = 0
	for i in 1..29
		top = 0
		for j in 1..29
			
			if arr3[[j,i]].to_i > top
				top = arr3[[j,i]].to_i
				
				maxs = j
				maxr = i
				s += 1
			
			end
			

			
		end

		
	
		for j in 1..29
			
			if	arr3[[j,i]].to_i == arr3[[maxs,i]].to_i
				count +=1
				arr4[s] = j
				print "Nomer " ,arr4[s], " e predal nai-mnogo na ", maxr, "[",arr3[[j,i]].to_i,"]" , "\n"
				puts
				s = s + 1
				
			end
			
		end
	
		
		s = 0
		maxr = 0
		maxs = 0
	end
		
	
	

end	

def number_taken

        files=Dir.glob("*.csv")

        for i in 1..29
                arr=Array.new(29,0)
                files.each do |name|
                        help=0
                        CSV.foreach("#{name}") do |row|
                                
                                if help == 0
                                        help=Integer(row[0])    
                                        next
                                end
                                
                                if Integer(row[0]) == i
                                        arr[help-1] = arr[help-1]+1 
                                        help=0
                                elsif
                                        help = Integer(row[0])
                                end
                        
                        end
                
                end
                
                for z in 0..28
                                
                                if arr.sort[-1]==0
                                        printf("Nomer %d ne mu e predal nikoi !",i)
                                        break
                                end
                                if arr[z]==arr.sort[-1]
                                        
                                        printf("Nomer %d, %d nomer mu e predal nai-mnogo puti [%d puti]\n",i,z+1,arr[z])
                                        
                                end
                end
                puts
        end
end

number_given
number_taken
given_counter_max