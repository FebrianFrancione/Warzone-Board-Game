#pragma once

#include "Cards.h";
#include "GameEngine.h"
#include "Map.h"
#include "MapLoader.h"
#include "Orders.h"
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
public:
	//assignment operator constructor
	GameEngine();
	//copy constructor 
	GameEngine(const GameEngine& e);

	bool initializeGameValues(); //returns true if game intialized successfully
	void startupPhase();
	void assignOrder();
	void assignCardDeck();
	void GamestartupPhase();
};
