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


Hand::~Hand(void) {
	cout << "Freeing Hand Memory" << endl;
}

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

void Deck::Draw(std::vector <Card*> deck, std::vector <Card*> player_deck) {
	//shuffle the cards
	for (size_t k = 0; k < deck.size(); k++) {
		cout << *deck.at(k);
	}
	cout << "_______________________________________________" << endl;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(std::begin(deck), deck.end(), std::default_random_engine(seed));

	for (int k = 0; k < deck.size(); k++) {
		cout << *deck.at(k);
	}

	int n = deck.size();
	/*hand.push_back(playing_deck[n - 1]);*/
	cout << player_deck.at(n);
	deck.pop_back();
}
Deck::~Deck(void) {
	cout << "Freeing Deck Memory" << endl;
}