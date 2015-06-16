# Училище: ТУЕС ( http://www.elsys-bg.org/ )
# Клас: 11 Б
# Номер: 16
# Име:  Едуард Федев Калфов

# Задача: "Да се отвори CSV файл и да се намери колко ученици пишат на Python,Ruby,Perl и общия брой на задачите."

import csv
total = 0
total_Python = 0
total_Ruby = 0
total_Perl = 0
check =1
try:
    fileName  = raw_input("Enter file name: ")
    open_file = open(fileName,'r')
    reader = csv.reader(open_file)

    while check:
        check = 0
    try: 
        col = int(raw_input("Please enter the number column: "))
        col2 = int(raw_input("Please enter the language colum: "))
    except ValueError:
        print "Wrong column or out of range"
        check = 1
    try:
        for row in reader: 
            
            if row[col2] == "Python" :
                total_Python = total_Python + 1

            if row[col2] == "Ruby":
                total_Ruby= total_Ruby+ 1
            
            if row[col2] == "Perl":
                total_Perl=total_Perl+1
            try:
                total += int(row[col])
          
            except ValueError:
                print "Ignore the column with the number if it's not integer"
                continue

        print "Total sum: ",total
        print "Python: ",total_Python
        print "Ruby: ",total_Ruby
        print "Perl: ",total_Perl   
        open_file.close()           
    except IndexError:
        print "Wrong column or out of range"
    
except ShutdownRequest:
    print "Shutdown! Exiting now..."
except IOError:
    print "No such file or wrong file name !"
  
