#include <iostream>
#include <cstdio>
#include "Cards.h"
#include "player.h"
#include "Territory.h"
#include "Continent.h"
using namespace std;

int main() {

	cout << "Building Deck...\n";

	Deck deck;

	cout << "\nDisplaying all cards in the deck...\n";

	for (int i = 0; i < 52; i++) {
		std::string cardType = deck.gameDeck[i].getType();
		cout << "\n" + cardType;

	}

	cout << "\nCreating empty hand for player 1 and drawing 3 cards...\n";

	Hand hand1;

	for (int i = 0; i < 7; i++)
	{
		deck.draw(hand1.playerHand);

	}


	cout << "\nDisplaying player 1's hand...\n";

	for (int i = 0; i < 7; i++) {
		std::string cardType = hand1.playerHand[i].getType();
		cout << "\n" + cardType;
	}

	cout << "\nDisplaying all cards in the deck...\n";

	for (int i = 0; i < 52; i++) {
		std::string cardType = deck.gameDeck[i].getType();
		cout << "\n" + cardType;

	}

	cout << "\nPlaying cards in this order: 3, 2, 5, 4, 1, 7, 6\n";

	Continent cont("Europe", 12);
	Player player1("Player 1");
	Player player2("Player 2");
	Territory terr1_1("Sweden", cont, 12, 0);
	Territory terr1_2("Germany", cont, 20, 1);
	Territory terr2_1("Spain", cont, 18, 2);
	Territory terr2_2("Netherlands", cont, 11, 3);


	hand1.playerHand[2].play(deck.gameDeck, player1, player2, terr1_1, terr2_2);
	hand1.playerHand[1].play(deck.gameDeck, player2, player1, terr2_1, terr1_2);
	hand1.playerHand[4].play(deck.gameDeck, player1, player2, terr1_2, terr2_1);
	hand1.playerHand[3].play(deck.gameDeck, player1, player2, terr1_1, terr1_2);
	hand1.playerHand[0].play(deck.gameDeck, player2, player1, terr2_2, terr1_1);
	hand1.playerHand[6].play(deck.gameDeck, player1, player2, terr1_2, terr2_2);
	hand1.playerHand[5].play(deck.gameDeck, player1, player2, terr1_1, terr2_2);

	cout << "\nDisplaying all cards in the deck...\n";

	for (int i = 0; i < 52; i++) {
		std::string cardType = deck.gameDeck[i].getType();
		cout << "\n" + cardType;

	}

	cout << "\nDisplaying player 1's hand...\n";

	for (int i = 0; i < 7; i++) {
		std::string cardType = hand1.playerHand[i].getType();
		cout << "\n" + cardType;
	}


	std::getchar();
	std::getchar();
	return 0;
}
//#include "Cards.h"
//#include "Player.h"
//
//
//
//int main() {
//
//	Player player1{ "Player1", 0, 0 };
//
//	Deck deck;
//	std::vector <Card*> playing_deck;
//	int max_deck_size = 52;
//	playing_deck = deck.generateDeck(playing_deck, max_deck_size);
//	cout << playing_deck.size() << endl;
//
//	for (int i = 0; i < playing_deck.size(); i++) {
//		cout << playing_deck[i]->type << "-";
//	}
//	cout << "__________________________" << endl;
//
//	std::vector<Card*> player1_hand;
//
//	cout << "Player1 hand size: " << player1_hand.size();
//	//deck.Draw(playing_deck, player1_hand);
//
//
//}
//
//
//
////Hand cards_in_hand;
////cards_in_hand.hand.push_back();
////for (int i = 0; i < sizeof(cards_in_hand); i++) {
//
////}
//
