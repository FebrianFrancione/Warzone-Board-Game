#include "Player.h"
#include "Cards.h"
#include "Map.h"

#include <iostream>
#include <iomanip>

using namespace std;

//default constructor
Player::Player() {
	armySize = -1;
	playerTurnId = -1;
	gameMap = new Map("");
	hand = -1;
	orders = new OrdersList();
};

//temp
/*Player::Player(std::string n, int id, int army) {
    //Player::Player(std::string n, int id, int army, list<string> t, int h) {
    armySize = army;
    name = n;
    playerTurnId = id;
    //vector<string> playerTerritories;
    //territories = t;
    //hand = h;
};*/

//constructor
Player::Player(std::string n, int id, int army, Map* needle) {
	//Player::Player(std::string n, int id, int army, list<string> t, int h) {
	armySize = army;
	name = n;
	playerTurnId = id;
	gameMap = needle;
	orders = new OrdersList();
	//vector<string> playerTerritories;
	//territories = t;
	//hand = h;
};

//copy constructor
Player::Player(const Player& p) {
	armySize = p.armySize;
	name = p.name;
	playerTurnId = p.playerTurnId;
	orders = p.orders;
	/*player1_hand = p.player1_hand;*/
}

Player::~Player() {}


//player Strategies
void Player::setPlayerStrategy(PlayerStrategy* strat){
    this->playerstrat = strat;
}

//Iterates over a list of territories owned by the player and displays them

void Player::printPlayerTerritories() {
	cout << name << "'s territories: " << endl;
	for (int i = 0; i < territories.size(); i++) {
		cout <<
			right << setw(36) << territories[i]->getName() <<
			" (ID:" << setw(2) << territories[i]->getId() << ")" <<
			" (Troops:" << setw(3) << territories[i]->getVirtualArmy() << ")" <<
			endl;
	}
	cout << "--------" << endl;
}

void Player::toDeploy() {
	this->playerstrat->toDeploy(this, gameMap);
}

// Displays a list of surrounding territories the player can attack
void Player::toAttack() {
    this->playerstrat->toAttack(this, gameMap);
	//issue advance order with origin and destination after
}

void Player::toDefend() {
    this->playerstrat->toDefend(this, gameMap);
    //cout << " Inside player class Player name: " << this;
}

//Player can issue an order
void Player::issueOrder() {
    this->playerstrat->issueOrder(this, gameMap);
}

//Add order to the players orderlist
void Player::addOrder(Order* order) {
	orders->add(order);
}

void Player::executeOrder(int i) {
	if (i < orders->getSize() && i >= 0) {
		orders->get(i)->execute();
		orders->deleteOrder(i);
	}
}

Order* Player::getFirstOrder() {
	if (orders->getSize() > 0) {
		return orders->get(0);
	}
	return nullptr;
}


