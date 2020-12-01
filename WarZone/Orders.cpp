#include "Orders.h"
#include <iostream>
using namespace std;

//================
//	Order
//================

//Default Constructor (no type)
Order::Order() {
	type = -1;
	executed = false;
}

//Copy constructor
Order::Order(const Order& original) {
	type = original.type;
	executed = original.executed;
}

//Destructor
//Default
Order::~Order() {}

//Assignment operator
Order& Order::operator=(const Order& order) {
	if (&order == this) {
		return *this;
	}
	type = order.type;
	executed = order.executed;
	return *this;
}

//"to string" (stream operator overload for output)
//Returns order type ID (which for superclass is none)
ostream& operator<<(ostream& out, const Order& order) {
	return (out << "Order of type " << order.type << " execution state: " << order.executed);
}

//================
//	Orders List
//================

//Default constructor
OrdersList::OrdersList() {
	size = 0;
	theList = new Order*[size];
}

//Copy constructor
OrdersList::OrdersList(const OrdersList& originalList) {
	cout << "OrdersList Copy constructor called" << endl;
	size = originalList.size;
	theList = new Order*[size];
	for (int i = 0; i < size; i++) {
		theList[i] = originalList.theList[i]->clone();
	}
}

//Destructor
OrdersList::~OrdersList() {
	cout << "OrdersList Destructor called" << endl;
	for (int i = 0; i < size; i++) {
		delete theList[i];
	}
	delete [] theList;
};

//Move order from start position to end position
void OrdersList::move(int start, int end) {
	if (start == end || start < 0 || start > size || end < 0 || end > size) {
		cout << "Cannot move order from pos " << start << " to pos " << end << endl;
		return;
	}
	//Moving it down the list, we need to shift everything after
	if (start < end) {
		Order* temp = theList[start];
		for (int i = start; i < end; i++) {
			theList[i] = theList[i + 1];
		}
		theList[end] = temp;
	}
	//Moving it up the list, we need to shift everything before
	else if(start > end){
		Order* temp = theList[start];
		for (int i = start; i > end; i--) {
			theList[i] = theList[i - 1];
		}
		theList[end] = temp;
	}
}

//Delete an order from the list
void OrdersList::deleteOrder(int pos) {
	//Move it to the end delete it
	move(pos, size - 1);
	delete theList[size - 1];
	//Copy data into new smaller array
	size--;
	Order** newList = new Order * [size];
	for (int i = 0; i < size; i++) {
		newList[i] = theList[i];// ->clone();
	}
	//Delete old list and point to new list
	delete theList;
	theList = newList;
}

//Add a new order to a list
void OrdersList::add(Order* newOrder) {
	size++;
	Order** newList = new Order*[size];
	for (int i = 0; i < size - 1; i++) {
		newList[i] = theList[i];
	}
	newList[size - 1] = newOrder->clone();
	delete theList;
	theList = newList;
}

//Get a specific order from the list
Order* OrdersList::get(int pos) {
	return theList[pos];
}

//Assignment operator
OrdersList& OrdersList::operator=(const OrdersList& ordersList) {
	if (&ordersList == this) {
		return *this;
	}
	cout << "OrdersList Assignment Operator called" << endl;
	size = ordersList.size;
	theList = new Order* [size];
	for (int i = 0; i < size; i++) {
		theList[i] = ordersList.theList[i]->clone();
	}
	return *this;
}

//toString
ostream& operator<<(ostream& out, const OrdersList& ordersList) {
	out << "List of orders: " << endl;
	for (int i = 0; i < ordersList.size; i++)
	{
		out << "Order #" << i + 1 << ": " << *(ordersList.theList[i]) << endl;
	}
	return out;
}

//================
//	Deploy
//================

Deploy::Deploy() {
	executed = false;
	type = OrderType::Deploy;
}

Deploy::Deploy(const Deploy& original) {
	executed = original.executed;
	type = original.type;
}

//Destructor
Deploy::~Deploy() {};

void Deploy::execute() {
	if (this->validate()) {
		cout << "Executing deploy order.\n";
		executed = true;
	}
}
bool Deploy::validate() {
	return !executed;
}

Order* Deploy::clone() {
	Deploy* newDeployOrder = new Deploy();
	newDeployOrder->type = this->type;
	newDeployOrder->executed = this->executed;
	return (Order*)newDeployOrder;
}

Deploy& Deploy::operator= (const Deploy& deploy) {
	if (&deploy == this) {
		return *this;
	}
	executed = deploy.executed;
	type = deploy.type;
	return *this;
}

ostream& operator<<(ostream& out, const Deploy& deploy) {
	return out << "This is a deploy order";
}

//================
//	Advance
//================

Advance::Advance() {
	executed = false;
	type = OrderType::Advance;
}

