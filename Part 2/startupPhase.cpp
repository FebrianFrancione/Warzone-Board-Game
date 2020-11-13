#include "startupPhase.h"
#include <iostream>

#include<vector>
#include "Player.h"

using namespace std;

int main() {
	Player Player1;
	Player Player2;
	Player Player3;
	Player Player4;
	Player Player5;

	//vector<Player> player_vec{ Player1 };

	//player_vec.push_back(Player2);
	cout << "Enter the number of players (2-5)" << endl;
	int numOfPlayers{ 2 };
	Player1.setName("Frank");
	Player2.setName("Bill");
	Player3.setName("bob");
	vector<Player> player_vec{ Player1, Player2 };

	cin >> numOfPlayers;
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
		player_vec.push_back(Player4);
		break;
	case 5:
		cout << "players initialized: " << numOfPlayers;
		player_vec.push_back(Player5);
		break;
	default:
		cout << "Entry Unknown" << endl;
		break;
}

	for (int i = 0; i < player_vec.size(); i++) {
		cout << player_vec[i].getName() << endl;
	}



	/*void PlayerNames(vector<Player> &player_vec) {

	}*/

	
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



}