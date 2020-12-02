#include "GameEngine.h"
#include "Player.h"
#include "Map.h"
#include "MapLoader.h"

#include <iostream>
//#include <filesystem> //ENABLE IF PROJECT IS SET FOR C++17, IF NOT CANNOT READ FILES FROM DIRECTORY
#include <filesystem>
using namespace std;

AggressivePlayerStrategy aggroStrat;
HumanPlayerStrategy humanStrat;
BenevolentPlayerStrategy benevolentStrat;
NeutralPlayerStrategy neutralStrat;

//================================
//	GameEngine
//================================
GameEngine::GameEngine(){
	num_players = 0;
	gameMap = new Map("");
}

GameEngine::GameEngine(const GameEngine& e) {
	num_players = e.num_players;
	gameMap = e.gameMap;
}

//================================
//	init game values
//================================
bool GameEngine::initializeGameValues() {

	//For reading in input
	string input;
	//Game start greeting
	cout << "---------------- Warzone game : Conquer All Worlds ----------------" << endl;
	cout << endl;
	//LOAD MAP
	cout << "Type in name of map to play on: (you may have to check manually in the directory)" << endl;
	string path = "Maps/";
	//ENABLE ONLY IF C++17 IS AVAILABLE
/*	for (const auto& entry : filesystem::directory_iterator(path))
		std::cout << entry.path() << std::endl;*/


/*	cout << "Default available: \"canada.map\"" << endl << ">> ";
	getline(cin, input);*/
	//temp
	input = "canada.map";
	mapName = path + input;
	//GET PLAYERS
/*	cout << "Enter number of players (2-5)" << endl << ">> ";
	getline(cin, input);
	try {
		*//*num_players = stoi(input);*//*

		if (num_players > 5 || num_players < 2) {
			throw exception();
		}
	}
	catch (const std::exception& e) {
		cout << "Invalid player number. Game closing" << endl;
		return false;
	}*/


    //temp
    num_players = 2;


	//statistic observer on/off
	cout << "Statistic Observer (type \"on\" to turn on)" << endl << ">> ";
	getline(cin, input);
	if (input == "on") {
		// put statistic observer intialiser here (reserved for observer part) 
	}
	// phase observer on//off
	cout << "Phase Observer (type \"on\" to turn on)" << endl << ">> ";
	getline(cin, input);
	if (input == "on") {
		//put phase observer initialiser here (reserved for observer part) 
	}

	//LOAD MAP
	cout << "====================" << endl;
	cout << "====================" << endl;
	cout << "Loading map at: " << mapName << endl;
	MapLoader loader = MapLoader(mapName);
	//Try to load map, if fails exit
	try {
		loader.loadMap();
		gameMap = new Map(loader.getMapCopy());
	}
	catch (const std::exception& e) {
		cout << e.what();
		exit(1002);
	}
	//If read successfully, validate
	if (!gameMap->validate()) {
		cout << "Invalid map. Game closing" << endl;
		return false;
	}
	else {
		loader.printMap();
		return true;
	}

}

