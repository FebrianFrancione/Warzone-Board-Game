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





//player Strategies
void Player::setPlayerStrategy(PlayerStrategy* strat){
    this->playerstrat = strat;
}
//Iterates over a list of territories owned by the player and displays them


// Displays a list of surrounding territories the player can attack
void Player::toAttack() {
    this->playerstrat->toAttack(this->name, this->territories, this->gameMap, this->orders);
}

void Player::toDefend() {
    this->playerstrat->toDefend(this->name, this->territories, this->gameMap, this->orders);
    cout << " Inside player class Player name: " << this;
}

//Adds an order to the order list and displays all current orders
void Player::issueOrder() {
    this->playerstrat->issueOrder(this->name, this->territories, this->gameMap, this->orders);
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

