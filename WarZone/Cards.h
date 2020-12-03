#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <chrono> 
#include <random>
#include <algorithm>
#include "Player.h"
#include "Map.h"
#include "MapLoader.h"

#include <list>


/*#include "Territory.h"*/
class Cards {

public:
    //Card class will be inherited by the other subCards
	std::string type;
	//Card methods need to be here
	Cards();
	Cards(std::string t);//simple constructor

	Cards(const Cards& obj);//copy
	~Cards();//destructor
	/*void play(Player player1, Player player2); */// creates an order and adds to list of orders
    virtual void Play();
	friend std::ostream& operator<< (std::ostream& out, const Cards& data);
};


//inheritance class for cards
class BombCard : public Cards {
public:
    BombCard();
	//Bomb(std::string t);
	/*Play(Player player1, Player player2, Territory thisTerr, Territory otherTerr);*/
     virtual void Play();
};


class ReinforcementCard : public Cards {
public:
    ReinforcementCard();
	//Reinforcement(std::string t);
    /*Play(Player player1, Player player2, Territory thisTerr, Territory otherTerr);*/
    virtual void Play();
private:
};


class BlockadeCard : public Cards {
public:
	BlockadeCard();
	//Blockade(std::string t);
    /*Play(Player player1, Player player2, Territory thisTerr, Territory otherTerr);*/
  virtual void Play();
private:


};

class AirliftCard : public Cards {
public:
    AirliftCard();
	//Airlift(std::string t);
    /*Play(Player player1, Player player2, Territory thisTerr, Territory otherTerr);*/
    virtual void Play();
private:


};

class DiplomacyCard : public Cards {
public:
    DiplomacyCard();
	//Diplomacy(std::string t);
    /*Play(Player player1, Player player2, Territory thisTerr, Territory otherTerr);*/
    virtual void Play();
private:

};

//calss of Decks use to store Cards
class Deck {
public:
	//aiming ot h

	Deck();
	Deck(Deck& otherDeck);
	~Deck();
	//vector of Card Objects can hold any of the implemented subClasses of Cards
    std::vector<Cards*> deck;
    void shuffle();
	/*void draw(Card hand[]);*/
	void generateDeck();

    std::vector<Cards*> Draw(std::vector <Cards*> player_deck);
};
