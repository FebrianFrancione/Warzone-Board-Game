#include "Cards.h"
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


std::ostream& operator<<(ostream& os, const Card& data)
{
	os << data.type;
	return os;
}

Bomb::Bomb() {
	type = "Bomb Card";
}


Reinforcement::Reinforcement() {
	type = "Reinforcement Card";
}

Blockade::Blockade() {
	type = "Blockade Card";
}


Airlift::Airlift() {
	type = "Airlift Card";
}

Diplomacy::Diplomacy() {
	type = "Diplomacy Card";
}


//Hand::Hand() {
//	std::vector<Card> hand;
//}
//
//Hand::Hand(const Hand& otherHand)
//{
//	for (int i = 0; i <= 7; i++) {
//		hand.push_back(otherHand.hand[i]);
//	}
//}

Deck::Deck() {

}
std::vector<Card*> Deck::generateDeck(std::vector <Card*> playing_deck, int max_deck_size) {
	//generating deck
	while (playing_deck.size() <= max_deck_size) {

		playing_deck.push_back(new Bomb());

		playing_deck.push_back(new Reinforcement());

		playing_deck.push_back(new Blockade());

		playing_deck.push_back(new Diplomacy());

		playing_deck.push_back(new Airlift());


		/*	if (max_deck_size - playing_deck.size() < 5) {
				extra = max_deck_size - playing_deck.size();
				switch (extra) {
				case 1:
					playing_deck.push_back(new Bomb());

					playing_deck.push_back(new Reinforcement());

					playing_deck.push_back(new Blockade());

					playing_deck.push_back(new Diplomacy());
				case 2:
					playing_deck.push_back(new Bomb());

					playing_deck.push_back(new Reinforcement());

					playing_deck.push_back(new Blockade());
				case 3:
					playing_deck.push_back(new Bomb());

					playing_deck.push_back(new Reinforcement());
				case 4:
					playing_deck.push_back(new Bomb());
				}
			}*/



	}
	while (playing_deck.size() > max_deck_size) {
		playing_deck.pop_back();
	}


	return playing_deck;
}

//void Draw(std::vector <Card*> playing_deck) {
//	//shuffle the cards
//	for (int k = 0; k < playing_deck.size(); k++) {
//		cout << playing_deck[k];
//	}
//
//	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//	std::shuffle(std::begin(playing_deck), std::end(playing_deck), std::default_random_engine(seed));
//
//	for (int k = 0; k < playing_deck.size(); k++) {
//		cout << playing_deck[k];
//	}
//
//	int n = playing_deck.size();
//	/*hand.push_back(playing_deck[n - 1]);*/
//	cout << hand[1];
//	playing_deck.pop_back();
//
//
//
//	//int n = playing_deck.size();
//	//hand.push_back(territories[n - 1]);
//	//territories.pop_back();
//}