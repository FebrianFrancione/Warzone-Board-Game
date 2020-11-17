using namespace std;
#include "Player.h"
#include <iostream>
#include <string>




//default cunstructor
//default cunstructor
Player::Player() {

	int hand{ 0 };
	string name{ "Player" };

};

//contructor 
Player::Player(list<string> t, int h) {

	territories = t;
	hand = h;

};

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

void Player::setPlayerId(int id) {
	playerId = id;
}
int Player::getPlayerId() {
	return playerId;
}