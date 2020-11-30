/*
#include "Cards.h"
#include "Player.h"



int main() {

	Player player1{ "Player1", 0, 0 };

	std::vector<Card*> player1_hand;

	Deck playing_deck;
*/
/*	std::vector <Card*> hand;*//*

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
    player1_hand.push_back(new Bomb());
    std::vector<Card*> player2_hand{new Bomb(), new Reinforcement(), new Blockade(), new Airlift(), new Diplomacy()};
    player1_hand[0]->Play();

    cout << "Player 2 printing pLay on cards: " << endl;
    for (auto & i : player2_hand) {
        i->Play();
    }
}


*/
