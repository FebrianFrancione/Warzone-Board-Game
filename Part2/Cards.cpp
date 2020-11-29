#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "cards.h"
#include "player.h"
#include "Territory.h"

Card::Card()
{
	//assigns typeAssign a random integer. type is determined based on typeAssign.
	typeAssign = rand() % 5 + 1;

	switch (typeAssign)
	{
	case 1:
		type = "Bomb";
		break;

	case 2:
		type = "Reinforcement";
		break;

	case 3:
		type = "Blockade";
		break;

	case 4:
		type = "Airlift";
		break;

	case 5:
		type = "Diplomacy";
		break;

	default:
		break;
	}
}

//parameterized constructor
Card::Card(int t)
{
	type = t;
}

//copy constructor
Card::Card(Card& otherCard)
{
	type = otherCard.getType();
	typeAssign = otherCard.getTypeAssign();

}

//retrieves typeAssign
int Card::getTypeAssign()
{
	return typeAssign;
}

//sets typeAssign to the passed value
void Card::setTypeAssign(int usrTypeAssign)
{
	typeAssign = usrTypeAssign;
}

//retrieves type
string Card::getType()
{
	return type;
}

//sets type to the passed value
void Card::setType(std::string usrType)
{
	type = usrType;
}

//exeutes a card's order and puts it back into the deck
void Card::play(Card deck[], Player player1, Player player2, Territory thisTerr, Territory otherTerr)
{
	//stores whether or not a card has been put back into the deck
	bool cardCheck = false;

	int troopsRemain = otherTerr.getArmies() / 2;

	int troopReinforce = thisTerr.getArmies() * 3;

	int numOfTroops = thisTerr.getArmies() + 1;

	Territory neutral;

	//performs an order based on the type of card 
	switch (typeAssign) {

		//halves the troops of the other player
	case 1:

		otherTerr.setArmies(troopsRemain);

		if (otherTerr.getArmies() < 0) {
			otherTerr.setArmies(0);
		}

		cout << "\n" << otherTerr.getName() << " now has " << otherTerr.getArmies() << " army units.\n";
		break;

		//adds 5 army units to the other territory
	case 2:

		otherTerr.addArmies(5);
		cout << "\n" << otherTerr.getName() << " now has " << otherTerr.getArmies() << " army units.\n";

		break;

		//multiplies the territory's army units and sets the owner to neutral
	case 3:

		thisTerr.setArmies(troopReinforce);
		thisTerr.setOwner(neutral.getOwner());

		cout << "\n" << thisTerr.getName() << " now has " << thisTerr.getArmies() << " army units, and is now neutral.\n";
		break;

		//transfers a specfied number of armies from one territory to another
	case 4:

		while (thisTerr.getArmies() < numOfTroops) {
			cout << "Please enter the number of troops you wish to move: ";
			cin >> numOfTroops;

			if (thisTerr.getArmies() < numOfTroops) {
				cout << "\nYou canot move that many troops from this territory, please enter a valid number.\n ";
			}

		}

		thisTerr.setArmies(thisTerr.getArmies() - numOfTroops);
		otherTerr.addArmies(numOfTroops);

		cout << "\n" << thisTerr.getName() << " now has " << otherTerr.getArmies() << " army units.\n" << "\n" << otherTerr.getName() << " now has " << otherTerr.getArmies() << " army units.\n";
		break;

		//sets the playerAttack value to true, making them unable to attack
	case 5:

		player2.setPlayerAttack(true);

		cout << "\n" << player2.getName() << " is now unable to attack.\n";
		break;

	default:
		break;
	}

	//iterates through the deck until an empty card object is found
	for (int i = 0; i < 52; i++) {

		if (deck[i].getType().empty() == true && cardCheck == false) {

			//puts the card back into the deck and removes the card from the player's hand
			deck[i].setType(type);
			deck[i].setTypeAssign(typeAssign);

			type = "";
			typeAssign = 0;
		}
	}
}

//default constructor
Deck::Deck()
{
	gameDeck[52];

	//creates a unique Card object for each element in the array
	for (int i = 0; i < 52; i++) {

		gameDeck[i] = Card();

	}
}

//copy constructor
Deck::Deck(Deck& otherDeck)
{

	int deckSize = otherDeck.getDeckSize();
	gameDeck[deckSize];

	for (int i = 0; i < deckSize; i++) {
		gameDeck[i] = otherDeck.gameDeck[i];

	}

}

//returns the deckSize value
int Deck::getDeckSize()
{
	return deckSize;
}

//sets the value of deckSize to the passed value
void Deck::setDeckSize(int usrDeckSize)
{
	deckSize = usrDeckSize;
}

