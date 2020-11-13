#include "startupPhase.h"
#include <iostream>

#include<vector>
#include "Player.h"

using namespace std;


void setPlayerNames(vector<Player> &player_vec)
{


	int intialArmies2{ 40 };
	int intialArmies3{ 35 };
	int intialArmies4{ 30 };
	int intialArmies5{ 25 };
	int passingArmies;

	if (player_vec.size() == 2) {
		passingArmies = intialArmies2;
	}
	else if (player_vec.size() == 3) {
		passingArmies = intialArmies3;
	}
	else if (player_vec.size() == 4) {
		passingArmies = intialArmies4;
	}
	else {
		passingArmies = intialArmies5;
	}
	for (int i = 0; i < player_vec.size(); i++) {
		cout << "Set player name for: " << player_vec[i].getName() << endl;
		string  userSetPlayerName;
		cin >> userSetPlayerName;
		player_vec[i].setName(userSetPlayerName);
		player_vec[i].setPlayerArmySize(passingArmies);
		cout << "Player Name Set: " << player_vec[i].getName() << endl << "Player Army size: " << player_vec[i].getPlayerArmySize() << endl;
	}
}

int main() {

	//setting deaflt values for 5 possible players
	Player Player1{ "Player1", 1, 0 };
	Player Player2{ "Player2", 2, 0 };
	Player Player3{ "Player3", 3, 0 };
	Player Player4{ "Player4", 4, 0 };
	Player Player5{ "Player5", 5, 0 };


	cout << "Enter the number of players (2-5)" << endl;

	int numOfPlayers{2};
	vector<Player> player_vec{ Player1, Player2 };


	cin >> numOfPlayers;
	if (numOfPlayers < 2 || numOfPlayers > 5) {
		cout << "Invalid answer. System Exiting" << endl;
		return 0;
	}
	else {
		switch (numOfPlayers) {
		case 2:
			cout << "players initialized: " << numOfPlayers;
			
			break;
		case 3:
			cout << "players initialized: " << numOfPlayers;
			player_vec.push_back(Player3);
			
			break;
		case 4:
			cout << "players initialized: " << numOfPlayers;
			player_vec.push_back(Player3);
			player_vec.push_back(Player4);
			
			break;
		case 5:
			cout << "players initialized: " << numOfPlayers;
			player_vec.push_back(Player3);
			player_vec.push_back(Player4);
			player_vec.push_back(Player5);
			

			break;
		default:
			cout << "Entry Unknown" << endl;
			break;
		}

		cout << endl;
		//for (int i = 0; i < player_vec.size(); i++) {
		//	cout << player_vec[i].getName() << endl;
		//}

		setPlayerNames(player_vec);

		for (int i = 0; i < player_vec.size(); i++) {
			cout << player_vec[i].getName() << endl;
		}

		cout << "start Game? Enter y to start" << endl;
		string start;
		cin >> start;
		if (start._Equal("y")) {
			cout << "Game Started!";

			cout << "Printing army size";
			for(int i = 0; i < player_vec.size(); i++) {
				cout << player_vec[i].getPlayerArmySize() << endl;
			}

		}
		else {
			cout << "Invalid answer. System Exiting" << endl;
			return 0;
		}
	}
}


//Player1.setName("Frank");
//Player2.setName("Bill");
/*for (int i = 0; i < player_vec.size(); i++) {
	cout << player_vec[i].getName() << endl;
}*/
//Player1.hand = 3;
//Player players[]{ frank,bill };
//std::ostream << players[1] << endl;
//Player* enemy{ nullptr };
//enemy = new Player;