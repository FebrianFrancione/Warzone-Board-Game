#pragma once
#include "Cards.h"
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"



class Card {

public:
	std::string type;
	//Card methods need to be here
	Card();
	Card(std::string t);//simple constructor

	Card(const Card& obj);//copy
	~Card();//destructor
	/*void play(Deck deck, Player player1, Player player2);*/ // creates an order and adds to list of orders

	friend std::ostream& operator<< (std::ostream& out, const Card& data);
};


//inheritance class for cards
class Bomb : public Card {
public:
	Bomb();
	Bomb(std::string t);
};



//class Reinforcement : public Card {
//public:
//	Reinforcement();
//private:
//
//
//};
//class Blockade : public Card {
//public:
//	Blockade();
//private:
//
//
//};
//class Airlift : public Card {
//public:
//	Airlift();
//private:
//
//
//};
//class Diplomacy : public Card {
//public:
//	Diplomacy();
//private:
//
//};

//class Hand {
//public:
//	vector<Card> hand;
//	int max_cards_in_hand;
//};

//class Deck {
//public:
//	//aiming ot h
//	vector<Card> game_deck;
//	Deck();
//	Deck(Deck& otherDeck);
//	void draw(Card hand[]);
//
//	void generateDeck();
//	/* draw(Player player);*/
//	vector<Card> Cards_in_Deck;
//private:
//	/*int deck_size;*/
//
//};