//draws a card form the deck and places it into the passed card array
void Deck::draw(Card hand[])
{
	//stores the index of the card taken from the deck
	int deckIndex;
	//stores whether or not a card was drawn
	bool cardCheck = false;

	for (int i = 0; i < 7; i++) {

		//checks for an empty card object in the passed array
		if (hand[i].getType().empty() == true && cardCheck == false) {


			do {

				//chooses a random index to take a card from 
				int cardIndex = rand() % 52;

				//only attempts to draw a card if the index isn't empty
				if (gameDeck[cardIndex].getType().empty() != true) {

					//adds the card to the palyer's hand, sets cardCheck to true, and records the index of the taken card 
					hand[i] = gameDeck[cardIndex];
					cardCheck = true;
					deckIndex = cardIndex;
					cout << "Card has been added\n";
					break;
				}
				//loops until a card has been drawn
			} while (cardCheck == false);
		}

		//if the player's hand is full, no cards are drawn
		if (i == 6 && cardCheck == false) {
			cout << "Player's hand is full, no cards were added.\n";
		}

	}

	//if a card was drawn, that card is removed from the deck
	if (cardCheck == true) {

		gameDeck[deckIndex].setType("");
		gameDeck[deckIndex].setTypeAssign(0);

	}


}

//default constructor
Hand::Hand()
{
	playerHand[7];
	for (int i = 0; i < 7; i++) {
		playerHand[i].setType("");
		playerHand[i].setTypeAssign(0);
	}
}

//copy constructor
Hand::Hand(const Hand& otherHand)
{
	playerHand[7];
	for (int i = 0; i < 7; i++) {
		playerHand[i] = otherHand.playerHand[i];
	}
}
//#include "Cards.h"
//#include "Player.h"
//
//
//Card::Card() {
//	type = "Default Card";
//}
//
//Card::Card(std::string t) {
//	type = t;
//}
//
////copy constructor
//Card::Card(const Card& obj) {
//	// body of constructor
//	cout << "copy constructor allocating ptr" << endl;
//	type = obj.type; // copy the value using deep copy
//}
//
//Card::~Card(void) {
//	cout << "Freeing Card Memory" << endl;
//}
//
//
//std::ostream& operator<<(ostream& os, const Card& data)
//{
//	os << data.type;
//	return os;
//}
//
//Bomb::Bomb() {
//	type = "Bomb Card";
//}
//
//
//Reinforcement::Reinforcement() {
//	type = "Reinforcement Card";
//}
//
//Blockade::Blockade() {
//	type = "Blockade Card";
//}
//
//
//Airlift::Airlift() {
//	type = "Airlift Card";
//}
//
//Diplomacy::Diplomacy() {
//	type = "Diplomacy Card";
//}
//
//
////Hand::Hand() {
////	std::vector<Card> hand;
////}
////
////Hand::Hand(const Hand& otherHand)
////{
////	for (int i = 0; i <= 7; i++) {
////		hand.push_back(otherHand.hand[i]);
////	}
////}
//
//Deck::Deck() {
//
//}
//std::vector<Card*> Deck::generateDeck(std::vector <Card*> playing_deck, int max_deck_size) {
//	//generating deck
//	while (playing_deck.size() <= max_deck_size) {
//
//		playing_deck.push_back(new Bomb());
//
//		playing_deck.push_back(new Reinforcement());
//
//		playing_deck.push_back(new Blockade());
//
//		playing_deck.push_back(new Diplomacy());
//
//		playing_deck.push_back(new Airlift());
//
//
//		/*	if (max_deck_size - playing_deck.size() < 5) {
//				extra = max_deck_size - playing_deck.size();
//				switch (extra) {
//				case 1:
//					playing_deck.push_back(new Bomb());
//
//					playing_deck.push_back(new Reinforcement());
//
//					playing_deck.push_back(new Blockade());
//
//					playing_deck.push_back(new Diplomacy());
//				case 2:
//					playing_deck.push_back(new Bomb());
//
//					playing_deck.push_back(new Reinforcement());
//
//					playing_deck.push_back(new Blockade());
//				case 3:
//					playing_deck.push_back(new Bomb());
//
//					playing_deck.push_back(new Reinforcement());
//				case 4:
//					playing_deck.push_back(new Bomb());
//				}
//			}*/
//
//
//
//	}
//	while (playing_deck.size() > max_deck_size) {
//		playing_deck.pop_back();
//	}
//
//
//	return playing_deck;
//}
//
////void Deck::Draw(std::vector <Card*> deck, std::vector <Card*> player_deck) {
////	//shuffle the cards
////	for (int k = 0; k < deck.size(); k++) {
////		cout << 
////	}
////
////	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
////	std::shuffle(std::begin(deck), std::end(deck), std::default_random_engine(seed));
////
////	for (int k = 0; k < deck.size(); k++) {
////		cout << deck.at(k);
////	}
////
////	int n = deck.size();
////	/*hand.push_back(playing_deck[n - 1]);*/
////	cout << player_deck.at(n);
////	deck.pop_back();
////
////
////
////	//int n = playing_deck.size();
////	//hand.push_back(territories[n - 1]);
////	//territories.pop_back();
////}