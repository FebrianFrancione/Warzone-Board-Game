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

    virtual void toAttack() = 0;
    virtual void toDefend() = 0;
    virtual void issueOrder() = 0;
};

class HumanPlayerStrategy: public PlayerStrategy{
public:
    virtual void toAttack(){
        cout << "**HumanPlayerStrategy** toAttack" << endl;

/*
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
*/

    }

    virtual void toDefend(){
        cout << "**HumanPlayerStrategy** toDefend"<< endl;
    }
    virtual void issueOrder(){
        cout << "**HumanPlayerStrategy** IssueOrder"<< endl;
    }

};

class AggressivePlayerStrategy: public PlayerStrategy{
public:

    virtual void toAttack(){
        cout << "**AggressivePlayerStrategy** toAttack"<< endl;
    }

    virtual void toDefend(){
        cout << "**AggressivePlayerStrategy** toDefend"<< endl;
    }

    virtual void issueOrder(){
        cout << "**AggressivePlayerStrategy** IssueOrder"<< endl;
    }
};

class BenevolentPlayerStrategy: public PlayerStrategy{
public:
    virtual void toAttack(){
        cout << "**BenevolentPlayerStrategy** toAttack"<< endl;
    }

    virtual void toDefend(){
        cout << "**BenevolentPlayerStrategy** toDefend"<< endl;
    }

    virtual void issueOrder(){
        cout << "**BenevolentPlayerStrategy** IssueOrder"<< endl;
    }
};

class NeutralPlayerStrategy: public PlayerStrategy{
public:

    virtual void toAttack(){
        cout << "**NeutralPlayerStrategy** toAttack"<< endl;
    }

    virtual void toDefend(){
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






