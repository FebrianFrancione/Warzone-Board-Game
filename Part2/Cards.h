#pragma once
#include "Cards.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono> 
#include <random>
#include <algorithm>
#include "Player.h"
#include <list>

/*#include "Territory.h"*/
class Cards {

public:
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

/*class Hand {

public:
	Hand();
	Hand(const Hand& otherHand);
	~Hand();
private:
	vector<Card*> hand;
};*/


class Deck {
public:
	//aiming ot h

	Deck();
	Deck(Deck& otherDeck);
	~Deck();
    std::vector<Cards*> deck;
    void shuffle();
	/*void draw(Card hand[]);*/
	void generateDeck();

    std::vector<Cards*> Draw(std::vector <Cards*> player_deck);
};



/*
class Player
{
public:
    Player();
*/
/* extern settings_t ESPdata;*//*


//Constructors

    Player(std::string n, int id, int army);

    //Player(std::string n, int id, int army, list<string> t, int h);

    //copy
    Player(const Player& p);
    */
/*Player(list<string> t, int h);*//*

    ~Player();

    //methods to attack, defend, and issue orders
    void toAttack();
    void toDefend();
    void issueOrder();

    void setName(std::string n);
    std::string getName();

    void setPlayerTurnId(int id);
    int getPlayerTurnId();

    void setPlayerArmySize(int army);
    int getPlayerArmySize();

    */
/*vector<string> playerTerritories;*//*

    std::list<std::string> territories;
    std::vector<Cards*> player_hand;
    Cards* cards = new Cards;

private:
    int armySize;
    std::string name;
    int playerTurnId;

    int hand;
    std::list<std::string> orders;
};
*/
