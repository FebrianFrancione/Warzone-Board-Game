#include "Player.h"
#include "Cards.h"
#include "Map.h"

#include <iomanip>

using namespace std;

//default constructor
//Player::Player() {
//	armySize = -1;
//	playerTurnId = -1;
//	hand = -1;
//};

//constructor
Player::Player(std::string n, int id, int army, Map* needle) {
	//Player::Player(std::string n, int id, int army, list<string> t, int h) {
	armySize = army;
	name = n;
	playerTurnId = id;
	gameMap = needle;
	//vector<string> playerTerritories;
	//territories = t;
	//hand = h;
};

//copy constructor
Player::Player(const Player& p) {
	armySize = p.armySize;
	name = p.name;
	playerTurnId = p.playerTurnId;
	/*player1_hand = p.player1_hand;*/
}

Player::~Player() {}

//Iterates over a list of territories owned by the player and displays them
void Player::toDefend() {
	cout << "Your territories to defend: " << endl;
	for (int i = 0; i < territories.size(); i++) {
		cout << setw(40) << territories[i]->getName() << endl; 
	}
	cout << "--------" << endl;
}

// Displays a list of surrounding territories the player can attack
void Player::toAttack() {
	cout << "The territories you can attack are: " << endl;
	for (int i = 0; i < territories.size(); i++) {
		for (int j = 0; j < territories[i]->getNumberAdj(); j++) {
			if (gameMap->getTerritory(territories[i]->getAdjacent(j))->getOwner() != name) {
				cout << 
					right << setw(40) << gameMap->getTerritory(territories[i]->getAdjacent(j))->getName() << 
					" (" << setw(2) << territories[i]->getAdjacent(j) << ")" <<
					setw(20) << " belonging to " <<
					left << setw(20) << gameMap->getTerritory(territories[i]->getAdjacent(j))->getOwner() <<
					" from " <<
					right << setw(40) << territories[i]->getName() <<
					" (" << setw(2) << territories[i]->getId() << ")" <<
					endl;
			}
		}
	}
	cout << "--------" << endl;
}

//Adds an order to the order list and displays all current orders
void Player::issueOrder() {

	int j = 1;

	orders.push_back(" Order " + to_string(j));
	cout << " Order " + to_string(j) << " was added to the list of orders";
	cout << endl;

	j++;

	cout << "List of all orders:";
	cout << endl;
	for (list<string>::iterator it = orders.begin(); it != orders.end(); ++it) {

		std::cout << ' ' << *it;
		cout << endl;

	};
	cout << endl;
}


void Player::setName(string n) {
	name = n;
}
string Player::getName() {
	return name;
}

void Player::setPlayerTurnId(int id) {
	playerTurnId = id;
}
int Player::getPlayerTurnId() {
	return playerTurnId;
}

void Player::setPlayerArmySize(int army) {
	armySize = army;
}
int Player::getPlayerArmySize() {
	return armySize;
}