//================================
//	startupPhase: initialize players and territories
//================================
void GameEngine::startupPhase() {

	string input = "";
	//Initialize players
	int initialArmies = 0;
	switch (num_players) {
	case 2: initialArmies = 40; break;
	case 3: initialArmies = 35; break;
	case 4: initialArmies = 30; break;
	case 5: initialArmies = 25; break;
	}
	for (int i = 0; i < num_players; i++) {
		cout << "Enter player " << i + 1 << "'s name >> ";
		getline(cin, input);
		while (input.empty()) {
			cout << "Empty name, try again" << endl << ">>";
			getline(cin, input);
		}


		//gameMap is a pointer, and we're giving each player direct access to the map object because I didn't
		//implement the graph data structure properly and now it's kinda too late to rewrite that whole thing
		//so we're doing some ------****epic****------ cheating.
		players.push_back(new Player(input, i, initialArmies, gameMap));


        //sanity check
        //strategy before or after

        int strat_id {0};

        cout << "Enter player " << i + 1 << "'s Starting Strategy."<<endl<<"1.Human 2.Aggro 3.Benevolent 4.Neutral(AFK)" << endl;
        cin >> strat_id;
        cout << strat_id;
        switch (strat_id) {
        case 1: players[i]->setPlayerStrategy(&humanStrat);break;
        case 2: players[i]->setPlayerStrategy(&aggroStrat);break;
        case 3: players[i]->setPlayerStrategy(&benevolentStrat);break;
        case 4: players[i]->setPlayerStrategy(&neutralStrat);break;
        }
        cout << "Strat set!" << endl;
        players[i]->toAttack();
        players[i]->toDefend();
        players[i]->issueOrder();

        cout << "Continue" << endl;
	}



	//Shuffle the vector to randomize play order
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(std::begin(players), std::end(players), std::default_random_engine(seed));
	cout << "====================" << endl;
	cout << "Player turn order will be:" << endl;
	for (int i = 0; i < num_players; i++) {
		cout << players[i]->getName() << endl;
		players[i]->setPlayerTurnId(i + 1);
	}
	cout << "====================" << endl;

	//Distribute territories to each player
	//Step 1: Create a vector of the territories ids that we can shuffle for random distribution
	vector<int> shuffleTerritories;
	for (int i = 0; i < gameMap->getNumTerritories(); i++) shuffleTerritories.push_back(i);
	//Step 2: Shuffle said vector
	seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(std::begin(shuffleTerritories), std::end(shuffleTerritories), std::default_random_engine(seed));
	//Step 3: Give the territories out in the shuffled order to the players in their own order
	int distributeQty = gameMap->getNumTerritories() - (gameMap->getNumTerritories() % num_players);
	for (int i = 0; i < distributeQty; i++) {
		//Update the player's list of territories
		//players[i % num_players]->territoriesId.push_back(shuffleTerritories[i]);
		players[i % num_players]->territories.push_back(gameMap->getTerritory(shuffleTerritories[i]));
		//Update the territories' owner in the map itself
		gameMap->getTerritory(shuffleTerritories[i])->setOwner(players[i % num_players]->getName());
		//Put a message out for the player //TEST
		//cout << players[i % num_players]->getName() << " receives " << gameMap->getTerritory(shuffleTerritories[i])->getName() << endl;
	}
	cout << "====================" << endl;
	cout << "Territory distribution summary" << endl;
	for (int i = 0; i < num_players; i++) {
		cout << players[i]->getName() << ": " << endl;
		//for (int j = 0; j < players[i]->territoriesId.size(); j++) {
		for (int j = 0; j < players[i]->territories.size(); j++) {
			//cout << gameMap->getTerritory(players[i]->territoriesId[j])->getName() << endl;
			cout << players[i]->territories[j]->getName() << endl;
		}
		cout << "--------" << endl;
	}
	cout << "Neutral territories: " << endl;
	for (int i = 0; i < gameMap->getNumTerritories() - distributeQty; i++) {
		cout << gameMap->getTerritory(shuffleTerritories[i + distributeQty])->getName() << endl;
	}
cout << "--------" << endl;
	cout << "All territories in order: " << endl;
	for (int i = 0; i < gameMap->getNumTerritories(); i++) {
		cout << gameMap->getTerritory(i)->getName() << " owned by " << gameMap->getTerritory(i)->getOwner() << endl;
	}


}

//================================
//	MAIN GAME LOOP FUNCTIONS
//================================
void GameEngine::reinforcementPhase() {
}

void GameEngine::issueOrdersPhase() {
}

void GameEngine::executeOrdersPhase() {
}

//================================
//	MAIN GAME LOOP
//================================
void GameEngine::mainGameLoop() {
	reinforcementPhase();
	issueOrdersPhase();
	executeOrdersPhase();
	for (int i = 0; i < num_players; i++) {
		cout << "It is " << players[i]->getName() << "'s turn" << endl;
		cout << players[i]->getName() << "'s Defense: " << endl;
	    players[i]->toDefend();
        cout << players[i]->getName() << "'s Attack: " << endl;
		players[i]->toAttack();
	}
}
