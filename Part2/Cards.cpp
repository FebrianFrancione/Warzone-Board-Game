#include "Cards.h"
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

Card::Card() {
	type = "Default Card";
}

Card::Card(std::string t) {
	type = t;
}

//copy constructor
Card::Card(const Card& obj) {
	// body of constructor
	cout << "copy constructor allocating ptr" << endl;
	type = obj.type; // copy the value using deep copy
}

Card::~Card(void) {
	cout << "Freeing Card Memory" << endl;
}

//string Card::printCard() {
//	return "Here are the cards detail. Card type: " << type << endl;
//}

std::ostream& operator<<(ostream& os, const Card& data)
{
	os << data.type;
	return os;
}

Bomb::Bomb() {
	type = "Bomb Card";
}

//Bomb::Bomb(std::string t) {
//	type = t;
//}



Reinforcement::Reinforcement() {
	type = "Reinforcement Card";
}

//Reinforcement::Reinforcement(std::string t) {
//	type = t;
//}


Blockade::Blockade() {
	type = "Blockade Card";
}

//Blockade::Blockade(std::string t) {
//	type = t;
//}


Airlift::Airlift() {
	type = "Airlift Card";
}

//Airlift::Airlift(std::string t) {
//	type = t;
//}

Diplomacy::Diplomacy() {
	type = "Diplomacy Card";
}

//Diplomacy::Diplomacy(std::string t) {
//	type = t;
//}

//std::vector<Card>& Deck::GetVect()
//{
//	return Cards_in_Deck;
//}

//std::vector<Card> Cards_in_Deck = generateDeck();


void Deck::generateDeck() {
	//generating deck

	do {

		game_deck.push_back(new Card());
		game_deck.push_back(new Bomb());
		game_deck.push_back(new Reinforcement());
		game_deck.push_back(new Blockade());
		game_deck.push_back(new Diplomacy());
		game_deck.push_back(new Airlift());
	} while (game_deck.size() < 52);
}


