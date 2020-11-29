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

void Draw(Card hand[], std::vector <Card*> playing_deck) {
	//shuffle the players and set playerTurn ID
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(std::begin(playing_deck), std::end(playing_deck), std::default_random_engine(seed));

}