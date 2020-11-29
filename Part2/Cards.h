#pragma once
#include <string>
#include <list>
#include <vector>
#include "player.h"
#include "Territory.h"
#include "Continent.h"

class Card {

public:


	//Constructors for the Card class
	Card();
	Card(int t);
	Card(Card& otherCard);

	//getter and setter methods for both private values
	int getTypeAssign();
	void setTypeAssign(int usrTypeAssign);

	std::string getType();
	void setType(std::string usrType);


	void play(Card deck[], Player player1, Player player2, Territory thisTerr, Territory otherTerr);

private:

	//stores the value that determines card type
	int typeAssign;
	//stores the type name of the card
	std::string type;


};

class Deck {

public:

	//stores an array of cards to be used as the deck
	Card gameDeck[52];

	//constructors for the Deck class
	Deck();
	Deck(Deck& otherDeck);

	//geter and setter methods for the deckSize value
	int getDeckSize();
	void setDeckSize(int usrDeckSize);

	//draws a card from the deck and puts it in a Hand object
	void draw(Card hand[]);

private:

	//stores the size of the deck 
	int deckSize;





};

class Hand {

public:

	//creates an array of cards that acts as a player's hand
	Card playerHand[7];

	//constructors for the Hand class
	Hand();
	Hand(const Hand& otherHand);

private:


};

//#pragma once
//#include "Cards.h"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <chrono> 
//#include <random>
//#include <algorithm>
//#include "Player.h"
//
//
//
//
//class Card {
//
//public:
//	std::string type;
//	//Card methods need to be here
//	Card();
//	Card(std::string t);//simple constructor
//
//	Card(const Card& obj);//copy
//	~Card();//destructor
//	/*void play(Deck deck, Player player1, Player player2);*/ // creates an order and adds to list of orders
//	friend std::ostream& operator<< (std::ostream& out, const Card& data);
//};
//
//
////inheritance class for cards
//class Bomb : public Card {
//public:
//	Bomb();
//	//Bomb(std::string t);
//};
//
//class Reinforcement : public Card {
//public:
//	Reinforcement();
//	//Reinforcement(std::string t);
//private:
//
//
//};
//
//
//class Blockade : public Card {
//public:
//	Blockade();
//	//Blockade(std::string t);
//private:
//
//
//};
//
//class Airlift : public Card {
//public:
//	Airlift();
//	//Airlift(std::string t);
//private:
//
//
//};
//
//class Diplomacy : public Card {
//public:
//	Diplomacy();
//	//Diplomacy(std::string t);
//private:
//
//};
//
////class Hand {
////
////public:
////	Hand();
////	Hand(const Hand& otherHand);
////private:
////	vector<Card*> hand;
////};
//
//class Deck {
//public:
//	//aiming ot h
//
//	Deck();
//	Deck(Deck& otherDeck);
//	/*void draw(Card hand[]);*/
//	std::vector<Card*> generateDeck(std::vector <Card*> playing_deck, int max_deck_size);
//
//	/*oid Draw(std::vector <Card*> player_deck, std::vector <Card*> deck);*/
//
//private:
//
//
//};
