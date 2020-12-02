#pragma once

#include <string>
#include <iostream>
#include "Map.h"
#include "Player.h"
#include <iomanip>

using namespace std;

class Player;


class PlayerStrategy {
public:
/*    virtual string toAttack() = 0;
    virtual string toDefend() = 0;
    virtual string issueOrder() = 0;*/

    virtual void toAttack(string name, vector<struct Territory *> territories, Map *gameMap) = 0;
    virtual void toDefend(string name, vector<struct Territory *> territories, Map *gameMap) = 0;
    virtual void issueOrder(string name, vector<struct Territory *> territories, Map *gameMap, list<string> orders) = 0;
};

class HumanPlayerStrategy: public PlayerStrategy{
public:
    virtual void toAttack(string name, vector<struct Territory *> territories, Map *gameMap){
        cout << "**HumanPlayerStrategy** toAttack" << endl;
        cout << "The territories you can attack are: " << endl;
        for (int i = 0; i < territories.size(); i++) {
            for (int j = 0; j < territories[i]->getNumberAdj(); j++) {
                if (gameMap->getTerritory(territories[i]->getAdjacent(j))->getOwner() != name) {
                    cout <<
                         right << setw(40) << gameMap->getTerritory(territories[i]->getAdjacent(j))->getName() <<
                         " (" << setw(2) << territories[i]->getAdjacent(j) << ")" <<
                         setw(20) << " belonging to " <<
                         left << setw(20) << gameMap->getTerritory(territories[i]->getAdjacent(j))->getOwner() <<
                         " from " <<
                         right << setw(40) << territories[i]->getName() <<
                         " (" << setw(2) << territories[i]->getId() << ")" <<
                         endl;
                }
            }
        }
        cout << "--------" << endl;
    }

    virtual void toDefend(string name, vector<struct Territory *> territories, Map *gameMap, list<string> list) {
        cout << "**HumanPlayerStrategy** toDefend"<< endl;

        cout << "Your territories to defend: " << endl;
        for (int i = 0; i < territories.size(); i++) {
            cout << setw(40) << territories[i]->getName() << endl;
        }
        cout << "--------" << endl;

    }
    virtual void issueOrder(string name, vector<struct Territory *> territories, Map *gameMap){
        cout << "**HumanPlayerStrategy** IssueOrder"<< endl;
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

};

class AggressivePlayerStrategy: public PlayerStrategy{
public:

    virtual void toAttack() {
        cout << "**AggressivePlayerStrategy** toAttack"<< endl;
        cout << "Reinforce Strongest country, then attacks with it until it cannot anymore, then fortifies to maximize armies in one country" << endl;
    }

    virtual void toDefend(string name, vector<struct Territory *> territories, Map *gameMap, list<string> list) {
        cout << "**AggressivePlayerStrategy** toDefend"<< endl;
        cout << "Reinforce Strongest country, then attacks with it until it cannot anymore, then fortifies to maximize armies in one country" << endl;
    }

    virtual void issueOrder(){
        cout << "**AggressivePlayerStrategy** IssueOrder"<< endl;
        cout << "Reinforce Strongest country, then attacks with it until it cannot anymore, then fortifies to maximize armies in one country" << endl;
    }
};

class BenevolentPlayerStrategy: public PlayerStrategy{
public:
    virtual void toAttack() {
        cout << "**BenevolentPlayerStrategy** toAttack"<< endl;
        cout << "Protect weakest country, never attacks, then fortifies to move armies to weaker coutnries" << endl;
    }

    virtual void toDefend(string name, vector<struct Territory *> territories, Map *gameMap, list<string> list) {
        cout << "**BenevolentPlayerStrategy** toDefend"<< endl;
        cout << "Protect weakest country, never attacks, then fortifies to move armies to weaker coutnries" << endl;
        /*   cout << "Inside player strat " << name;*/
    }

    virtual void issueOrder(){
        cout << "**BenevolentPlayerStrategy** IssueOrder"<< endl;
        cout << "Protect weakest country, never attacks, then fortifies to move armies to weaker coutnries" << endl;
    }
};

class NeutralPlayerStrategy: public PlayerStrategy{
public:

    virtual void toAttack() {
        cout << "**NeutralPlayerStrategy** toAttack"<< endl;
        cout << "Never issues orders" << endl;
    }

    virtual void toDefend(string name, vector<struct Territory *> territories, Map *gameMap, list<string> list) {
        cout << "**NeutralPlayerStrategy** toDefend"<< endl;
    }

    virtual void issueOrder(){
        cout << "**NeutralPlayerStrategy** IssueOrder"<< endl;
    }
};














/*class Players {
public:
void setPlayerStrategy(PlayerStrategy* strat){
    this->playerstrat = strat;
}
void toAttack(){
    // if(this->playerstrat)
    this->playerstrat->toAttack();
}
private:
PlayerStrategy * playerstrat;
};*/






