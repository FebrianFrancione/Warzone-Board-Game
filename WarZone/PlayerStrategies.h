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
	
	virtual void toAttack(Player* player, Map* gameMap) = 0;
	virtual void toDefend(Player* player, Map* gameMap) = 0;
	virtual void toDeploy(Player* player, Map* gameMap) = 0;
	virtual void issueOrder(Player* player, Map* gameMap) = 0;
};

class HumanPlayerStrategy : public PlayerStrategy{
public:
	void toAttack(Player* player, Map* gameMap);
	void toDefend(Player* player, Map* gameMap);
	void toDeploy(Player* player, Map* gameMap);
    void issueOrder(Player* player, Map* gameMap);
};

class AggressivePlayerStrategy : public PlayerStrategy {
public:
    void toAttack(Player* player, Map* gameMap);
    void toDefend(Player* player, Map* gameMap);
    void toDeploy(Player* player, Map* gameMap);
    void issueOrder(Player* player, Map* gameMap);
};

class BenevolentPlayerStrategy : public PlayerStrategy {
public:
    void toAttack(Player* player, Map* gameMap);
    void toDefend(Player* player, Map* gameMap);
    void toDeploy(Player* player, Map* gameMap);
    void issueOrder(Player* player, Map* gameMap);
};

class NeutralPlayerStrategy : public PlayerStrategy {
public:
    void toAttack(Player* player, Map* gameMap);
    void toDefend(Player* player, Map* gameMap);
    void toDeploy(Player* player, Map* gameMap);
    void issueOrder(Player* player, Map* gameMap);
};
