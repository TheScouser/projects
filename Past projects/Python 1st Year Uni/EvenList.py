def EvenList(n):
    list =[]
    for x in range(2,n):
        if x%2 == 0:
            list.append(x)
    return list

l = EvenList(10)
print l
