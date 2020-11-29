#include "Cards.h"
#include "Player.h"



int main() {

	Player player1{ "Player1", 0, 0 };

	Deck deck;
	std::vector <Card*> playing_deck;
	int max_deck_size = 52;
	playing_deck = deck.generateDeck(playing_deck, max_deck_size);
	cout << playing_deck.size() << endl;

	for (int i = 0; i < playing_deck.size(); i++) {
		cout << playing_deck[i]->type << "-";
	}
	cout << "___________________________________________" << endl;

	std::vector<Card*> player1_hand;

	cout << "Player1 hand size: " << player1_hand.size();
	deck.Draw(playing_deck, player1_hand);


}



//Hand cards_in_hand;
//cards_in_hand.hand.push_back();
//for (int i = 0; i < sizeof(cards_in_hand); i++) {

//}

