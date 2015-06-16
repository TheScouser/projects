# Училище: ТУЕС ( http://www.elsys-bg.org/ )
# Клас: 11 Б
# Номер: 16
# Име:  Едуард Федев Калфов

# Задача: "Да се отвори CSV файл и да се сумира дадена колона от него."

import csv
total = 0
check =1
try:
    fileName  = raw_input("Enter file name: ")
    reader = csv.reader(open(fileName,'r'))

    while check:
        check = 0
        try:
            col = int(raw_input("Please enter a number: "))
        except NameError:
            print "That was no valid number.Try again!"
            check = 1
    try:
        for row in reader:
            try:
               total += int(row[col])
            except ValueError:
                break
        print total
        
    except IndexError:
        print "Wrong column or out of range"
except KeyboardInterrupt:
    print "Shutdown! Exiting now..."
except IOError:
        print "No such file or wrong file name !"
  
