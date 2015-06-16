from cards import *

cardD = {"A" : (1,11),"2" : (2,False), "3": (3,False), "4" : (4,False), "5": (5,False), "6": (6,False), "7": (7,False), "8": (8,False), "9": (9,False), "10" : (10, False), "J" : (10,False), "Q": (10,False), "K": (10, False)}


cards = initDeck()
cards = shuffleCards(100,cards)

def printDeck(deck):
    for p in deck: print p


def count(cards):
    global cardD

    count = 0
    for p in cards:
        if p[0] == "1":
            a = (10,False);
        else:
            a = cardD[p[0]]

        if a[1] == False:
            count += a[0]
        else:
            count += a[1]

    return count
    
def play(cards):
    nextCard = 0
    playerCards = []
    dealerCards = []

    #player cards
    playerCards.append(cards[nextCard])
    nextCard += 1
    playerCards.append(cards[nextCard])
    nextCard += 1

    #dealer cards
    dealerCards.append(cards[nextCard])
    nextCard += 1
    dealerCards.append(cards[nextCard])
    nextCard += 1

    #print info
    print "Dealer cards: ", dealerCards[0], " ##"

    print "your cards: "
    printDeck(playerCards)
    print "you have: ",count(playerCards)," points"

    if count(playerCards) > 21:
        print "you have: ",count(playerCards)," points"
        print "You lose"
        return False
    elif count(playerCards) == 21:
        print "you have: ",count(playerCards)," points"
        print "You win"
        return True

    #player draws
    while True:
        a = raw_input("do you want to draw? [y/n]")
        if a == "y":
            playerCards.append(cards[nextCard])
            nextCard += 1
            print "you have: ",count(playerCards)," points"
            if count(playerCards) > 21:
                print "you have: ",count(playerCards)," points"
                print "dealer has: ",count(dealerCards)," points"
                print "You lose!"
                return False
        else:
            print "you have: ",count(playerCards)," points"
            break

    #dealer draws
    if count(dealerCards) > 21:
        print "you have: ",count(playerCards)," points"
        print "You win"
        return True
    elif count(dealerCards) == 21:
        print "you have: ",count(playerCards)," points"
        print "dealer has: ",count(dealerCards)," points"
        print "You lose"
        return False
    elif count(dealerCards) > 17:
        if count(dealerCards) < count(playerCards):
            print "you have: ",count(playerCards)," points"
            print "You win"
            return True
        else:
            print "you have: ",count(playerCards)," points"
            print "dealer has: ",count(dealerCards)," points"
            print "You lose"
            return False
    
    while count(dealerCards) < 17:
        dealerCards.append(cards[nextCard])
        nextCard += 1
        if count(playerCards) > 21:
            print "you have: ",count(playerCards)," points"
            print "dealer has: ",count(dealerCards)," points"
            print "You lose"
            return False
        elif count(dealerCards) > count(playerCards) and count(dealerCards) <= 21:
            print "you have: ",count(playerCards)," points"
            print "dealer has: ",count(dealerCards)," points"
            print "You lose"
            return False
        elif count(dealerCards) < count(playerCards):
            print "you have: ",count(playerCards)," points"
            print "dealer has: ",count(dealerCards)," points"
            print "You win"
            return True

    if  count(dealerCards) > count(playerCards):
        print "you have: ",count(playerCards)," points"
        print "dealer has: ",count(dealerCards)," points"
        print "You win"
        return True
    else:
        print "you have: ",count(playerCards)," points"
        print "dealer has: ",count(dealerCards)," points"
        print "You lose"
        return False
play(cards)
