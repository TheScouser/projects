# �������: ���� ( http://www.elsys-bg.org/ )
# ����: 11 �
# �����: 16
# ���:  ������ ����� ������

# ������: "�� �� ������ CSV ���� � �� �� ������ ������ ������ �� ����."

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
  
