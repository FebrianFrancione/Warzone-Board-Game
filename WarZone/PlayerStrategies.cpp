/*
//
// Created by febri on 01/12/2020.
//

#include "PlayerStrategies.h"
#include "Player.h"


  void PlayerStrategy::toDefend() {
    cout << "Base player to Defend" <<endl;
    */
/*    cout << "Your territories to defend: " << endl;*//*

      */
/*  for (int i = 0; i < territories.size(); i++) {
            cout << setw(40) << territories[i]->getName() << endl;
        }
        cout << "--------" << endl;*//*

    }

// Displays a list of surrounding territories the player can attack
    void PlayerStrategy::toAttack() {
    cout << "Base player to Attack" <<endl;
       */
/* cout << "The territories you can attack are: " << endl;
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
        cout << "--------" << endl;*//*

    }

//Adds an order to the order list and displays all current orders
   void PlayerStrategy::issueOrder() {
    cout << "Base player issueOrder "<<endl;
    */
/*
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
        cout << endl;*//*

    }


void HumanPlayerStrategy::toDefend() {
    cout << "HumanPlayerStrategy player to Defend" <<endl;
    */
/*    cout << "Your territories to defend: " << endl;*//*

    */
/*  for (int i = 0; i < territories.size(); i++) {
          cout << setw(40) << territories[i]->getName() << endl;
      }
      cout << "--------" << endl;*//*

}

// Displays a list of surrounding territories the player can attack
void HumanPlayerStrategy::toAttack() {
    cout << "HumanPlayerStrategy player to Attack" <<endl;
    */
/* cout << "The territories you can attack are: " << endl;
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
     cout << "--------" << endl;*//*

}

//Adds an order to the order list and displays all current orders
void HumanPlayerStrategy::issueOrder() {
    cout << "HumanPlayerStrategy player issueOrder "<<endl;
    */
/*
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
        cout << endl;*//*

}
*/
#include <string>

#include <iostream>
using namespace std;


class PlayerStrategy {
public:
    virtual void toAttack()=0;
/*    virtual void toDefend();
    virtual void issueOrder();*/
};

class HumanPlayerStrategy: public PlayerStrategy{
    virtual void toAttack(){
        cout << "human player strat";
    }
/*    virtual void toDefend();
    virtual void issueOrder();*/
};

class AggressivePlayerStrategy: public PlayerStrategy{
    virtual void toAttack(){
        cout << "Aggressive player strat";
    }
    /*  virtual void toDefend();
      virtual void issueOrder();*/
};

/*class BenevolentPlayerStrategy: public PlayerStrategy{
    virtual void toAttack();
    virtual void toDefend();
    virtual void issueOrder();
};*/

/*class NeutralPlayerStrategy: public PlayerStrategy{
    virtual void toAttack();
    virtual void toDefend();
    virtual void issueOrder();
};*/

class Players {
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
};
int main(){
    Players player1;
    AggressivePlayerStrategy aggro;
    player1.setPlayerStrategy(&aggro);
    player1.toAttack();
    /*Players player1;
    player1.toAttack();*/
/*    AggressivePlayerStrategy *aggro = new AggressivePlayerStrategy;

    player1.toAttack();*/
}



