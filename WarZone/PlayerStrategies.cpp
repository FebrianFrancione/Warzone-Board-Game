#include "PlayerStrategies.h"

#include <string>
#include <iostream>
#include "Map.h"
#include "Player.h"
#include <iomanip>

using namespace std;

class Player;

void HumanPlayerStrategy::toAttack(Player* player, Map* gameMap) {
	cout << "**HumanPlayerStrategy** toAttack" << endl;
	cout << "The territories you can attack are: " << endl;
	bool hasAtLeastOneTarget = false;
	//Outter loop i -> index of the players own territories
	for (int i = 0; i < player->territories.size(); i++) {
		if (gameMap->getTerritory(i)->getVirtualArmy() < 2) {
			continue;
		}
		hasAtLeastOneTarget = true;
		//inner loop j -> index of the territories adjacent to territory[i]
		for (int j = 0; j < player->territories[i]->getNumberAdj(); j++) {
			//for each neighbour, if it belongs to an enemy
			if (gameMap->getTerritory(player->territories[i]->getAdjacent(j))->getOwner() != player->getName()) {
				//Output full line
				cout << right << setw(36) << gameMap->getTerritory(player->territories[i]->getAdjacent(j))->getName();//enemy territory
				cout << " (" << setw(2) << player->territories[i]->getAdjacent(j) << ")";//id of enemy territory
				cout << " (" << "Troops: " << setw(3) << gameMap->getTerritory(player->territories[i]->getAdjacent(j))->getVirtualArmy() << ")";//troop count
				cout << setw(20) << " belonging to ";
				cout << left << setw(20) << gameMap->getTerritory(player->territories[i]->getAdjacent(j))->getOwner();//owner of enemy territory
				cout << " from ";
				cout << right << setw(36) << player->territories[i]->getName();//your territory
				cout << " (" << setw(2) << player->territories[i]->getId() << ")";//id
				cout << " (" << "Troops: " << setw(3) << player->territories[i]->getVirtualArmy() << ")";//troop count
				cout << endl;
			}
		}
	}
	cout << "--------" << endl;
	if (hasAtLeastOneTarget) {
		string input;
		int qty;
		Territory* origin;
		Territory* destination;
		//select origin
		cout << "Select territory to attack from >> ";
		getline(cin, input);
		while (!player->validTerritoryAttack(input)) {
			cout << "!!Enter a valid territory ID to attack from >> ";
			getline(cin, input);
		}
		origin = gameMap->getTerritory(stoi(input));
		//select target
		cout << "Select territory to target for attack >> ";
		getline(cin, input);
		while (!player->validTerritoryAttackTarget(input, origin)) {
			cout << "!!Enter a valid territory ID to target for attack >> ";
			getline(cin, input);
		}
		destination = gameMap->getTerritory(stoi(input));
		cout << "Number of troops to attack with >> ";
		//Get number of troops to transfer
		getline(cin, input);
		while (!player->validAdvanceAmount(input, origin)) {
			cout << "Enter a valid number of troops >> ";
			getline(cin, input);
		}
		qty = stoi(input);
		//Create the advance order
		player->addOrder(new Advance(origin, destination, qty, player->getName(), destination->getOwner()));
		//Update virtual army count
		origin->removeVirtualTroops(qty);
	}
}

void HumanPlayerStrategy::toDefend(Player* player, Map* gameMap) {
	cout << "**HumanPlayerStrategy** toDefend" << endl;
	cout << "The territories you can transfer between are: " << endl;
	bool hasAtLeastOneTarget = false;
	//Outter loop i -> index of the players own territories
	for (int i = 0; i < player->territories.size(); i++) {
		if (gameMap->getTerritory(i)->getVirtualArmy() < 2) {
			continue;
		}
		hasAtLeastOneTarget = true;
		//inner loop j -> index of the territories adjacent to territory[i]
		for (int j = 0; j < player->territories[i]->getNumberAdj(); j++) {
			//for each neighbour, if it belongs to yourself
			if (gameMap->getTerritory(player->territories[i]->getAdjacent(j))->getOwner() == player->getName()) {
				//Output full line
				cout << right << setw(36) << gameMap->getTerritory(player->territories[i]->getAdjacent(j))->getName();//own neighbour 
				cout << " (" << setw(2) << player->territories[i]->getAdjacent(j) << ")";//id
				cout << " (" << "Troops: " << setw(3) << gameMap->getTerritory(player->territories[i]->getAdjacent(j))->getVirtualArmy() << ")";//troop count
				cout << setw(25) << " can be reinforced from ";
				cout << right << setw(36) << player->territories[i]->getName();//your territory origin
				cout << " (" << setw(2) << player->territories[i]->getId() << ")";//id
				cout << " (" << "Troops: " << setw(3) << player->territories[i]->getVirtualArmy() << ")";//troop count
				cout << endl;
			}
		}
	}
	cout << "--------" << endl;
	if (hasAtLeastOneTarget) {
		string input;
		int qty;
		Territory* origin;
		Territory* destination;
		//Select origin of transfer
		cout << "Select territory to transfer from >> ";
		getline(cin, input);
		while (!player->validTerritoryDefend(input)) {
			cout << "!!Enter a valid territory ID to transfer from >> ";
			getline(cin, input);
		}
		origin = gameMap->getTerritory(stoi(input));
		//Select target of transfer
		cout << "Select territory to transfer to>>";
		getline(cin, input);
		while (!player->validTerritoryTransferTarget(input, origin)) {
			cout << "!!Enter a valid territory ID to transfer too >> ";
			getline(cin, input);
		}
		destination = gameMap->getTerritory(stoi(input));
		cout << "Number of troops to transfer >> ";
		//Get number of troops to transfer
		getline(cin, input);
		while (!player->validAdvanceAmount(input, origin)) {
			cout << "Enter a valid number of troops >> ";
			getline(cin, input);
		}
		qty = stoi(input);
		//Create the advance order
		player->addOrder(new Advance(origin, destination, qty, player->getName(), destination->getOwner()));
		//Update virtual army count
		origin->removeVirtualTroops(qty);
	}
}

