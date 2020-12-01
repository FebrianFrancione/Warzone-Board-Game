#pragma once

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "Cards.h"

using namespace std;

class Cards;

//Player Class
class Player
{
public:
    Player();


//Constructors

	Player(std::string n, int id, int army);

	//Player(std::string n, int id, int army, list<string> t, int h);

	//copy
	Player(const Player& p);
Player(list<string> t, int h);

	~Player();

	//methods to attack, defend, and issue orders
	void toAttack();
	void toDefend();
	void issueOrder();

	void setName(string n);
	string getName();

	void setPlayerTurnId(int id);
	int getPlayerTurnId();

	void setPlayerArmySize(int army);
	int getPlayerArmySize();

vector<string> playerTerritories;

	list<string> territories;
    std::vector<Cards*> player_hand;
private:
	int armySize;
	std::string name;
	int playerTurnId;

	int hand;
	list<string> orders;
};
