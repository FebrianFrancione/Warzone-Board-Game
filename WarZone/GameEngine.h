#pragma once

#include "Player.h"
#include "PlayerStrategies.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class GameEngine {
private:
	int num_players;
	vector<Player*> players;
	Map* gameMap;
	string mapName;
	string winner;
public:
	//assignment operator constructor
	GameEngine();
	//copy constructor 
	GameEngine(const GameEngine& e);

	bool initializeGameValues(); //returns true if game intialized successfully
	void startupPhase();
	//void assignOrder();
	//void assignCardDeck();
	//void GamestartupPhase();
	void reinforcementPhase();
	void issueOrdersPhase();
	void executeOrdersPhase();
	void mainGameLoop();
	//Name check function (player unique names)
	bool validName(string name);
	//Validates whether the territory belongs to the player
	bool validTerritoryDefend(string selection, Player* player);
	//Valid target to transfer to
	bool validTerritoryTransferTarget(string selection, Territory* origin, Player* player);
	//Validate whether the territory belongs to the player, and has an attack target
	bool validTerritoryAttack(string selection, Player* player);
	//Validate whether the target of an attack is the neighbour of the origin
	bool validTerritoryAttackTarget(string selection, Territory* origin, Player* player);
	//Valid reinforcment troop count for deploy
	bool validReinforceAmount(string amount, Player* player);
	//Valid amount of troops to advance with (attack or transfer)
	bool validAdvanceAmount(string amount, Territory* origin);
	//
	bool validOrder(string input, Player* player);
};
