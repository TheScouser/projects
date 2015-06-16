# Read in and display voting responses

from GUI import *

# For Part 1, add code here to process the files and produce the
# textual output.

def fileHandle(name):

    file = open(name,"r")
    list = file.readlines()
    handledFile = []
    for i in list:
        handledFile.append(i[:-1].split()) 
    return handledFile

def dupes():
    responses = fileHandle("Responses.txt") 
    i = 0
    p = 0
    while i < len(responses)-1:
        while p+i+1 < len(responses):
            if responses[i][0] == responses[p+i+1][0] and responses[i][1] == responses[p+i+1][1]:
                #print responses[i]
                responses.pop(i)
                p-=1
            p+=1
        i+=1
        p = 0 
    return responses

        
def responseCount():

    responses = dupes() 
    questions = fileHandle("QuestionInfo.txt")

    correctAnswers = []
    for i in questions:
        correctAnswers.append(i[0])
    answers = []
    currentAnswer = []
    for i in range(10):
        currentAnswer.append(0)
    currentQuestion = 1
    counter = 0
    string = ""
    for k in range(len(questions)):
        currentAnswer = []
        for p in range(int(questions[k][1])):
            if p == 9:
                currentAnswer.append(str(0)+":"+str(0))
                break
            currentAnswer.append(str(p+1)+":"+str(0))
        for i in responses:
            if int(i[0]) == k+1:
                while counter < len(currentAnswer[int(i[2])-1]):
                    char = currentAnswer[int(i[2])-1][counter]
                    if(char == ":"):
                        for p in range(len(currentAnswer[int(i[2])-1])-counter-1):
                            string += currentAnswer[int(i[2])-1][counter+p+1]        
                    counter +=1
                counter = 0
                a = int(string)
                
                currentAnswer[int(i[2])-1] = currentAnswer[int(i[2])-1][:-len(string)]+str(1+a)
                string = ""
                
        answers.append(currentAnswer)
    answers.append(correctAnswers)
    return answers

def correctAnswers(answers):
    answers.pop()
    questions = fileHandle("QuestionInfo.txt")

    for i in range(len(questions)):
        answers[i][int(questions[i][0])-1] = "**"+str(answers[i][int(questions[i][0])-1])+"**"
    return answers

def printing(answers):
    for i in range(len(answers)):
        print "Question ",i+1
        print answers[i]

def splitting(answers):
    data = []
    l = []
    correctAnswers = answers.pop()
    for i in range(len(answers)):
        for j in range(len(answers[i])):
           data.append(answers[i][j].split(':'))
        l.append(data)
        data = []
    #print l
    l.append(correctAnswers)
    return l



printing(correctAnswers(responseCount()))


########

# For Part 2, uncomment the line below (with suitable modifications) to
# start the graphical user interface.

application(splitting(responseCount())) # The "..." indicates that parameters will be needed
