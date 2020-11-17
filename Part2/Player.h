#pragma once

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

//Player Class
class Player
{
public:

	//Constructors
	/*Player();*/
	Player(std::string n, int id, int army);

	Player(std::string n, int id, int army, list<string> t, int h);

	/*Player(list<string> t, int h);*/
	~Player();

	//methods to attack, defend, and issue orders
	void toAttack();
	void toDefend();
	void issueOrder();

	void setName(string n);
	string getName();

	void setPlayerTurnId(int id);
	int getPlayerTurnId();

	void setPlayerArmySize(int army);
	int getPlayerArmySize();

	vector<string>playerTerritories;
	list<string> territories;
private:
	int armySize;
	std::string name;
	int playerTurnId;
	
	int hand;
	list<string> orders;
};
