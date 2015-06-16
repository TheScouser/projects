from math import *
from Canvas import *

def endX(x, d, a):
    return x + sin(radians(a))*d

def endY(y, d, a):
    return y - cos(radians(a))*d

def shape(x,y,n,l):
    angle = 360/n
    start_x = x
    start_y = y
    for j in range(0,n):
        end_x = endX(start_x,l,j*angle)
        end_y = endY(start_y,l,j*angle)
        create_line(start_x,start_y,end_x,end_y)
        start_x = end_x
        start_y = end_y


shape(120,120,10,50)
complete()
