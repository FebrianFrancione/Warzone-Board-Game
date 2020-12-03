#pragma once

#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Cards.h"
#include "Map.h"
#include "Orders.h"
#include "PlayerStrategies.h"

using namespace std;

class Cards;
class Territory;
class PlayerStrategy;
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
    void setPlayerStrategy(PlayerStrategy* playerstrat);
	//Play methods
	void toAttack();
	void toDefend();
	void toDeploy();
	void issueOrder();
	//pwetty pwint
	void printPlayerTerritories();
	//Orders
	void executeOrder(int i);
	Order* getFirstOrder();
	int numberOfOrders();
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
	//This holds the pointers directly to the map
	//But only its own territories
	vector<Territory*> territories;
	//Cards
	std::vector<Cards*> player_hand;
	//---
	//validation functions on user input
	//---
	//valid territory to deploy to
	bool validTerritoryDeploy(string input);
	//Validates whether the territory belongs to the player
	bool validTerritoryDefend(string selection);
	//Valid target to transfer to
	bool validTerritoryTransferTarget(string selection, Territory* origin);
	//Validate whether the territory belongs to the player, and has an attack target
	bool validTerritoryAttack(string selection);
	//Validate whether the target of an attack is the neighbour of the origin
	bool validTerritoryAttackTarget(string selection, Territory* origin);
	//Valid amount of troops to advance with (attack or transfer)
	bool validAdvanceAmount(string amount, Territory* origin);
	//Valid reinforcment troop count for deploy
	bool validReinforceAmount(string input);
	//
	bool validOrder(string input);
	
private:
	int armySize;
	std::string name;
	int playerTurnId;
	int hand;
	OrdersList* orders;
	//I call this one the needle threader: the pointer points directly to the map
	Map* gameMap;

  PlayerStrategy * playerstrat;
};
