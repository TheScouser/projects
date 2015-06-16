from math import *
from Canvas import *
from task4 import *


def endX(x, d, a):
    return x + sin(radians(a))*d

def endY(y, d, a):
    return y - cos(radians(a))*d

def shapePoints(x,y,n,l):
    #shapes = []
    points = [shape(x,y,n,l)]
    #shapes.append(points)
    points.append(shape(x+50,y+50,n+2,l))
    points.append(shape(x+100,y+100,n+3,l))
    points.append(shape(x+150,y+150,n+4,l))
    drawLines(points)

def shape(x,y,n,l):
    angle = 360.0/n
    points = [x,y]
    
    start_x = x
    start_y = y
    for j in range(0,n):
        end_x = endX(start_x,l,j*angle)
        end_y = endY(start_y,l,j*angle)
        create_line(start_x,start_y,end_x,end_y)
        points.append(end_x)
        points.append(end_y)
        start_x = end_x
        start_y = end_y
    return points

shapePoints(100,100,5,50)
complete()
