def doubleList(n):
    list = []
    x=0
    while x < len(n):
        list.append(n[x]*2)
        x+=1
    return list

l = doubleList([2,3,4,5])
print l
