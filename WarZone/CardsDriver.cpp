/*
#include "Cards.h"
#include "Player.h"

using namespace std;

int main() {

	Player player1{ "Player1", 0, 0 };
*/
/*    player1.player_hand;

	player1.player_hand.push_back(new BombCard());
	cout << player1.player_hand.size();*//*

player1.player_hand.push_back(new BombCard());
cout << " Hand: " << player1.player_hand.at(0)->type;



    std::vector<Cards*> player1_hand;
	Deck playing_deck;
	std::vector <Cards*> hand;

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
    player1_hand.push_back(new BombCard());
    std::vector<Cards*> player2_hand{new BombCard(), new ReinforcementCard(), new BlockadeCard(), new AirliftCard(), new DiplomacyCard()};
    player1_hand[0]->Play();

  */
/*  cout << "Player 2 printing pLay on cards: " << endl;
    for (auto & i : player2_hand) {
        i->Play();
    }*//*

}


*/
