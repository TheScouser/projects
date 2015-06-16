
books = [["0131176552","Introduction to Computing and Programming in Python","Mark Guzidal"]]

def addBook(p):
    books.append(p)
    return books

def delBookByAuthor(name):
    for i in range(0,len(books)):
        if name in books[i][2]:
            del books[i]
    return books

def delBookByIsbn(isbn):
    for i in range(0,len(books)):
        if isbn in books[i][0]:
            del books[i]
    return books

def delBookByTitle(title):
    for i in range(0,len(books)):
        if title in books[i][1]:
            del books[i]
    return books

def searchByAuthor(name):
    books2=[]
    for i in range(0,len(books)):
        if name in books[i][2]:
            books2.append(books[i])
    return books2

def searchByIsbn(isbn):
    books2=[]
    for i in range(0,len(books)):
        if isbn in books[i][0]:
            books2.append(books[i])
    return books2

def searchByTitle(title):
    books2=[]
    for i in range(0,len(books)):
        if title in books[i][1]:
            books2.append(books[i])
    return books2

l = addBook(["0234452136","Think Computing in Python","Mark Strathie"])

p =  delBookByAuthor("Mark Strathie")
print p
