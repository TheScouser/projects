import bmany
d = {}

command=raw_input('Enter a command: ')

while command != 'quit':
    if command=='read':
        fileName=raw_input('Enter a file name: ')
        bmany.filling_birthday_book(fileName,d)

    elif command=='birthday':
        nameOfPerson=raw_input('Enter a name: ')
        bmany.FindBirthday(d,nameOfPerson)

    elif command=='month':
        month=raw_input('Enter a month: ')
        bmany.FindByMonth(month)

    elif command=='following week':
        month=raw_input('Enter a month: ')
        date=input('Enter a date: ')
        bmany.BirthdayComing(d)
            
        

    print
    command=raw_input('Enter a command: ')



print d