int Player::numberOfOrders() {
	return orders->getSize();
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

void Player::addReinforcements(int r) {
	armySize += r;
}

void Player::subtractReinforcements(int r) {
	armySize -= r;
}

//====================================
//	Input validation functions
//====================================

//Valid target to deploy troops to
bool Player::validTerritoryDeploy(string input) {
	int territoryId = 0;
	//attempt to parse user input into int
	try {
		territoryId = stoi(input);
	}
	catch (const std::exception&) {
		cout << "!!Not a territory ID" << endl;
		return false;
	}
	//within territory id ranges
	if (territoryId >= gameMap->getNumTerritories() || territoryId < 0) {
		cout << "!!Invalid territory ID." << endl;
		return false;
	}
	//check that there are enough troops to move
	if (gameMap->getTerritory(territoryId)->getVirtualArmy() < 1) {
		cout << "Not enough troops to transfer";
		return false;
	}
	//check if belongs to the player
	if (gameMap->getTerritory(territoryId)->getOwner() != name) {
		cout << "!!This territory does not belong to you." << endl;
		return false;
	}
	else {
		return true;
	}
}

//Valid target to get troops from for transfer
bool Player::validTerritoryDefend(string selection) {
	int territoryId = 0;
	//attempt to parse user input into int
	try {
		territoryId = stoi(selection);
	}
	catch (const std::exception&) {
		cout << "!!Not a territory ID" << endl;
		return false;
	}
	//within territory id ranges
	if (territoryId > gameMap->getNumTerritories() || territoryId < 0) {
		cout << "!!Invalid territory ID." << endl;
		return false;
	}
	//check that there are enough troops to move
	if (gameMap->getTerritory(territoryId)->getVirtualArmy() < 2) {
		cout << "Not enough troops to transfer";
		return false;
	}
	//check if belongs to the player
	if (gameMap->getTerritory(territoryId)->getOwner() != name) {
		cout << "!!This territory does not belong to you." << endl;
		return false;
	}
	else {
		return true;
	}
}

bool Player::validTerritoryTransferTarget(string selection, Territory* origin) {
	int territoryId = 0;
	//attempt to parse user input into int
	try {
		territoryId = stoi(selection);
	}
	catch (const std::exception&) {
		cout << "!!Not a territory ID" << endl;
		return false;
	}
	//within territory ids range
	if (territoryId > gameMap->getNumTerritories() || territoryId < 0) {
		cout << "!!Invalid territory ID." << endl;
		return false;
	}
	//check if the territory belongs to the player
	if (gameMap->getTerritory(territoryId)->getOwner() != name) {
		cout << "This territory does not belong to you" << endl;
		return false;
	}
	//for each neighbour of the origin, check if one of them is a target
	for (int i = 0; i < origin->getNumberAdj(); i++) {
		if (origin->getAdjacent(i) == territoryId && gameMap->getTerritory(territoryId)->getOwner() == name) {
			return true;
		}
	}
	//not neighbours, loop never found neighbour
	cout << "!!Selected target is not a neighbour of " << origin->getName() << endl;
	return false;
}

//Check if the selected territory can launch an attack
bool Player::validTerritoryAttack(string selection) {
	int territoryId = 0;
	//attempt to parse user input into int
	try {
		territoryId = stoi(selection);
	}
	catch (const std::exception&) {
		cout << "!Not a territory ID" << endl;
		return false;
	}
	//check if within territory ids range
	if (territoryId > gameMap->getNumTerritories() || territoryId < 0) {
		cout << "!!Invalid territory ID." << endl;
		return false;
	}
	//check that there are enough troops to move
	if (gameMap->getTerritory(territoryId)->getVirtualArmy() < 2) {
		cout << "Not enough troops to attack";
		return false;
	}
	//check if the territory belongs to the player
	if (gameMap->getTerritory(territoryId)->getOwner() != name) {
		cout << "This territory does not belong to you" << endl;
		return false;
	}
	//Check that the selected origin has a target for attack (does one of the neighbours belong to a different player)
	for (int i = 0; i < gameMap->getTerritory(territoryId)->getNumberAdj(); i++) {
		if (gameMap->getTerritory(gameMap->getTerritory(territoryId)->getAdjacent(i))->getOwner() != name) {
			return true;
		}
	}
	cout << "!!Not a valid territory to attack from" << endl;
	return false;
}

//Is this a valid target for an attack
bool Player::validTerritoryAttackTarget(string selection, Territory* origin) {
	int territoryId = 0;
	//attempt to parse user input into int
	try {
		territoryId = stoi(selection);
	}
	catch (const std::exception&) {
		cout << "!!Not a territory ID" << endl;
		return false;
	}
	//has to be within range of territory ids
	if (territoryId > gameMap->getNumTerritories() || territoryId < 0) {
		cout << "!!Invalid territory ID." << endl;
		return false;
	}
	//check if the territory does not belongs to the player
	if (gameMap->getTerritory(territoryId)->getOwner() == name) {
		cout << "Committing genocide upon your farming nation is not cool." << endl;
		return false;
	}
	//is the target actually a neighbour of the origin of attack
	for (int i = 0; i < origin->getNumberAdj(); i++) {
		if (origin->getAdjacent(i) == territoryId && gameMap->getTerritory(territoryId)->getOwner() != name) {
			return true;
		}
	}
	cout << "!!Selected target is not a neighbour of " << origin->getName() << endl;
	return false;
}


bool Player::validAdvanceAmount(string amount, Territory* origin) {
	int qty = 0;
	//attempt to parse user input into int
	try {
		qty = stoi(amount);
	}
	catch (const std::exception&) {
		cout << "!!Not a valid number" << endl;
	}
	//Verify that we're allowed to actually advance troops from there
	if (qty >= origin->getVirtualArmy() || qty < 1) {
		return false;
	}
	else {
		return true;
	}
}

bool Player::validReinforceAmount(string amount) {
	int qty = 0;
	//attempt to parse user input into int
	try {
		qty = stoi(amount);
	}
	catch (const std::exception&) {
		cout << "!!Not a valid number" << endl;
		return false;
	}
	//amount cannot be larger than available
	if (qty > armySize || qty == 0) {
		cout << "!!Can't reinforce by " << qty << " troops." << endl;
		return false;
	}
	//if below 0, warn user that committing war crimes is not permitted in this game, even if it's to better feed your populace
	else if (qty < 0) {
		cout << "!!Genocide is sanctioned by the Geneva conventions, and therefore not allowed." << endl;
		return false;
	}
	else {
		return true;
	}
}

bool Player::validOrder(string input) {
	int choice = 0;
	//attempt to parse user input into int
	try {
		choice = stoi(input);
	}
	catch (const std::exception&) {
		cout << "Not a valid choice" << endl;
		return false;
	}
	switch (choice) {
		//No validation needed for these options
	case OrdersList::RemoveOrder:
	case OrdersList::ChangeOrder:
	case 0:
		return true;
		//Need to validate if there are territories that can allow any advances
	case Order::Advance:
		for (int i = 0; i < territories.size(); i++) {
			if (territories[i]->getVirtualArmy() > 1) {
				return true;
			}
		}
		cout << "Cannot advance from any territory";
		return false;
	case Order::Bomb:
		cout << "Order cannot be used without a bomb card" << endl;
		return false;
	case Order::Blockade:
		cout << "Order cannot be used without a blockade card" << endl;
		return false;
	case Order::Airlift:
		cout << "Order cannot be used without an airlift card" << endl;
		return false;
	case Order::Negotiate:
		cout << "Order cannot be used without a negotiate card" << endl;
		return false;
	default:
		cout << "Not a choice" << endl;
		return false;
	}
}