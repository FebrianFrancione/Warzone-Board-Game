#include "Cards.h"
#include <iostream>
#include <string>

using namespace std


class Card {

public:
	const string bomb = "Bomb";
	const string reinforcement = "Reinforcement";
	const string blockade = "Blockade";
	const string airlift = "airlift";
	const string diplomacy = "diplomacy";

	//Card mrthods need to be here
	Card();//default
	Card(string cardName);//simple ciostructor
	Card(const Card& obj);//copy
	~Card();//destructor
private:
	string* type;

};

//classes functions here
Card() {
	this.type = "";
}

Card(string cardName) {
	this.type = cardName;
}

//copy constructor
Card(const Card& obj) {
	// body of constructor
	cout << "copy constructor allocating ptr" << endl;
	type = new string;
	*type = *obj.type; // copy the value using deep copy
}

~Card(void) {
	cout << "Freeing Card Memory";
	delete type;
}

void printCard() {
	cout << "Here are the cards detail. Card type: " << type << endl;

}

class Deck {
	//hasmap
};