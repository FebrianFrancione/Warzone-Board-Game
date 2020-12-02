
#include "Player.h"

int main(){
    Player player1("name", 0, 0);
    AggressivePlayerStrategy aggroStrat;
    HumanPlayerStrategy humanStrat;
    BenevolentPlayerStrategy benevolentStrat;
    NeutralPlayerStrategy neutralStrat;

    player1.setPlayerStrategy(&aggroStrat);
    player1.toAttack();
    player1.toDefend();
    player1.issueOrder();

    player1.setPlayerStrategy(&humanStrat);
    player1.toAttack();
    player1.toDefend();
    player1.issueOrder();

    player1.setPlayerStrategy(&benevolentStrat);
    player1.toAttack();
    player1.toDefend();
    player1.issueOrder();

    player1.setPlayerStrategy(&neutralStrat);
    player1.toAttack();
    player1.toDefend();
    player1.issueOrder();

    /*Players player1;
    player1.toAttack();*/
/*    AggressivePlayerStrategy *aggro = new AggressivePlayerStrategy;

    player1.toAttack();*/
}
