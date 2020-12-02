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

	void toAttack();
	void toDefend();
	void toDeploy();
	void printPlayerTerritories();
	void issueOrder();
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

	//validation functions on user input
	bool validTerritoryDeploy(string input);
	bool validReinforceAmount(string input);
	bool validOrder(string input);
  PlayerStrategy * playerstrat;
};
