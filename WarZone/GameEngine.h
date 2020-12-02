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
	void mainGameLoop();
	void reinforcementPhase();
	void issueOrdersPhase();
	void executeOrdersPhase();
};
