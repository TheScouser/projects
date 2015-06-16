months = {1:"Jan",2:"Feb",3:"Mar",4:"Apr",5:"May",6:"Jun",7:"Jul",8:"Aug",9:"Sep",10:"Oct",11:"Nov",12:"Dec"}
class dayError(Exception):
    def __init__(self, value):
        self.parameter = value
    def __str__(self):
        return repr(self.parameter)
class monthError(Exception):
    def __init__(self, value):
        self.parameter = value
    def __str__(self):
        return repr(self.parameter)
def menu():
    while(1):
        print "Select an option: "
        print "Option:1- read bBook"
        print "Option:2- find nextWeek b-days"
        print "Option:3- print b-day of person"
        print "Option:4- exit program"
        selected = input()
        if selected == 4:
            break
        options[selected]()
        
def Exception():
    print "no such name"
    return 0
        
def bBook1():
    bBook1 = {}
    filename = raw_input("please type the filename: ")
    #except IOError:
     #   print "file not existent bro"
        #pass
    bBook2 = bBook(filename,bBook1)
    print bBook2
    print "\n"
    
def printDay1():
    bBook1 = {}
    filename = raw_input("please type the filename: ")
    bBook2 = bBook(filename,bBook1)
    printBday(bBook2)
    print "\n"
    
def printName1():
    bBook1 = {}
    filename = raw_input("please type the filename: ")
    bBook2 = bBook(filename, bBook1)
    printName(bBook2)

def bBook(fileName,bBook):
   # bBook = {"john":{"Month":10,"day":2},"marie":{"Month":9,"day":28},"jim":{"Month":9,"day":6},"jack":{"Month":11,"day":12},"jimmy":{"Month":3,"day":30}}
    while(1):
        try:
            file = open(fileName,'r')
            break
        except IOError:
            fileName = raw_input("no file bro try reentering the name: ")
    list = file.readlines()
    newList = []
    bBookDay = {}
    for i in range(len(list)):
        newList.append(list[i][:-1])

    #print newList
    list = []
    for i in range(len(newList)):
        list.append(newList[i].split(','))
    for i in range(len(newList)):
        bBookDay["Day"] = int(list[i][2])
        bBookDay["Month"] = list[i][1]
        bBook[list[i][0]] = bBookDay
        bBookDay = {}
    return bBook


def printName(bBook):
    while(1):
        name = raw_input("enter name of person: ")
        try:
            print bBook[name]
            break
        except KeyError:
            print "Enter name!!!"

def printDay(bBook,month):

    for key,val in bBook.items():
       if(val.get("Month")== month):
           print key
           print val
    
def printBday(bBook):
    while(1):
        try:
            day = input("please type the day: ")
            if(day > 31):
                raise dayError("FAIL FAIL FAIL")
            break
        except dayError:
            print "Wrong date!"
    while(1):        
        try:
            month = input("please type the month: ")
            if(month > 12 or (day > 28 and month==2)):
                raise monthError("FAIL FAIL FAIL")
            break
        except monthError:
            print "Wrong date!"
    if day > 23:
        check = True
        
    else:
        check = False
        
    for key,val in bBook.items():
        if(check == False):
            for i in range(0,7):
                #print val
                
                if(val.get("Month") == months[month] and val.get("Day") == day+i):
                    print key,months[month],val["Day"]
        else:
            k = 0
            for i in range(0,7):
                if(day+i<31):
                    if(val.get("Month") == months[month] and val.get("Day") == day+i):
                        print key,months[month],val["Day"]
                else:
                    if(month == 12):
                        month1 = 1
                    else:
                        month1 = month + 1
                    if(val.get("Month") == months[month1] and val.get("Day") == k+1):
                        print key,months[month1],val["Day"]
                    k = k + 1    
            month1 = 0           
options = {1:bBook1,
           2:printDay1,
           3:printName1,
           4:"QUIT"}                    
    
bBook1 = {}
#bBook = bBook('birthdays.txt',bBook1)
#print bBook
#printName(bBook,"marie")
#printDay(bBook,"oct")
#printBday(bBook,4,1)
menu()
