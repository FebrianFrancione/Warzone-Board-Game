#include "GameEngine.h"

#include <iostream>
//#include <filesystem> //ENABLE IF PROJECT IS SET FOR C++17, IF NOT CANNOT READ FILES FROM DIRECTORY
using namespace std;

//================
//	GameEngine
//================

GameEngine::GameEngine(){
	num_players = 0;
	gameMap = new Map("");
}

GameEngine::GameEngine(const GameEngine& e) {
	num_players = e.num_players;
	gameMap = e.gameMap;
}

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
	/*
	for (const auto& entry : filesystem::directory_iterator(path))
		std::cout << entry.path() << std::endl;
	*/
	cout << "Default available: \"canada.map\"" << endl << ">> ";
	getline(cin, input);
	mapName = path + input;
	//GET PLAYERS
	cout << "Enter number of players (2-5)" << endl << ">> ";
	getline(cin, input);
	try {
		num_players = stoi(input);
		if (num_players > 5 || num_players < 2) {
			throw exception();
		}
	}
	catch (const std::exception& e) {
		cout << "Invalid player number. Game closing";
		return false;
	}
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
	loader.loadMap();
	Map newMap = loader.getMapCopy();
	gameMap = &newMap;
	if (!gameMap->validate()) {
		cout << "Invalid map. Game closing" << endl;
		return false;
	}
	else {
		loader.printMap();
	}
}

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
		players.push_back(new Player(input, i, initialArmies));
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
	/*
	Optimally loop backwards so that last players get 1 extra territories given they play after
	sike neutral territories
	Basically, going from player to player, assign a random territory to that player
	The territory contains who owns it
	At every player turn, will probably have to loop through all territories to see which ones they own
	*/
	
}
