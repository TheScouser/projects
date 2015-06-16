from Canvas import *
positionX = 0
positionY = 0

def changePosition(args):
   global positionX
   global positionY
   positionX = args[0]
   positionY = args[1]

        

def movePosition(args):
    global positionX
    global positionY
    positionX = args[0]+positionX
    positionY = args[1]+positionY

def drawCircle(args):
    global positionX
    global positionY
    create_oval(positionX-args[0],positionY-args[0],positionX+args[0],positionY+args[0])


def drawLine(args):
    global positionX
    global positionY
    #print positionX,positionY
    #print positionX,positionY,args[0],args[1]
    create_line(positionX,positionY,args[0]+positionX,args[1]+positionY)
    positionX = args[0]+positionX
    positionY = args[1]+positionY
    
def readFile():
    filename = raw_input("Please enter filename: ")
    file = open(filename,"r")
    fileLines = file.readlines()
    commandsList = []
    for line in fileLines:
        line = line[:-1]
        commandsList.append(line)

    #print commandsList
    return commandsList

def dealWithDefs(commandsList):
    k = 1
    i = 0
    arguments = []
    while i < len(commandsList):
        while k < len(commandsList[i]):
            arguments.append(int(commandsList[i][k]))
            k += 1
        k = 1
        commands[commandsList[i][0]](arguments)
        arguments = []
        i+=1

def dealWithLoops(counter,commandsList):
    arguments = []
    i = 0
    k = 1
    loopList = []
    defineEnd= ""
    #print commandsList
    print positionX,positionY,counter
    global definitions
    for x in range(counter):
        while i<len(commandsList):
            if(commandsList[i][0] in definitions):
                dealWithDefs(definitions[commandsList[i][0]])
                i = i+1
            elif commandsList[i][0] == "loop":
                counter = int(commandsList[i][1])
                while 1:
                   defineEnd = commandsList[i+1][0]
                   if defineEnd == "end":
                     i = i+2
                     break
                   loopList.append(commandsList[i+1])
                   i += 1
                loops[counter] = loopList
                loopList = []
                dealWithLoops(counter, loops[counter])
                i = i+1
            else:
                while k < len(commandsList[i]):
                    arguments.append(int(commandsList[i][k]))
                    k += 1
                k = 1
                commands[commandsList[i][0]](arguments)
                arguments = []
                i = i + 1
        i = 0

def dealWithCommands(commandsListOld):
    #create_line(50,50,25,25)
    k = 1
    arguments = []
    commandsList = []
    defineList = []
    defineEnd = ""
    global definitions
    definitions = {}
    loopList = []
    defName = ""
    loops = {}
    for i in range(len(commandsListOld)):
        commandsList.append(commandsListOld[i].split(' '))
    i = 0
    while i<len(commandsList):
        if(commandsList[i][0] == "define"):
            #defineList.append(commandsList[i][1])
            defName = commandsList[i][1]
            while 1:
                defineEnd = commandsList[i+1][0]
                if defineEnd == "end":
                    i = i+2
                    break
                defineList.append(commandsList[i+1])
                i += 1
            definitions[defName] = defineList
            defineList = []

        elif(commandsList[i][0] in definitions):
            dealWithDefs(definitions[commandsList[i][0]])
            i = i+1
        elif(commandsList[i][0] == "loop"):
            counter = int(commandsList[i][1])
            while 1:
                defineEnd = commandsList[i+1][0]
                if defineEnd == "end":
                    i = i+2
                    break
                loopList.append(commandsList[i+1])
                i += 1
            loops[counter] = loopList
            loopList = []
            dealWithLoops(counter, loops[counter])
        else:
            while k < len(commandsList[i]):
                arguments.append(int(commandsList[i][k]))
                k += 1
            k = 1
            commands[commandsList[i][0]](arguments)
            arguments = []
            i = i + 1
commands = {"line":drawLine, "position":changePosition, "move":movePosition, "circle":drawCircle}
    

dealWithCommands(readFile())
complete()
