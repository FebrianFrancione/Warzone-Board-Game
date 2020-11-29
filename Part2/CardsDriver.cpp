#include "Cards.h"


int main() {

	Card card("freedom");
	cout << card;
	Bomb card2;
	cout << card2 << endl;
	Reinforcement card3;
	cout << card3 << endl;
	Blockade card4;
	cout << card4 << endl;
	Airlift card5;
	cout << card5 << endl;

	Deck deck;

	deck.generateDeck();
	deck.game_deck.size();

	/*for (int j = 0; j < 52; j++) {
		cout << Cards_in_Deck[j]. << endl;
	}*/



}


//Hand cards_in_hand;
//cards_in_hand.hand.push_back();
//for (int i = 0; i < sizeof(cards_in_hand); i++) {

//}

