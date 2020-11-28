#include "Cards.h"
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;


class Card {
public:
	//const string bomb = "Bomb";
	//const string reinforcement = "Reinforcement";
	//const string blockade = "Blockade";
	//const string airlift = "airlift";
	//const string diplomacy = "diplomacy";

	//Card methods need to be here
	Card();//default
	Card(string type);//simple constructor
	Card(const Card& obj);//copy
	~Card();//destructor
	void play(Deck deck, Player player1, Player player2); // creates an order and adds to list of orders
	void printCard();


	//getters and setters
	void setType(const string& type) {
		this->type = type;
	}

	string getType()const {
		return this->type;
	}
private:
	string type;
};

//inheritance class for cards
class Bomb : public Card {
public:

private:

};

class Reinforcement : public Card {
public:
private:


};
class Blockade : public Card {
public:
private:


};
class Airlift : public Card {
public:
private:


};
class Diplomacy : public Card {
public:
private:

};




class Hand {
public:
	vector<Card> hand;
private:
	int max_cards_in_hand;

};

class Deck {
public:
	/* draw(Player player);*/
	 //getter and setter
	void setCards_in_deck(const vector<Card>& Cards_in_Deck) {
		this->Cards_in_Deck = Cards_in_Deck;
	}

	vector<Card> getCards_in_Deck()const {
		return this->Cards_in_Deck;
	}

private:
	vector<Card> Cards_in_Deck;
};





//Card::play(Player player) {
//}
//classes functions here
Card::Card() {
	type = "";
}
Card::Card(string type) {
	type = type;
}
//copy constructor
Card::Card(const Card& obj) {
	// body of constructor
	cout << "copy constructor allocating ptr" << endl;
	type = obj.type; // copy the value using deep copy
}
Card::~Card(void) {
	cout << "Freeing Card Memory";
}

void Card::play() {

}
void Card::printCard() {
	cout << "Here are the cards detail. Card type: " << type << endl;
}

//Deck::draw() {
//}
