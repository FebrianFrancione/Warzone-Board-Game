//#include "startupPhase.h"
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include<vector>
//#include <iostream>     // std::cout
///*#include <algorithm> */   // std::shuffle
//#include <array>        // std::array
///*#include <random>*/       // std::default_random_engine
//#include <chrono>       // std::chrono::system_clock
//#include <random>
//#include <algorithm>
//
//#include "Player.h"
//
//
//using namespace std;
//
//void setPlayerNames(vector<Player>& player_vec)
//{
//	int intialArmies2{ 40 };
//	int intialArmies3{ 35 };
//	int intialArmies4{ 30 };
//	int intialArmies5{ 25 };
//	int passingArmies;
//
//	if (player_vec.size() == 2) {
//		passingArmies = intialArmies2;
//	}
//	else if (player_vec.size() == 3) {
//		passingArmies = intialArmies3;
//	}
//	else if (player_vec.size() == 4) {
//		passingArmies = intialArmies4;
//	}
//	else {
//		passingArmies = intialArmies5;
//	}
//	for (size_t i = 0; i < player_vec.size(); i++) {
//		cout << "Set player name for: " << player_vec[i].getName() << endl;
//		string  userSetPlayerName;
//		cin >> userSetPlayerName;
//		player_vec[i].setName(userSetPlayerName);
//		player_vec[i].setPlayerArmySize(passingArmies);
//		cout << "Player Name Set: " << player_vec[i].getName() << endl << "Player Army size: " << player_vec[i].getPlayerArmySize() << endl;
//	}
//}
//
//
//
//void distributeTerritories(vector<Player>& player_vec, vector<string>& territories) {
//
//	while (!territories.empty()) {
//		for (size_t k = 0; k < player_vec.size(); k++) {
//			int l = territories.size();
//			player_vec[k].playerTerritories.push_back(territories[l - 1]);
//			territories.pop_back();
//		}
//	}
//
//	for (size_t k = 0; k < player_vec.size(); k++) {
//		cout << "Player " << player_vec[k].getName() << ": ";
//		for (size_t i = 0; i < player_vec[k].playerTerritories.size(); i++) {
//			cout << player_vec[k].playerTerritories[i] << " ";
//		}
//		cout << endl;
//	}
//}
//
//
//
//int main() {
//
//	//setting deaflt values for 5 possible players
//
//	Player Player1{ "Player1", 0, 0 };
//	Player Player2{ "Player2", 0, 0 };
//	Player Player3{ "Player3", 0, 0 };
//	Player Player4{ "Player4", 0, 0 };
//	Player Player5{ "Player5", 0, 0 };
//
//
//	/*for (int i = 0; i < Player1.playerTerritories.size(); i++) {
//		cout << Player1.playerTerritories[i];
//	}*/
//	//placeholder for now, setting a list of territories that will bve used to distrbute, must be taken from map class aferwards
//
//	vector<string> territories;
//	vector<string> neutralTerritories;
//	int x = 0;
//
//	//Populate the list, arbitrary for now
//	territories.push_back("Canada");
//	territories.push_back("US");
//	territories.push_back("Mexico");
//	territories.push_back("France");
//	territories.push_back("Germany");
//	territories.push_back("China");
//	territories.push_back("Japan");
//	territories.push_back("India");
//
//
//
//	cout << "Territories: ";
//	for (size_t j = 0; j < territories.size(); j++) {
//		cout << territories[j] << ", ";
//	}
//
//	cout << endl;
//
//
//	cout << "Enter the number of players (2-5)" << endl;
//
//	int numOfPlayers{ 2 };
//	vector<Player> player_vec{ Player1, Player2 };
//
//	cin >> numOfPlayers;
//	if (numOfPlayers < 2 || numOfPlayers > 5) {
//		cout << "Invalid answer. System Exiting" << endl;
//		return 0;
//	}
//	else {
//		switch (numOfPlayers) {
//		case 2:
//			cout << "players initialized: " << numOfPlayers;
//
//			break;
//		case 3:
//			cout << "players initialized: " << numOfPlayers;
//			player_vec.push_back(Player3);
//			numOfPlayers = 3;
//			break;
//		case 4:
//			cout << "players initialized: " << numOfPlayers;
//			player_vec.push_back(Player3);
//			player_vec.push_back(Player4);
//			numOfPlayers = 4;
//			break;
//
//		case 5:
//			cout << "players initialized: " << numOfPlayers;
//			player_vec.push_back(Player3);
//			player_vec.push_back(Player4);
//			player_vec.push_back(Player5);
//			numOfPlayers = 5;
//			break;
//
//		default:
//			cout << "Entry Unknown" << endl;
//			break;
//		}
//		cout << endl;
//		setPlayerNames(player_vec);
//
//		for (size_t i = 0; i < player_vec.size(); i++) {
//			cout << player_vec[i].getName() << endl;
//		}
//
//		cout << "start Game? Enter y to start" << endl;
//		string start;
//		cin >> start;
//		if (start._Equal("y")) {
//			cout << "Game Started!" << endl;
//			/*		cout << "Printing army size" << endl;*/
//					//for (int i = 0; i < player_vec.size(); i++) {
//					//	cout << "Player: " << player_vec[i].getName() << ", Army size: " << player_vec[i].getPlayerArmySize() << endl;
//					//}
//
//
//
//					//shuffle the players and set playerTurn ID
//					/*unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();*/
//				/*	srand(time(0));
//					random_shuffle(player_vec.begin(), player_vec.end());*/
//			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//			std::shuffle(std::begin(player_vec), std::end(player_vec), std::default_random_engine(seed));
//
//
//			std::cout << "Player Turn Order: " << endl;
//			int i = 1;
//			for (Player& player : player_vec) {
//				//player set army size
//				player.setPlayerTurnId(i);
//				i++;
//				//can set player turn id
//				cout << "Player: " << player.getName() << " Player turn id: " << player.getPlayerTurnId() << " Army size: " << player.getPlayerArmySize() << endl;
//				/*	cout << " Player turn Id: " << player.getPlayerTurnId() << endl;*/
//				cout << endl;
//			}
//
//
//
//			// set the territories to player here, if number of territories cannot be assigned, they are set to neutral
//			cout << territories.size() << endl;
//			if (territories.size() % numOfPlayers == 0) {
//				cout << "even distribution!";
//				//distribute territories method
//				//print territories first 
//				for (size_t i = 0; i < territories.size(); i++) {
//					cout << territories[i] << ' ';
//				}
//				cout << endl;
//				//distribute emthod
//				distributeTerritories(player_vec, territories);
//
//			}
//			else {
//				cout << "Uneven distribution!" << endl;
//
//				cout << "Territories before shuffle: " << endl;
//				for (size_t i = 0; i < territories.size(); i++) {
//					cout << territories[i] << ' ';
//				}
//
//
//				unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//				std::shuffle(std::begin(territories), std::end(territories), std::default_random_engine(seed));
//
//
//				cout << endl << "Territories After shuffle: " << endl;
//
//				for (size_t i = 0; i < territories.size(); i++) {
//					cout << territories[i] << ' ';
//				}
//
//				while (territories.size() % numOfPlayers != 0) {
//					int n = territories.size();
//					neutralTerritories.push_back(territories[n - 1]);
//					territories.pop_back();
//				}
//
//				cout << endl << "Territories After popping: " << endl;
//
//				for (size_t i = 0; i < territories.size(); i++) {
//					cout << territories[i] << ' ';
//				}
//
//				cout << endl << "Neutral territories: " << endl;
//
//				for (size_t i = 0; i < neutralTerritories.size(); i++) {
//					cout << neutralTerritories[i] << ' ';
//				}
//				cout << endl;
//				//finished evening out the territories
//					//distribute territoires method
//				distributeTerritories(player_vec, territories);
//			}
//		}
//		else {
//			cout << "Invalid answer. System Exiting" << endl;
//			return 0;
//		}
//	}
//}
//
//
//
//
////Player1.setName("Frank");
////Player2.setName("Bill");
///*for (int i = 0; i < player_vec.size(); i++) {
//	cout << player_vec[i].getName() << endl;
//}*/
////Player1.hand = 3;
////Player players[]{ frank,bill };
////std::ostream << players[1] << endl;
////Player* enemy{ nullptr };
////enemy = new Player;