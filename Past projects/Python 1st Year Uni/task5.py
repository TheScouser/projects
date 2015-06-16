from math import *
from Canvas import *

def checkPoints(points):
    if len(points) % 2 == 0:
        return True
    else:
        return False

def drawLines(points):
    for x in range(0,len(points)-1,1):
        p1 = points[x]
        p2 = points[x+1]
        create_line(p1[0],p1[1],p2[0],p2[1])

def draw(points):
    if checkPoints(points):
        drawLines(points)
    else:
        print " List of points is not valid"

list = [[10,10],[20,20],[30,10],[40,20]]
draw(list)
complete()
