def join(a,b):
    new_list=[]
    i=0
    if (a!=[] and b!=[])and (a!=[1] and b!=[1]):
        new_list=[[a[i],b[i]],[a[i+1],b[i+1]],[a[i+2],b[i+2]]]
        print new_list
    else:
        print 'Enter a list with more than one element'
        
join([1,2,3],["a","b","c"])
