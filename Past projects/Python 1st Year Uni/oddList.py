def oddList(n):
    list =[]
    for x in range(1,n):
        if x%2 != 0:
            list.append(x)
    return list

l = oddList(10)
print l
