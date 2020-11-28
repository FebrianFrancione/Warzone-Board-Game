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

	Card() {
		this.type = "";
	}

	Card(string cardName) {
		this.type{ cardName };
	}

private:
	string type;

};

//class Deck {
//
//};