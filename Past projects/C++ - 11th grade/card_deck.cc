#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Card{
	string value_;
	string suit_;
public:


    string get_suit(){
		return suit_;
	}

    string get_value(){
		return value_;
	}

    void set_value(string value){
        value_=value;
    }

     void set_suit(string suit){
        suit_=suit;
    }
	void print(){
cout << "Value: " << value_ << "  Suit: " << suit_ << endl;
	}
};

class Deck{
	Card cards_[52];
public:
    Deck(){
		int currentCard = 0;
		string Suit[] = {"Hearts", "Spades", "Clubs", "Diamonds"};
		string Value[] = {"2", "3", "4", "5","6", "7", "8", "9","10", "J", "Q", "K","A"};

		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 13; j++){
				cards_[currentCard].set_suit(Suit[i]);
				cards_[currentCard].set_value(Value[j]);
				currentCard++;
			}
		}
	}


	void shuffle(){
	  	int from, to;
		Card temp;

		for (int i = 0; i < 100; i++){
			from = rand() % 52;
			to = rand() % 52;
			temp = cards_[from];
			cards_[from] = cards_[to];
			cards_[to] = cards_[from];
		}
	}

	Card at(int i){
		return cards_[i];

	}

};

int main()
{
    Deck myDeck;
	myDeck.at(8).print();
	myDeck.shuffle();

	myDeck.at(8).print();
	return 0;
}
