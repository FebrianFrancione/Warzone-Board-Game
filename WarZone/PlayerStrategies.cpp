#include "PlayerStrategies.h"
#include <string>
#include <iostream>
using namespace std;





void PlayerStrategy::toAttack() {};
void PlayerStrategy::toDefend() {};
void PlayerStrategy::issueOrder() {};


class PlayerStrategy;
class HumanPlayerStrategy;
class AggressivePlayerStrategy;
class BenevolentPlayerStrategy;
class NeutralPlayerStrategy;

void HumanPlayerStrategy::HumanPlayerStrategy::toAttack(){
    cout << "HumanPlayerStrategy toAttack player strat";
}
void HumanPlayerStrategy::HumanPlayerStrategy::toDefend(){
    cout << "HumanPlayerStrategy toDefend player strat";
}
void HumanPlayerStrategy::HumanPlayerStrategy::issueOrder(){
    cout << "HumanPlayerStrategy issueOrder player strat";
}



void AggressivePlayerStrategy::toAttack(){
    cout << "AggressivePlayerStrategy toAttack player strat";
}
void AggressivePlayerStrategy::toDefend(){
    cout << "AggressivePlayerStrategy toDefend player strat";
}
void AggressivePlayerStrategy::issueOrder(){
    cout << "AggressivePlayerStrategy issueOrder player strat";
}



void BenevolentPlayerStrategy::toAttack(){
    cout << "BenevolentPlayerStrategy toAttack player strat";
}
void BenevolentPlayerStrategy::toDefend(){
    cout << "BenevolentPlayerStrategy toDefend player strat";
}
void BenevolentPlayerStrategy::issueOrder(){
    cout << "BenevolentPlayerStrategy issueOrder player strat";
}



void NeutralPlayerStrategy::toAttack(){
    cout << "NeutralPlayerStrategy toAttack player strat";
}
void NeutralPlayerStrategy::toDefend(){
    cout << "NeutralPlayerStrategy toDefend player strat";
}
void NeutralPlayerStrategy::issueOrder(){
    cout << "NeutralPlayerStrategy issueOrder player strat";
}

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




