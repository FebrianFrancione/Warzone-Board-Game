/*#include "PlayerStrategies.h"*/
#include <string>
#include <iostream>
using namespace std;

class PlayerStrategy {
public:
    virtual void toAttack() = 0;
    virtual void toDefend() = 0;
    virtual void issueOrder() = 0;
};

class HumanPlayerStrategy: public PlayerStrategy{
public:
    virtual void toAttack(){
        cout << "HumanPlayerStrategy toAttack player strat" << endl;
    }

    virtual void toDefend(){
        cout << "HumanPlayerStrategy toDefend player strat"<< endl;
    }
    virtual void issueOrder(){
        cout << "HumanPlayerStrategy issueOrder player strat"<< endl;
    }

};

class AggressivePlayerStrategy: public PlayerStrategy{
public:
    virtual void toAttack(){
        cout << "AggressivePlayerStrategy toAttack player strat"<< endl;
    }
    virtual void toDefend(){
        cout << "AggressivePlayerStrategy toDefend player strat"<< endl;
    }
    virtual void issueOrder(){
        cout << "AggressivePlayerStrategy issueOrder player strat"<< endl;
    }
};

class BenevolentPlayerStrategy: public PlayerStrategy{
public:
    virtual void toAttack(){
        cout << "BenevolentPlayerStrategy toAttack player strat"<< endl;
    }
    virtual void toDefend(){
        cout << "BenevolentPlayerStrategy toDefend player strat"<< endl;
    }
    virtual void issueOrder(){
        cout << "BenevolentPlayerStrategy issueOrder player strat"<< endl;
    }
};

class NeutralPlayerStrategy: public PlayerStrategy{
public:

    virtual void toAttack(){
        cout << "NeutralPlayerStrategy toAttack player strat"<< endl;
    }
    virtual void toDefend(){
        cout << "NeutralPlayerStrategy toDefend player strat"<< endl;
    }
    virtual void issueOrder(){
        cout << "NeutralPlayerStrategy issueOrder player strat"<< endl;
    }
};



/*

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
*/




