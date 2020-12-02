#pragma once

#include "Map.h";

#include <iostream>

//Order superclass
class Order {
public:
	enum OrderType{Deploy, Advance, Bomb, Blockade, Airlift, Negotiate};
	//Constructors
	Order();
	Order(const Order& original);
	//Destructors
	virtual ~Order();
	//Methods
	virtual void execute() = 0;
	virtual bool validate() = 0;
	virtual Order* clone() = 0;
	//Operator overloads
	Order& operator = (const Order& order);
	friend std::ostream& operator << (std::ostream& out, const Order& order);
protected:
	//Members used by subclasses
	int type;
	bool executed;
};

//Class for Order Lists (lists by player)
class OrdersList {
public:
	//Constructors
	OrdersList();
	OrdersList(const OrdersList& originalList);
	//Destructor
	~OrdersList();
	//Methods
	void add(Order* order);
	void move(int from, int to);
	void deleteOrder(int pos);
	Order* get(int pos);
	int getSize();
	//Operator overloads
	OrdersList& operator = (const OrdersList& ordersList);
	friend std::ostream& operator << (std::ostream& out, const OrdersList& ordersList);
private:
	//Private members
	Order** theList;
	int size;
};

//================
//Order Subclasses
//================
//All subclasses follow the same structure as the superclass:
//	constructor, copy constructor, overloaded methods and overloaded input stream operator
//The execute and validate methods need to be redefined since each order type is different

class Deploy : public Order {
public:
	Deploy();
	Deploy(Territory* _territory, int qty);
	Deploy(const Deploy& original);
	~Deploy();
	void execute();
	bool validate();
	Order* clone();
	Deploy& operator= (const Deploy& deploy);
	friend std::ostream& operator << (std::ostream& out, const Deploy& deploy);
private:
	Territory* territory;
	int qty;
};

class Advance : public Order {
public:
	Advance();
	Advance(const Advance& original);
	~Advance();
	void execute();
	bool validate();
	Order* clone();
	Advance& operator= (const Advance& advance);
	friend std::ostream& operator << (std::ostream& out, const Advance& deploy);
};

class Bomb : public Order {
public:
	Bomb();
	Bomb(const Bomb& original);
	~Bomb();
	void execute();
	bool validate();
	Order* clone();
	Bomb& operator= (const Bomb& bomb);
	friend std::ostream& operator << (std::ostream& out, const Bomb& deploy);
};

class Blockade : public Order {
public:
	Blockade();
	Blockade(const Blockade& original);
	~Blockade();
	void execute();
	bool validate();
	Order* clone();
	Blockade& operator= (const Blockade& blockade);
	friend std::ostream& operator << (std::ostream& out, const Blockade& deploy);
};

class Airlift : public Order {
public:
	Airlift();
	Airlift(const Airlift& original);
	~Airlift();
	void execute();
	bool validate();
	Order* clone();
	Airlift& operator= (const Airlift& airlift);
	friend std::ostream& operator << (std::ostream& out, const Airlift& deploy);
};

class Negotiate : public Order {
public:
	Negotiate();
	Negotiate(const Negotiate& original);
	~Negotiate();
	void execute();
	bool validate();
	Order* clone();
	Negotiate& operator= (const Negotiate& negotiate);
	friend std::ostream& operator << (std::ostream& out, const Negotiate& deploy);
};
