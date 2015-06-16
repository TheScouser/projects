# Program to simulate a ball bouncing horizontally left/right across the screen
# within a boundary rectangle

from Canvas import *

# These define the boundary rectangle
xMin = 10
yMin = 10
xMax = 200
yMax = 200

ballDiameter = 4

# This function performs the drawing for us
def drawBouncingBall():
    
    ballX = [] #30   # The position of the ball on the screen
    ballY = [] #30
    xInc  = 3    # The amount to change the horizontal position of
    yInc  = 10   # the ball by each time the drawing is updated

    boundary = create_rectangle( xMin, yMin, xMax, yMax )

    ball =  [] #create_oval( ballX, ballY, ballX+4, ballY+4 )
    print ball
    j=10
    t=20
    k=0
    while k < 4:
        ballX.append(30+j)
        ballY.append(30+t)
        #
        t+=10
        j+=20
        k+=1
    x=0
    print ball
    # Loop forever!!  The user can interrupt this drawing by clicking the mouse
    while True:
           
            yInc = yInc - 5
            v2 = - yInc + 0.5*yInc
            ballX[x] = ballX[x] + xInc   # Update the X position of the ball
            ballY[x] = ballY[x] + v2
            # Perform necessary checks.  What ARE we checking for here????
            # And, what are we doing according to the results of the checks
            if ballX[x] <= xMin:
                ballX[x] = xMin
                xInc = -xInc
            elif ballX[x] >= xMax:
                ballX[x] = xMax
                xInc = -xInc

            if ballY[x] <= yMin:
                ballY[x] = yMin
                yInc = -yInc
            elif ballY[x] >= yMax:
                ballY[x] = yMax
                yInc = -yInc

            delete( ball )
            ball = create_oval( ballX[x], ballY[x], ballX[x]+ballDiameter, ballY[x]+ballDiameter )
            
            x+=1
            if x==3:
                x=0
            wait( 0.04 )  # just so we can see it!

# Now submit the drawing function to the system
# Don't fret about this bit too much, just trust that it works!
runGraphicsFn( drawBouncingBall )

complete()   # Necessary so that the user can halt execution as required
