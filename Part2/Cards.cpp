#include "Cards.h"
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

Card::Card() {
	type = "no-type card";
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
	cout << "Freeing Card Memory";
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
	type = "Bomb";
}

Bomb::Bomb(std::string t) {
	type = t;
}


//
//Reinforcement::Reinforcement() {
//	type = "Reinforcement";
//}
//Blockade::Blockade() {
//	type = "Blockade";
//}
//
//Airlift::Airlift() {
//	type = "Airlift";
//}
//
//Diplomacy::Diplomacy() {
//	type = "Diplomacy";
//}


//Deck::Deck() {
//	//generating deck
//
//	do {
//
//		game_deck.push_back(Card());
//		game_deck.push_back(Bomb());
//		game_deck.push_back(Reinforcement());
//		game_deck.push_back(Blockade());
//		game_deck.push_back(Diplomacy());
//		game_deck.push_back(Airlift());
//	} while (game_deck.size() < 52);
//
//}


