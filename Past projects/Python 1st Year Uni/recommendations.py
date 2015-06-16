

import random

scale = [-3,-5,0,5,3,1]
class scaleError(Exception):
    def __init__(self,value):
        self.parameter = value
    def __str__(self):
        return repr(self.parameter)
# Function fileHandle(): we take a filename as argument, open that file
# and return a list with the lines of that file for elements
def fileHandle(filename):
    while 1:
        try:
            file = open(filename,"r")
            break
        except IOError:
            print "No such file or directory!"
    items = file.readlines()
    return items


#in this function we handle the ratings.txt file and we return a dictionary
#which has names for keys and ratings for values
def ratingHandle():
    items = fileHandle("ratings.txt")
    newList = []
    names = {}
    for i in items:
        newList.append(i[:-1])
    i = 0
    while i < len(newList)-1:
        names[newList[i]] = newList[i+1].split()
        i+=2
    return names

#In this function we handle the books.txt file and we return a dictionary
#which has authors names as keys and books as values
def booksHandle():
    items = fileHandle("books.txt")
    newList = []
    books = []
    for i in items:
        newList.append(i[:-1].split(","))

    for i in newList:
        books.append(i)
    return books

#booksHandle()
#ratingHandle()

def recommendations(username,bookRatings,simUsers,rec):
    usernames = ratingHandle()
    books = booksHandle()
    recommendedBooks = []
    recommendedBookBy = []
    counter = 0
    counter2 = 0
    for i in simUsers:
        ratings = usernames[i[0]]
        for k in ratings:
            if counter < rec :
                if k == '3' or k == '5':
                    if bookRatings[counter2] == 0:
                        if not any(books[counter2] in s for s in recommendedBooks):
                            recommendedBookBy.append(username)
                            recommendedBookBy.append(books[counter2])
                            recommendedBookBy.append(i[0])
                            recommendedBooks.append(recommendedBookBy)
                            counter +=1
                recommendedBookBy = []
            else :
                break
            counter2+=1
        counter2 = 0
    for i in recommendedBooks:
        print "For",i[0],":",i[1][0]+", "+i[1][1],"recommended by",i[2]
    return recommendedBooks
        
def simUsers(d,ratings):
        simUsers = []
        simUser = []
        dotProduct = 0
        for key,val in d.items():
            for i in range(len(booksHandle())):
                dotProduct += int(val[i])*int(ratings[i])
            simUser.append(key)
            simUser.append(dotProduct)
            simUsers.append(simUser)
            simUser = []
            dotProduct = 0
        simUsers = sorted(simUsers, key=lambda x: x[1], reverse=True)
        return simUsers
 

def similarity(name,rec):
    usernames = ratingHandle()
    books = booksHandle()
    while 1:
        try:
            outFile = open("output.txt","w")
            break
        except IOError:
            print "No such file or directory!"
    if not usernames.has_key(name):
        bookRatings = [x*0 for x in range(len(books))]
        randomGen = random.sample(range(55), int(len(books)*0.2))
        print "Now you need to rate a few books, because this username does not exist!"
        for i in range(int(len(books)*0.2)):
            b = randomGen[i]
            a = books[b]
            print a[0],", ",a[1],", Enter a number(-5,-3,-1,0,1,3,5):"
            while 1:
                try:
                    rating = input()
                    if not rating in scale:
                        raise scaleError("Invalid input")
                    break
                except (scaleError, NameError):
                    print "Invalid value please try again!"
            bookRatings[b] = rating
        recommendedBooks = recommendations(name,bookRatings,simUsers(usernames,bookRatings),rec)
        for i in recommendedBooks:
            outFile.write("For "+i[0]+":"+i[1][0]+", "+i[1][1]+", recommended by "+i[2]+"\n")
    else:
        for i in range(len(usernames[name])):
            usernames[name][i]= int(usernames[name][i])
        recommendedBooks = recommendations(name,usernames[name],simUsers(usernames,usernames[name]),rec)
        for i in recommendedBooks:
            outFile.write("For "+i[0]+":"+i[1][0]+", "+i[1][1]+", recommended by "+i[2]+"\n") 
    outFile.close()
name = raw_input("Enter a username: ")
while 1:
    try:
        rec = input("Enter the number of recommendations that you want: ")
        if(rec <= 0 or rec > len(bookHandle())): raise NameError
        break
    except (NameError,SyntaxError,ValueError):
        if SyntaxError or rec == 0:
            rec = 10
            break
        print "Invalid value. Try again!"
similarity(name,rec)
