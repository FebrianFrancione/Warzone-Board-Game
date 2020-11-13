#include "startupPhase.h"
#include <iostream>

#include<vector>
#include "Player.h"

using namespace std;


void setPlayerNames(vector<Player> &player_vec)
{
	for (int i = 0; i < player_vec.size(); i++) {
		cout << "Set player name for: " << player_vec[i].getName() << endl;
		string  userSetPlayerName;
		cin >> userSetPlayerName;
		player_vec[i].setName(userSetPlayerName);
		cout << "Player Name Set: " << player_vec[i].getName() << endl;
	}
}

int main() {

	//setting deaflt values for 5 possible players
	Player Player1{ "Player1", 1 };
	Player Player2{ "Player2", 2 };
	Player Player3{ "Player3", 3 };
	Player Player4{ "Player4", 4 };
	Player Player5{ "Player5", 5 };

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

			switch (player_vec.size()) {
			case 2:
				cout << "players initialized: " << numOfPlayers;
				break;
			case 3:
				cout << "players initialized: " << numOfPlayers;
				break;
			case 4:
				cout << "players initialized: " << numOfPlayers;
				break;
			case 5:
				cout << "players initialized: " << numOfPlayers;
				break;





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