void HumanPlayerStrategy::toDeploy(Player* player, Map* gameMap) {
	cout << "**HumanPlayerStrategy** toDeploy" << endl;
	string input;
	int selectId = 0;
	//while there are troops left to deploy
	cout << player->getPlayerArmySize() << " troops left to deploy." << endl;
	//List all owned territories
	player->printPlayerTerritories();
	//Get id of territory to deploy to
	cout << "Enter a territory ID to deploy to >> ";
	getline(cin, input);
	while (!player ->validTerritoryDeploy(input)) {
		cout << "Enter a valid territory ID >> ";
		getline(cin, input);
	}
	selectId = stoi(input);
	//Get amount of troops to deploy
	cout << "Number of troops to deploy >> ";
	getline(cin, input);
	while (!player->validReinforceAmount(input)) {
		cout << "Enter a valid number of troops to deploy >> ";
		getline(cin, input);
	}
	//Output message
	cout << "Adding " << input << " troops to " << gameMap->getTerritory(selectId)->getName() << endl;
	//Update reinforcement pool number of people
	player->subtractReinforcements(stoi(input));
	//update virtual troops count
	gameMap->getTerritory(selectId)->addVirtualTroops(stoi(input));
	//Add the deploy order to the list of orders
	player->addOrder(new Deploy(gameMap->getTerritory(selectId), stoi(input)));
}

void HumanPlayerStrategy::issueOrder(Player* player, Map* gameMap) {
	cout << "**HumanPlayerStrategy** IssueOrder" << endl;
	string input;
	cout << endl << "============" << endl;
	cout << player->getName() << "'s turn to issue orders." << endl;
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
		while (!player->validOrder(input)) {
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
				player->toAttack();
			}
			//transfer
			else if (input == "t" || input == "T") {
				player->toDefend();
			}
			//If the player didnt select attack or transfer, break out
			else {
				break;
			}
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

void AggressivePlayerStrategy::toAttack(Player* player, Map* gameMap) {
	cout << "**AggressivePlayerStrategy** toAttack" << endl;
	cout
		<< "Reinforce Strongest country, then attacks with it until it cannot anymore, then fortifies to maximize armies in one country"
		<< endl;
}

void AggressivePlayerStrategy::toDefend(Player* player, Map* gameMap) {
	cout << "**AggressivePlayerStrategy** toDefend" << endl;
	cout
		<< "Reinforce Strongest country, then attacks with it until it cannot anymore, then fortifies to maximize armies in one country"
		<< endl;
}

void AggressivePlayerStrategy::toDeploy(Player* player, Map* gameMap) {
	
}

void AggressivePlayerStrategy::issueOrder(Player* player, Map* gameMap) {
	cout << "**AggressivePlayerStrategy** IssueOrder" << endl;
	cout
		<< "Reinforce Strongest country, then attacks with it until it cannot anymore, then fortifies to maximize armies in one country"
		<< endl;
}

void BenevolentPlayerStrategy::toAttack(Player* player, Map* gameMap) {
	cout << "**BenevolentPlayerStrategy** toAttack" << endl;
	cout << "Protect weakest country, never attacks, then fortifies to move armies to weaker coutnries" << endl;
}

void BenevolentPlayerStrategy::toDefend(Player* player, Map* gameMap) {
	cout << "**BenevolentPlayerStrategy** toDefend" << endl;
	cout << "Protect weakest country, never attacks, then fortifies to move armies to weaker coutnries" << endl;
	/*   cout << "Inside player strat " << name;*/
}

void BenevolentPlayerStrategy::toDeploy(Player* player, Map* gameMap) {
}

void BenevolentPlayerStrategy::issueOrder(Player* player, Map* gameMap) {
	cout << "**BenevolentPlayerStrategy** IssueOrder" << endl;
	cout << "Protect weakest country, never attacks, then fortifies to move armies to weaker coutnries" << endl;
}

void NeutralPlayerStrategy::toAttack(Player* player, Map* gameMap) {
	cout << "**NeutralPlayerStrategy** toAttack" << endl;
	cout << "Never issues orders" << endl;
}

void NeutralPlayerStrategy::toDefend(Player* player, Map* gameMap) {
	cout << "**NeutralPlayerStrategy** toDefend" << endl;
}

void NeutralPlayerStrategy::toDeploy(Player* player, Map* gameMap) {
}

void NeutralPlayerStrategy::issueOrder(Player* player, Map* gameMap) {
	cout << "**NeutralPlayerStrategy** IssueOrder" << endl;
}
