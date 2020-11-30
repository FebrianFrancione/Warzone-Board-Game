using namespace std;
#include "Player.h"
#include "Cards.h"




//default cunstructor
//default cunstructor
//Player::Player() {
//
//	int hand{ 0 };
//	string name{ "Player" };
//
//};

//copy
Player::Player(const Player& p)
{
	name = p.name;
	armySize = p.armySize;
	/*player1_hand = p.player1_hand;*/

}

//constructor
Player::Player(std::string n, int id, int army) {
	//Player::Player(std::string n, int id, int army, list<string> t, int h) {


	name = n;
	playerTurnId = id;

	armySize = army;
	vector<string> playerTerritories;
	//territories = t;
	//hand = h;
};

//contructor 
//Player::Player(list<string> t, int h) {
//
//	
//};

Player::~Player() {}

//Iterates over a list of territories owned by the player and displays them
void Player::toDefend() {

	cout << "The territories you can defend are:";
	cout << endl;
	for (list<string>::iterator it = territories.begin(); it != territories.end(); ++it) {

		std::cout << ' ' << *it;
		cout << endl;

	};
	cout << endl;
}

// Displays a list of surrounding territories the player can attack, arbitrary for now
void Player::toAttack() {

	list<string> a;
	a.push_back("Russia");
	a.push_back("China");
	a.push_back("Japan");

	cout << "The territories you can attack are:";
	cout << endl;
	for (list<string>::iterator it = a.begin(); it != a.end(); ++it) {

		std::cout << ' ' << *it;
		cout << endl;

	};
	cout << endl;
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

