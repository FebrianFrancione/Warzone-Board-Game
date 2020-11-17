#pragma once

#include <iostream>
#include <list>
#include <string>

using namespace std;

//Player Class
class Player
{
public:

	//Constructors
	Player();
	Player(list<string> t, int h);
	

	//methods to attack, defend, and issue orders
	void toAttack();
	void toDefend();
	void issueOrder();

	void setName(string n);
	string getName();

	void setPlayerId(int id);
	int getPlayerId();

private:
	string name;
	int playerId;
	list<string> territories;
	int hand;
	list<string> orders;
};
