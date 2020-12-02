#include "Orders.h"
#include "Map.h"
#include <iostream>
#include <iomanip>
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

int Order::getType() {
	return type;
}

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
	switch (order.type) {
	case Order::Deploy: out << "Deploy"; break;
	case Order::Advance: out << "Advance"; break;
	case Order::Bomb: out << "Bomb"; break;
	case Order::Blockade: out << "Blockade"; break;
	case Order::Airlift: out << "Airlift"; break;
	case Order::Negotiate: out << "Negotiate"; break;
	}
	out << " order. Execution state: ";
	if (order.executed) {
		out << "Executed";
	}
	else {
		out << "Not executed";
	}
	return out;
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

//Add a new order to a list
void OrdersList::add(Order* newOrder) {
	size++;
	Order** newList = new Order * [size];
	for (int i = 0; i < size - 1; i++) {
		newList[i] = theList[i];
	}
	newList[size - 1] = newOrder;
	delete theList;
	theList = newList;
}

//Move order from start position to end position
void OrdersList::move(int start, int end) {
	if (start == end || start < 0 || start > size || end < 0 || end > size) {
		//cout << "Cannot move order from pos " << start << " to pos " << end << endl;
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
	delete[] theList;
	theList = newList;
}

//Get a specific order from the list
Order* OrdersList::get(int pos) {
	return theList[pos];
}

int OrdersList::getSize() {
	return size;
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
	territory = new Territory();
	qty = 0;
}

Deploy::Deploy(Territory* _territory, int _qty) {
	executed = false;
	type = OrderType::Deploy;
	territory = _territory;
	//territory = _territory;
	qty = _qty;
}

Deploy::Deploy(const Deploy& original) {
	executed = original.executed;
	type = original.type;
	territory = original.territory;
	qty = original.qty;
}

//Destructor
Deploy::~Deploy() {//delete this->territory;
};

void Deploy::execute() {
	if (validate()) {
		cout << "Adding " << qty << " troops to " << territory->getName() << endl;
		territory->addTroops(qty);
	}
	else {
		cout << "Could not deploy " << qty << " troops to " << territory->getName() << endl;
	}
	executed = true;
}
bool Deploy::validate() {
	//Only check to do is whether the territory belongs to anyone
	//Can't access any other information. This order can only be added to a players list if it belongs to a player
	//A deploy order has the highest priority, and therefore cannot fail otherwise
	if (territory->getOwner().empty()) {
		return false;
	}
	return !executed;
}

Order* Deploy::clone() {
	Deploy* newDeployOrder = new Deploy();
	newDeployOrder->type = this->type;
	newDeployOrder->executed = this->executed;
	newDeployOrder->territory = new Territory(*this->territory);
	newDeployOrder->qty = this->qty;
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
	origin = new Territory();
	destination = new Territory();
	qty = 0;
}

Advance::Advance(Territory* _origin, Territory* _destination, int _qty, string _playerO, string _playerD) {
	executed = false;
	type = OrderType::Advance;
	origin = _origin;
	destination = _destination;
	qty = _qty;
	playerO = _playerO;
	playerD = _playerD;
}

Advance::Advance(const Advance& original) {
	executed = original.executed;
	type = original.type;
	origin = original.origin;
	destination = original.destination;
	qty = original.qty;
	playerO = original.playerO;
	playerD = original.playerD;
}

Advance::~Advance() {
	delete origin;
	delete destination;
};

void Advance::execute() {
	if (this->validate()) {
		//cout << "Executing advance order.\n";
		int result = 0;
		if (playerO != playerD) {
			cout << right << setw(36) << playerO << " attacking " << left << setw(36) << playerD << endl;
			cout << right << setw(36) << origin->getName() << " attacking " << left << setw(36) << destination->getName();
			cout << right << setw(36) << origin->getArmyCount() << " vs. " << left << setw(36) << destination->getArmyCount();
			while (origin->getArmyCount() > 1 && destination->getArmyCount() > 0) {
				result = rand() % 10;
				if (result < 6) {
					destination->removeTroops(1);
				}
				result = rand() % 10;
				if (result < 7) {
					origin->removeTroops(1);
				}
			}
		}
	}
	else {
		cout << "Advance order cancelled.";
	}
	executed = true;
}
bool Advance::validate() {
	//Player lost control of their territory
	if (origin->getOwner() != playerO) {
		return false;
	}
	//Target switched ownership
	if (destination->getOwner() != playerD) {
		return false;
	}
	//Player lost the original troop count
	if (origin->getArmyCount() < 2) {
		return false;
	}
	//Return false if order already executed
	return !executed;
}

Order* Advance::clone() {
	Advance* newAdvanceOrder = new Advance();
	newAdvanceOrder->type = this->type;
	newAdvanceOrder->executed = this->executed;
	newAdvanceOrder->origin = new Territory(*this->origin);
	newAdvanceOrder->destination = new Territory(*this->destination);
	newAdvanceOrder->qty = this->qty;
	newAdvanceOrder->playerO = this->playerD;
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