Advance::Advance(const Advance& original) {
	executed = original.executed;
	type = original.type;
}

Advance::~Advance() {};

void Advance::execute() {
	if (this->validate()) {
		cout << "Executing advance/attack/transfer order.\n";
		executed = true;
	}
}
bool Advance::validate() {
	return !executed;
}

Order* Advance::clone() {
	Advance* newAdvanceOrder = new Advance();
	newAdvanceOrder->type = this->type;
	newAdvanceOrder->executed = this->executed;
	return (Order*)newAdvanceOrder;
}

Advance& Advance::operator=(const Advance& advance){
	if (&advance == this) {
		return *this;
	}
	executed = advance.executed;
	type = advance.type;
	return *this;
}

ostream& operator<<(ostream& out, const Advance& advance) {
	return out << "This is an advance order";
}

//================
//	Bomb
//================

Bomb::Bomb() {
	executed = false;
	type = OrderType::Bomb;
}

Bomb::Bomb(const Bomb& original) {
	executed = original.executed;
	type = original.type;
}

Bomb::~Bomb() {};

void Bomb::execute() {
	if (this->validate()) {
		cout << "Executing bomb order.\n";
		executed = true;
	}
}
bool Bomb::validate() {
	return !executed;
}

Order* Bomb::clone() {
	Bomb* newBombOrder = new Bomb();
	newBombOrder->type = this->type;
	newBombOrder->executed = this->executed;
	return (Order*)newBombOrder;
}

Bomb& Bomb::operator=(const Bomb& bomb)
{
	if (&bomb == this) {
		return *this;
	}
	executed = bomb.executed;
	type = bomb.type;
	return *this;
}

ostream& operator<<(ostream& out, const Bomb& bomb) {
	return out << "This is a bomb order";
}

//================
//	Blockade
//================

Blockade::Blockade() {
	executed = false;
	type = OrderType::Blockade;
}

Blockade::Blockade(const Blockade& original) {
	executed = original.executed;
	type = original.type;
}

Blockade::~Blockade() {};

void Blockade::execute() {
	if (this->validate()) {
		cout << "Executing blockade order.\n";
		executed = true;
	}
}
bool Blockade::validate() {
	return !executed;
}

Order* Blockade::clone() {
	Blockade* newBlockadeOrder = new Blockade();
	newBlockadeOrder->type = this->type;
	newBlockadeOrder->executed = this->executed;
	return (Order*)newBlockadeOrder;
}

Blockade& Blockade::operator=(const Blockade& blockade){
	if (&blockade == this) {
		return *this;
	}
	executed = blockade.executed;
	type = blockade.type;
	return *this;
}

ostream& operator<<(ostream& out, const Blockade& blockade) {
	return out << "This is a blockade order";
}

//================
//	Airlift
//================

Airlift::Airlift() {
	executed = false;
	type = OrderType::Airlift;
}

Airlift::Airlift(const Airlift& original) {
	executed = original.executed;
	type = original.type;
}

Airlift::~Airlift() {};

void Airlift::execute() {
	if (this->validate()) {
		cout << "Executing airlift order.\n";
		executed = true;
	}
}
bool Airlift::validate() {
	return !executed;
}

Order* Airlift::clone() {
	Airlift* newAirliftOrder = new Airlift();
	newAirliftOrder->type = this->type;
	newAirliftOrder->executed = this->executed;
	return (Order*)newAirliftOrder;
}

Airlift& Airlift::operator=(const Airlift& airlift){
	if (&airlift == this) {
		return *this;
	}
	executed = airlift.executed;
	type = airlift.type;
	return *this;
}

ostream& operator<<(ostream& out, const Airlift& airlift) {
	return out << "This is an airlift order";
}

//================
//	Negotiate
//================

Negotiate::Negotiate() {
	executed = false;
	type = OrderType::Negotiate;
}

Negotiate::Negotiate(const Negotiate& original) {
	executed = original.executed;
	type = original.type;
}

Negotiate::~Negotiate() {}

void Negotiate::execute() {
	if (this->validate()) {
		cout << "Executing negotiate order.\n";
		executed = true;
	}
}
bool Negotiate::validate() {
	return !executed;
}

Order* Negotiate::clone() {
	Negotiate* newNegotiateOrder = new Negotiate();
	newNegotiateOrder->type = this->type;
	newNegotiateOrder->executed = this->executed;
	return (Order*)newNegotiateOrder;
}

Negotiate& Negotiate::operator=(const Negotiate& negotiate) {
	if (&negotiate == this) {
		return *this;
	}
	executed = negotiate.executed;
	type = negotiate.type;
	return *this;
}

ostream& operator<<(ostream& out, const Negotiate& negotiate) {
	return out << "This is a negotiate order";
}