#pragma once

#include "Player.h"

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
	//Name check function
	bool validName(string name);
	bool validTerritoryDefend(string selection, Player* player);
	bool validReinforceAmount(string amount, Player* player);
};
