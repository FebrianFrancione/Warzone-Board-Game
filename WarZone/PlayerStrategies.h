
#pragma once;

class PlayerStrategy {
public:
    virtual void toAttack();
    virtual void toDefend();
    virtual void issueOrder();
};

class HumanPlayerStrategy: public PlayerStrategy{
    virtual void toAttack();
    virtual void toDefend();
    virtual void issueOrder();
};

class AggressivePlayerStrategy: public PlayerStrategy{
    virtual void toAttack();
    virtual void toDefend();
    virtual void issueOrder();
};

class BenevolentPlayerStrategy: public PlayerStrategy{
    virtual void toAttack();
    virtual void toDefend();
    virtual void issueOrder();
};

class NeutralPlayerStrategy: public PlayerStrategy{
    virtual void toAttack();
    virtual void toDefend();
    virtual void issueOrder();
};

