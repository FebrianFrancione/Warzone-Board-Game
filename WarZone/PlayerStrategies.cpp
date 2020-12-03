#include "PlayerStrategies.h"

#include <string>
#include <iostream>
#include "Map.h"
#include "Player.h"
#include <iomanip>

using namespace std;

class Player;

void HumanPlayerStrategy::toAttack(Player* player, Map* gameMap, Territory* origin, Territory* destination) {
	cout << "**HumanPlayerStrategy** toAttack" << endl;
	cout << "The territories you can attack are: " << endl;
	for (int i = 0; i < player->territories.size(); i++) {
		for (int j = 0; j < player->territories[i]->getNumberAdj(); j++) {
			if (gameMap->getTerritory(player->territories[i]->getAdjacent(j))->getOwner() != player->getName()) {
				cout <<
					right << setw(40) << gameMap->getTerritory(player->territories[i]->getAdjacent(j))->getName() <<
					" (" << setw(2) << player->territories[i]->getAdjacent(j) << ")" <<
					setw(20) << " belonging to " <<
					left << setw(20) << gameMap->getTerritory(player->territories[i]->getAdjacent(j))->getOwner() <<
					" from " <<
					right << setw(40) << player->territories[i]->getName() <<
					" (" << setw(2) << player->territories[i]->getId() << ")" <<
					endl;
			}
		}
	}
	cout << "--------" << endl;
}

void HumanPlayerStrategy::toDefend(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders) {
	cout << "**HumanPlayerStrategy** toDefend" << endl;

	cout << "Your territories to defend: " << endl;
	for (int i = 0; i < territories.size(); i++) {
		cout << setw(40) << territories[i]->getName() << endl;
	}

	cout << "***********************" << endl;
	cout << "Enter the territory you want to Defend:" << endl;
	for (int i = 0; i < territories.size(); i++) {
		cout << territories[i]->getName() << endl;
	}
	cout << "--------" << endl;
}

void HumanPlayerStrategy::toDeploy(Player* thePlayer, Map* gameMap) {
	cout << "**HumanPlayerStrategy** toDeploy" << endl;
	string input;
	int selectId;
	//while there are troops left to deploy
	cout << thePlayer->getPlayerArmySize() << " troops left to deploy." << endl;
	//List all owned territories
	thePlayer->printPlayerTerritories();
	//Get id of territory to deploy to
	cout << "Enter a territory ID to deploy to >> ";
	getline(cin, input);
	while (!thePlayer->validTerritoryDeploy(input)) {
		cout << "Enter a valid territory ID >> ";
		getline(cin, input);
	}
	selectId = stoi(input);
	//Get amount of troops to deploy
	cout << "Number of troops to deploy >> ";
	getline(cin, input);
	while (!thePlayer->validReinforceAmount(input)) {
		cout << "Enter a valid number of troops to deploy >> ";
		getline(cin, input);
	}
	//Output message
	cout << "Adding " << input << " troops to " << gameMap->getTerritory(selectId)->getName() << endl;
	//Update reinforcement pool number of people
	thePlayer->subtractReinforcements(stoi(input));
	//update virtual troops count
	gameMap->getTerritory(selectId)->addVirtualTroops(stoi(input));
	//Add the deploy order to the list of orders
	//player->orders->add(new Deploy(gameMap->getTerritory(selectId), stoi(input)));
}

void HumanPlayerStrategy::issueOrder(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders) {
	cout << "**HumanPlayerStrategy** IssueOrder" << endl;
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
		//while (!validOrder(input)) {
		//	cout << " >> ";
		//	getline(cin, input);
		//}
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
				//toAttack();
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
				//toDefend();
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

void AggressivePlayerStrategy::toAttack(Player* player, Map* gameMap, Territory* origin, Territory* destination) {
	cout << "**AggressivePlayerStrategy** toAttack" << endl;
	cout
		<< "Reinforce Strongest country, then attacks with it until it cannot anymore, then fortifies to maximize armies in one country"
		<< endl;
}

void AggressivePlayerStrategy::toDefend(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders) {
	cout << "**AggressivePlayerStrategy** toDefend" << endl;
	cout
		<< "Reinforce Strongest country, then attacks with it until it cannot anymore, then fortifies to maximize armies in one country"
		<< endl;
}

void AggressivePlayerStrategy::toDeploy(Player* player, Map* gameMap) {
	
}

void AggressivePlayerStrategy::issueOrder(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders) {
	cout << "**AggressivePlayerStrategy** IssueOrder" << endl;
	cout
		<< "Reinforce Strongest country, then attacks with it until it cannot anymore, then fortifies to maximize armies in one country"
		<< endl;
}

void BenevolentPlayerStrategy::toAttack(Player* player, Map* gameMap, Territory* origin, Territory* destination) {
	cout << "**BenevolentPlayerStrategy** toAttack" << endl;
	cout << "Protect weakest country, never attacks, then fortifies to move armies to weaker coutnries" << endl;
}

void BenevolentPlayerStrategy::toDefend(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders) {
	cout << "**BenevolentPlayerStrategy** toDefend" << endl;
	cout << "Protect weakest country, never attacks, then fortifies to move armies to weaker coutnries" << endl;
	/*   cout << "Inside player strat " << name;*/
}

void BenevolentPlayerStrategy::toDeploy(Player* player, Map* gameMap) {
}

void BenevolentPlayerStrategy::issueOrder(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders) {
	cout << "**BenevolentPlayerStrategy** IssueOrder" << endl;
	cout << "Protect weakest country, never attacks, then fortifies to move armies to weaker coutnries" << endl;
}

void NeutralPlayerStrategy::toAttack(Player* player, Map* gameMap, Territory* origin, Territory* destination) {
	cout << "**NeutralPlayerStrategy** toAttack" << endl;
	cout << "Never issues orders" << endl;
}

void NeutralPlayerStrategy::toDefend(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders) {
	cout << "**NeutralPlayerStrategy** toDefend" << endl;
}

void NeutralPlayerStrategy::toDeploy(Player* player, Map* gameMap) {
}

void NeutralPlayerStrategy::issueOrder(string name, vector<Territory*> territories, Map* gameMap, OrdersList* orders) {
	cout << "**NeutralPlayerStrategy** IssueOrder" << endl;
}
