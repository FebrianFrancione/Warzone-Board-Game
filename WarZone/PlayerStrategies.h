#pragma once

#include "Map.h"
#include "Player.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Player;

class PlayerStrategy {
public:
/*    virtual string toAttack() = 0;
    virtual string toDefend() = 0;
    virtual string issueOrder() = 0;*/
	
	virtual void toAttack(Player* player, Map* gameMap, Territory* origin, Territory* destination) = 0;
	virtual void toDefend(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders) = 0;
	virtual void toDeploy(Player* thePlayer, Map* gameMap) = 0;
	virtual void issueOrder(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders) = 0;
};

class HumanPlayerStrategy : public PlayerStrategy{
public:
	void toAttack(Player* player, Map* gameMap, Territory* origin, Territory* destination);
	void toDefend(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders);
	void toDeploy(Player* thePlayer, Map* gameMap);
    void issueOrder(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders);
};

class AggressivePlayerStrategy : public PlayerStrategy {
public:
    void toAttack(Player* player, Map* gameMap, Territory* origin, Territory* destination);
    void toDefend(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders);
    void toDeploy(Player* player, Map* gameMap);
    void issueOrder(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders);
};

class BenevolentPlayerStrategy : public PlayerStrategy {
public:
    void toAttack(Player* player, Map* gameMap, Territory* origin, Territory* destination);
    void toDefend(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders);
    void toDeploy(Player* player, Map* gameMap);
    void issueOrder(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders);
};

class NeutralPlayerStrategy : public PlayerStrategy {
public:
    void toAttack(Player* player, Map* gameMap, Territory* origin, Territory* destination);
    void toDefend(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders);
    void toDeploy(Player* player, Map* gameMap);
    void issueOrder(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders);
};
