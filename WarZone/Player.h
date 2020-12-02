#pragma once

#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Cards.h"
#include "Map.h"
#include "Orders.h"

using namespace std;

class Cards;
class Territory;

//Player Class
class Player
{
public:
	//Constructors
    Player();
	Player(std::string n, int id, int army, Map* needle);
	//Player(std::string n, int id, int army, list<string> t, int h);
	//copy constructor
	Player(const Player& p);
	//Player(list<string> t, int h);
	//Destructor
	~Player();
	//methods to attack, defend, and issue orders
	void toAttack();
	void toDefend();
	void issueOrder(int orderType, Order* order);
	//Name accessors
	void setName(string n);
	string getName();
	//Player turn accessor
	void setPlayerTurnId(int id);
	int getPlayerTurnId();
	//Reinforcement pool
	void setPlayerArmySize(int army);
	int getPlayerArmySize();
	void addReinforcements(int r);
	void subtractReinforcements(int r);
    //vector<string> playerTerritories;
	//list<string> territories;
	//vector<int> territoriesId;
	vector<Territory*> territories;

	//Cards
    std::vector<Cards*> player_hand;
private:
	int armySize;
	std::string name;
	int playerTurnId;
	int hand;
	OrdersList* orders;
	//I call this one the needle threader: the pointer points directly to the map
	Map* gameMap;
};
