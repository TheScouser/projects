def validateIsbn(isbn):
    if len(isbn) == 10 and isbn[9].isdigit() or isbn[9]=='X':
        i=10
        x=0
        s=0
        while i > 0:
            help  = isbn[0+x]
            if help == "X":
                help = 10
            else:
                help = int(isbn[0+x])
            s = s + i*help
            i-=1
            x+=1
        if s % 11 == 0:
            return True
        else:
            return False

t = validateIsbn("1854241745")
print t

def checkIsbnFormat(isbn):
    count = 0
    if len(isbn) == 10:
        if isbn[9].isdigit() or isbn[9]=='X':
            for i in range(0,9):
                if not isbn[i].isdigit():
                    print isbn[i]," is not a digit"
                else:
                    count+=1
    if count == 9:
        i=10
        x=0
        s=0
        while i > 1:
            help  = isbn[0+x]
            if help == "X":
                help = 10
            else:
                help = int(isbn[0+x])
            s = s + i*help
            i-=1
            x+=1

        for z in range(0,10):
            if (s+z)%11 == 0:
                if z==10:
                    print "The correct check character is X"
                    
                else:
                    print "The correct check character is ",z
                    print s
                
        return True
    else:
        return False

p = checkIsbnFormat("18542174X")

