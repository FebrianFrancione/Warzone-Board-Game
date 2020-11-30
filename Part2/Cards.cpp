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
	type = "Bomb Card ";
}


Reinforcement::Reinforcement() {
	type = "Reinforcement Card ";
}

Blockade::Blockade() {
	type = "Blockade Card ";
}


Airlift::Airlift() {
	type = "Airlift Card ";
}

Diplomacy::Diplomacy() {
	type = "Diplomacy Card ";
}


/*Hand::~Hand(void) {
	cout << "Freeing Hand Memory" << endl;
}*/

Deck::Deck() {

}
void Deck::generateDeck() {
    int max_deck_size = 52;
	//generating deck
	std::vector<Card*> playing_deck;
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
	deck = playing_deck;
	cout << "Deck generated" << endl;
}

std::vector<Card*> Deck::Draw(std::vector <Card*> player_deck) {

	//this causes issues in the code
	int n = deck.size();
	cout << "n: " << n << endl;
    player_deck.push_back(deck[n-1]);

    cout << "Player deck size: " << player_deck.size() << endl;
    cout << "Player deck card: " << player_deck.at(0)->type << endl;
    deck.pop_back();

    for(int i = 50 ;i < deck.size(); i++){
        cout << deck[i]->type;
    }
    cout << endl << "Deck size: " << deck.size() << endl;
    return player_deck;
}

void Deck::shuffle(){
    //shuffle the card
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(deck), deck.end(), std::default_random_engine(seed));

    cout <<endl<< "Deck has been shuffled! " << endl;

    for(int i = 50 ;i < deck.size(); i++){
        cout << deck[i]->type;
    }

    cout << endl << "_______________________________________________" << endl;
}

Deck::~Deck(void) {
	cout << "Freeing Deck Memory" << endl;
}

