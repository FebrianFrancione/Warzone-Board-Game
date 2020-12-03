#include "GameEngine.h"
#include "Player.h"
#include "Map.h"
#include "MapLoader.h"

#include <iostream>
//#include <filesystem> //ENABLE IF PROJECT IS SET FOR C++17, IF NOT CANNOT READ FILES FROM DIRECTORY
#include <filesystem>
using namespace std;

//AggressivePlayerStrategy aggroStrat;
//HumanPlayerStrategy humanStrat;
//BenevolentPlayerStrategy benevolentStrat;
//NeutralPlayerStrategy neutralStrat;

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
	catch (const std::exception&) {
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
	//If this threw, it just really confirms how dogshit I(calvin) am heh
	throw exception();
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
		while (!validName(input)) {
			cout << "Invalid name, try again" << endl << ">>";
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
        case 1: players[i]->setPlayerStrategy(new HumanPlayerStrategy());break;
        case 2: players[i]->setPlayerStrategy(new AggressivePlayerStrategy());break;
        case 3: players[i]->setPlayerStrategy(new BenevolentPlayerStrategy());break;
        case 4: players[i]->setPlayerStrategy(new NeutralPlayerStrategy());break;
        }
        //these will be removed
 /*       cout << "Strat set!" << endl;
        players[i]->toAttack();
        players[i]->issueOrder();

        cout << "Continue" << endl;*/
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
		players[i % num_players]->territories.push_back(gameMap->getTerritory(shuffleTerritories[i]));
		//Update the territories' owner in the map itself
		gameMap->getTerritory(shuffleTerritories[i])->setOwner(players[i % num_players]->getName());
		//Assign a minimum of 1 troop
		gameMap->getTerritory(shuffleTerritories[i])->setArmyCount(1);
		gameMap->getTerritory(shuffleTerritories[i])->setVirtualArmy(1);
		players[i % num_players]->subtractReinforcements(1);
		
	}
	//OUTPUT TO SCREEN
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
	int justToGetRidOfThisWarning;
	for (int i = 0; i < gameMap->getNumTerritories() - distributeQty; i++) {
		justToGetRidOfThisWarning = i + distributeQty;
		cout << gameMap->getTerritory(shuffleTerritories[justToGetRidOfThisWarning])->getName() << endl;
	}
}

//===============================================
//	--------------------------------------
//	The 3 functions for the main game loop
//	--------------------------------------
//===============================================


//================================
//	Reinforcement Phase
//================================
void GameEngine::reinforcementPhase() {
	//Check for continent bonus for any player
	for (int i = 0; i < gameMap->getNumContinents(); i++) {
		//get the owner of the first territory of the continent
		bool bonus = true;
		string first = gameMap->getTerritory(gameMap->getContinent(i)->getTerritoryId(0))->getOwner();
		string last;
		//iterate through the list of countries in the continent
		for (int j = 0; j < gameMap->getContinent(i)->getNumTerritories(); j++) {
			last = gameMap->getTerritory(gameMap->getContinent(i)->getTerritoryId(j))->getOwner();
			//we found a different player present in the continent
			if (last != first) {
				bonus = false;
			}
		}
		if (bonus) {
			for (int j = 0; j < players.size(); j++) {
				if (players[j]->getName() == first) {
					players[j]->addReinforcements(gameMap->getContinent(i)->getReinforcementBonus());
				}
			}
		}
	}
	//Each player must assign all of their remaining troops
	cout << endl << "++++++++++++++++++++" << endl;
	cout << "Reinforcement Phase:" << endl;
	int reinforcements;
	string input;
	for (int playerIndex = 0; playerIndex < num_players; playerIndex++) {
		cout << endl << "============" << endl;
		cout << "Player " << players[playerIndex]->getName() << "'s turn to reinforce. ";
		//Reinforcements by number of territories with a minimum of 3
		reinforcements = players[playerIndex]->territories.size() / 3;
		if (reinforcements < 3) {
			reinforcements = 3;
		}
		//Add existing amount
		players[playerIndex]->addReinforcements(reinforcements);
		//Loop to deploy all troops
		int selectId;
		while (players[playerIndex]->getPlayerArmySize() > 0) {
			players[playerIndex]->toDeploy();
		}
	}
}

//================================
//	Issue Orders Phase
//================================
void GameEngine::issueOrdersPhase() {
	cout << endl << "++++++++++++++++++++" << endl;
	cout << "Order issuing phase" << endl;
	//Each player gets to issue their orders
	for (int i = 0; i < num_players; i++) {
		players[i]->issueOrder();
	}
}

//================================
//	Execute Orders Phase
//================================
void GameEngine::executeOrdersPhase() {
	int totalNumberOfOrder = 0;
	for (int i = 0; i < num_players; i++) {
		while (players[i]->numberOfOrders() > 0 && players[i]->getFirstOrder()->getType() == Order::Deploy) {
			players[i]->executeOrder(0);
		}
		//Adds the number of remaining orders to execute from this player
		totalNumberOfOrder += players[i]->numberOfOrders();
	}
	//While there are orders to execute
	while (totalNumberOfOrder > 0) {
		//For each player, get the current first order of the list
		for (int i = 0; i < num_players; i++) {
			//If this player still has an order to execute
			if (players[i]->numberOfOrders() > 0) {
				//play it
				players[i]->executeOrder(0);
				totalNumberOfOrder--; //decrement the counter
			}
			//next players first order
		}
	}
}

//================================
//	MAIN GAME LOOP
//================================
void GameEngine::mainGameLoop() {

	/*reinforcementPhase();
	issueOrdersPhase();
	executeOrdersPhase();
	for (int i = 0; i < num_players; i++) {
        cout << "It is " << players[i]->getName() << "'s turn" << endl;
        cout << players[i]->getName() << "'s Defense: " << endl;
        players[i]->toDefend();
        cout << players[i]->getName() << "'s Attack: " << endl;
        players[i]->toAttack();
    }*/
	bool victory = false;
	int turnCounter = 0;
	while (!victory) {
		reinforcementPhase();
		issueOrdersPhase();
		executeOrdersPhase();
		for (int i = 0; i < num_players; i++) {
			if (players[i]->territories.size() == gameMap->getNumTerritories()) {
				victory = true;
				cout << "================================" << endl;
				cout << "            --------            " << endl;
				cout << " ** **  **  ++++++++  **  ** ** " << endl;
				cout << setw(32) << (players[i]->getName() + " has won the game.") << endl;
				cout << " ** **  **  ++++++++  **  ** ** " << endl;
				cout << "            --------            " << endl;
				cout << "================================" << endl;
			}
		}
		//fail safe for testing
		if (turnCounter == 5) {
			cout << "Turn limit reached. No one won";
			victory = true;
		}
	}
}

//================================
//	Validation functions
//================================

bool GameEngine::validName(string name) {
	//cant be empty
	if (name.empty()) {
		return false;
	}
	//check if exists in list already
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->getName() == name) {
			return false;
		}
	}
	return true;
}