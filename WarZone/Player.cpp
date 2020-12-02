#include "Player.h"
#include "Cards.h"
#include "Map.h"

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

//Iterates over a list of territories owned by the player and displays them
void Player::toDefend() {
	cout << "Your territories: " << endl;
	for (int i = 0; i < territories.size(); i++) {
		cout << 
			right << setw(36) << territories[i]->getName() << 
			" (ID:" << setw(2) << territories[i]->getId() << ")" <<
			" (Troops:" << setw(3) << territories[i]->getVirtualArmy() << ")" <<
			endl;
	}
	cout << "--------" << endl;
}

// Displays a list of surrounding territories the player can attack
void Player::toAttack() {
	cout << "The territories you can attack are: " << endl;
	//own territories loop
	for (int i = 0; i < territories.size(); i++) {
		//adjacent territories of i loop
		for (int j = 0; j < territories[i]->getNumberAdj(); j++) {
			if (gameMap->getTerritory(territories[i]->getAdjacent(j))->getOwner() != name) {
				cout << 
					right << setw(36) << gameMap->getTerritory(territories[i]->getAdjacent(j))->getName() << 
					" (ID:" << setw(2) << territories[i]->getAdjacent(j) << ")" <<
					" (Troops:" << setw(3) << gameMap->getTerritory(territories[i]->getAdjacent(j))->getVirtualArmy() << ")" <<
					setw(20) << " belonging to " <<
					left << setw(20) << gameMap->getTerritory(territories[i]->getAdjacent(j))->getOwner() <<
					" from " <<
					right << setw(36) << territories[i]->getName() <<
					" (ID:" << setw(2) << territories[i]->getId() << ")" <<
					" (Troops:" << setw(3) << territories[i]->getVirtualArmy() << ")" <<
					endl;
			}
		}
	}
	cout << "--------" << endl;
}

//Adds an order to the order list and displays all current orders
void Player::issueOrder(int orderType, Order* order) {

	string type;
	switch (orderType) {
	case Order::Deploy:
		//orders->add(new Deploy());
		type = "Deploy";
		break;
	case Order::Advance:
		//orders->add(new Advance());
		type = "Advance";
		break;
	case Order::Bomb:
		//orders->add(new Bomb());
		type = "Bomb";
		break;
	case Order::Blockade:
		//orders->add(new Blockade());
		type = "Blockade";
		break;
	case Order::Airlift:
		//orders->add(new Airlift());
		type = "Airlift";
		break;
	case Order::Negotiate:
		//orders->add(new Negotiate());
		type = "Negotiate";
		break;
	default:
		cout << "Invalid Order type" << endl;
		break;
	}
	orders->add(order);
	cout << type << " order added to " << name << "'s list" << endl;
	cout << "List of all orders:" << endl;
	for (int i = 0; i < orders->getSize(); i++) {
		cout << i + 1 << ": " << *(orders->get(i)) << endl;
	}
	cout << endl;
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

