#pragma once
#include "Cards.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono> 
#include <random>
#include <algorithm>
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
	//Bomb(std::string t);
};

class Reinforcement : public Card {
public:
	Reinforcement();
	//Reinforcement(std::string t);
private:


};


class Blockade : public Card {
public:
	Blockade();
	//Blockade(std::string t);
private:


};

class Airlift : public Card {
public:
	Airlift();
	//Airlift(std::string t);
private:


};

class Diplomacy : public Card {
public:
	Diplomacy();
	//Diplomacy(std::string t);
private:

};

class Hand {

public:
	Hand();
	Hand(const Hand& otherHand);
	~Hand();
private:
	vector<Card*> hand;
};

class Deck {
public:
	//aiming ot h

	Deck();
	Deck(Deck& otherDeck);
	~Deck();
	/*void draw(Card hand[]);*/
	std::vector<Card*> generateDeck(std::vector <Card*> playing_deck, int max_deck_size);

	void Draw(std::vector <Card*> player_deck, std::vector <Card*> deck);

private:


};
