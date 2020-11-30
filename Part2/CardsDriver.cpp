#include "Cards.h"
#include "Player.h"



int main() {

	Player player1{ "Player1", 0, 0 };

	std::vector<Card*> player1_hand;

	Deck playing_deck;
/*	std::vector <Card*> hand;*/
	playing_deck.generateDeck();
	cout << playing_deck.deck.size() << endl;

	for (auto & i : playing_deck.deck) {
		cout << i->type << "-";
	}
	cout << endl <<  "___________________________________________" << endl;

	playing_deck.shuffle();
	cout << "Shuffled deck: " << endl;

	player1_hand = playing_deck.Draw(player1_hand);
	cout << player1_hand.size() << ": " << player1_hand[0]->type << " deck: " << playing_deck.deck.size() << endl;

    player1_hand = playing_deck.Draw(player1_hand);
    cout << player1_hand.size() << ": " << player1_hand[0]->type << " deck: " << playing_deck.deck.size() << endl;
 /*   for (auto & i : playing_deck.deck) {
        cout << i->type << "-";
    }*/

/*	std::vector<Card*> player1_hand;
	cout << "Player1 from driver hand size: " << player1_hand.size();
	playing_deck.shuffle();
	player1_hand = playing_deck.Draw(playing_deck, player1_hand);
    cout << "Player1 hand size: " << player1_hand.size();
    player1_hand = playing_deck.Draw(playing_deck, player1_hand);
    cout << "Player1 hand size: " << player1_hand.size();*/

}


//Hand cards_in_hand;
//cards_in_hand.hand.push_back();
//for (int i = 0; i < sizeof(cards_in_hand); i++) {

//}

