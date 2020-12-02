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
	string input;
	int selectId;
	//while there are troops left to deploy
	cout << armySize << " troops left to deploy." << endl;
	//List all owned territories
	printPlayerTerritories();
	//Get id of territory to deploy to
	cout << "Enter a territory ID to deploy to >> ";
	getline(cin, input);
	while (!validTerritoryDeploy(input)) {
		cout << "Enter a valid territory ID >> ";
		getline(cin, input);
	}
	selectId = stoi(input);
	//Get amount of troops to deploy
	cout << "Number of troops to deploy >> ";
	getline(cin, input);
	while (!validReinforceAmount(input)) {
		cout << "Enter a valid number of troops to deploy >> ";
		getline(cin, input);
	}
	//Output message
	cout << "Adding " << input << " troops to " << gameMap->getTerritory(selectId)->getName() << endl;
	//Update reinforcement pool number of people
	armySize -= stoi(input);
	//update virtual troops count
	gameMap->getTerritory(selectId)->setVirtualArmy(gameMap->getTerritory(selectId)->getVirtualArmy() + stoi(input));
	//Add the deploy order to the list of orders
	orders->add(new Deploy(gameMap->getTerritory(selectId), stoi(input)));
}

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

// Displays a list of surrounding territories the player can attack
void Player::toAttack() {

	cout << "The territories you can attack are: " << endl;
	//own territories loop
	this->playerstrat->toAttack();
/*  cout << "The territories you can attack are: " << endl;
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
	cout << "--------" << endl;*/
}

void Player::toDefend() {
    this->playerstrat->toDefend();
    /*cout << "Your territories to defend: " << endl;
    for (int i = 0; i < territories.size(); i++) {
        cout << setw(40) << territories[i]->getName() << endl;
    }
    cout << "--------" << endl;*/
}

//Adds an order to the order list and displays all current orders
void Player::issueOrder() {
  this->playerstrat->issueOrder();
  //EVERYTHING AFTER THIS NEEDS TO BE MOVED INTO THE PLAYER STRATEGY INSTEAD FOR HUMANS
	string input;
	cout << endl << "============" << endl;
	cout << name << "'s turn to issue orders." << endl;
	//So long as the player isn't done and select option 0
	int option = 1;
	while (option != 0) {
		//ouput menu
		cout << "Orders: " << endl;
		cout << Order::Advance << " - Advance" << endl;
		cout << Order::Bomb << " - Airlift" << endl;
		cout << Order::Blockade << " - Bomb" << endl;
		cout << Order::Airlift << " - Blockade" << endl;
		cout << Order::Negotiate << " - Negotiate" << endl;
		cout << OrdersList::RemoveOrder << " - Remove Order" << endl;
		cout << OrdersList::ChangeOrder << " - Change Order" << endl;
		cout << "0 - Finish" << endl;
		cout << " >> ";
		//get user choice and validate it
		getline(cin, input);
		while (!validOrder(input)) {
			cout << " >> ";
			getline(cin, input);
		}
		option = stoi(input);
		Territory* origin = new Territory();
		Territory* destination = new Territory();
		int qty = 0;
		//Depending on the choice, act accordingly
		switch (option) {
		case Order::Advance:
			//decide whether the player wishes to attack or transfer troops in advance command
			cout << "Attack or Transfer (A to attack, T to transfer, anything else to cancel) >> ";
			getline(cin, input);
			//attack
			if (input == "a" || input == "A") {
				toAttack();
				//select origin
				cout << "Select territory to attack from >> ";
				getline(cin, input);
				/*while (!validTerritoryAttack(input, players[i])) {
					cout << "!!Enter a valid territory ID to attack from >> ";
					getline(cin, input);
				}*/
				origin = gameMap->getTerritory(stoi(input));
				//select target
				cout << "Select territory to target for attack >> ";
				getline(cin, input);
				/*while (!validTerritoryAttackTarget(input, origin, players[i])) {
					cout << "!!Enter a valid territory ID to target for attack >> ";
					getline(cin, input);
				}*/
				destination = gameMap->getTerritory(stoi(input));
				cout << "Number of troops to attack with >> ";
			}
			//transfer
			else if (input == "t" || input == "T") {
				toDefend();
				//Select origin of transfer
				cout << "Select territory to transfer from >> ";
				getline(cin, input);
				/*while (!validTerritoryDefend(input, players[i])) {
					cout << "!!Enter a valid territory ID to transfer from >> ";
					getline(cin, input);
				}*/
				origin = gameMap->getTerritory(stoi(input));
				//Select target of transfer
				cout << "Select territory to transfer to>>";
				getline(cin, input);
				/*while (!validTerritoryTransferTarget(input, origin, players[i])) {
					cout << "!!Enter a valid territory ID to transfer too >> ";
					getline(cin, input);
				}*/
				destination = gameMap->getTerritory(stoi(input));
				cout << "Number of troops to transfer >> ";
			}
			//If the player didnt select attack or transfer, break out
			else {
				break;
			}
			//This reaches only if the player attacked or transfered successfully
			//Get number of troops to transfer
			getline(cin, input);
			/*while (!validAdvanceAmount(input, origin)) {
				cout << "Enter a valid number of troops >> ";
				getline(cin, input);
			}*/
			qty = stoi(input);
			//Create the advance order
			//players[i]->issueOrder(Order::Advance, new Advance(origin, destination, qty, players[i]->getName(), destination->getOwner()));
			orders->add(new Advance(origin, destination, qty, name, destination->getOwner()));
			//Update virtual army count
			origin->setVirtualArmy(origin->getVirtualArmy() - qty);
			break;
		case Order::Bomb:
			break;
		case Order::Blockade:
			break;
		case Order::Airlift:
			break;
		case Order::Negotiate:
			break;
		case OrdersList::RemoveOrder:
			break;
		case OrdersList::ChangeOrder:
			break;
		default:
			break;
		}
	}

	//string type;
	//switch (orderType) {
	//case Order::Deploy:
	//	//orders->add(new Deploy());
	//	type = "Deploy";
	//	break;
	//case Order::Advance:
	//	//orders->add(new Advance());
	//	type = "Advance";
	//	break;
	//case Order::Bomb:
	//	//orders->add(new Bomb());
	//	type = "Bomb";
	//	break;
	//case Order::Blockade:
	//	//orders->add(new Blockade());
	//	type = "Blockade";
	//	break;
	//case Order::Airlift:
	//	//orders->add(new Airlift());
	//	type = "Airlift";
	//	break;
	//case Order::Negotiate:
	//	//orders->add(new Negotiate());
	//	type = "Negotiate";
	//	break;
	//default:
	//	cout << "Invalid Order type" << endl;
	//	break;
	//}
	//orders->add(order);
	//cout << type << " order added to " << name << "'s list" << endl;
	//cout << "List of all orders:" << endl;
	//for (int i = 0; i < orders->getSize(); i++) {
	//	cout << i + 1 << ": " << *(orders->get(i)) << endl;
	//}
	//cout << endl;
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
	if (territoryId > gameMap->getNumTerritories() || territoryId < 0) {
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