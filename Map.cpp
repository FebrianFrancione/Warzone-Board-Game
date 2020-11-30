#include "Map.h"
#include <iostream>


//=====================
//	Territory
//=====================
Territory::Territory() {
	id = -1;
	numAdj = 0;
	adjTerr = new int[numAdj];
	armyCount = 0;
	continentID = -1;
}

Territory::Territory(int _id, string _name, int _continentId) {
	if (_id < 0 || _continentId < 0) {
		cout << "Exception occured -> territory " << _name << "has ID:" << " and continent ID:" << _continentId << endl;
		throw std::exception();
	}
	id = _id;
	name = _name;
	numAdj = 0;
	adjTerr = new int[numAdj];
	armyCount = 0;
	continentID = _continentId;
}

Territory::Territory(const Territory& original) {
	id = original.id;
	name = original.name;
	armyCount = original.armyCount;
	continentID = original.continentID;
	numAdj = original.numAdj;
	adjTerr = new int[numAdj];
	for (int i = 0; i < numAdj; i++) {
		adjTerr[i] = original.adjTerr[i];
	}
}

Territory::~Territory() {
	delete adjTerr;
}

int Territory::getId() {
	return id;
}

string Territory::getName() {
	return name;
}

void Territory::setOwner(string _player) {
	if (_player != "") {
		player = _player;
	}
}

string Territory::getOwner() {
	return player;
}

void Territory::setArmyCount(int count) {
	if (count > 0) {
		armyCount = count;
	}
}

int Territory::getArmyCount() {
	return armyCount;
}

void Territory::addAdjacent(int id) {
	numAdj++;
	int* newList = new int[numAdj];
	for (int i = 0; i < numAdj - 1; i++) {
		newList[i] = adjTerr[i];
		//Check for duplicates
		if (adjTerr[i] == id) {
			numAdj--;
			delete[] newList;
			return;
		}
	}
	newList[numAdj - 1] = id;
	delete adjTerr;
	adjTerr = newList;
}

bool Territory::isAdjacent(int id) {
	for (int i = 0; i < numAdj; i++) {
		if (adjTerr[i] == id) {
			return true;
		}
	}
	return false;
}

bool Territory::isEqual(Territory territory) {
	return (territory.getId() == id || territory.getName() == name);
}

Territory& Territory::operator=(const Territory& original) {
	id = original.id;
	name = original.name;
	armyCount = original.armyCount;
	continentID = original.continentID;
	numAdj = original.numAdj;
	adjTerr = new int[numAdj];
	for (int i = 0; i < numAdj; i++) {
		adjTerr[i] = original.adjTerr[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Territory& territory) {
	//out << "Territory: " << territory.name << endl;
	//out << "Army Size: " << territory.armyCount << "(owned by: " << territory.player << ")" << endl;
	//out << territory.adjTerr;
	//return out;
	return (out << "Territory: " << territory.name);
}

//=====================
//	Edge
//=====================
Edge::Edge() {
	origin = -1;
	dest = -1;
}

Edge::Edge(int o, int d) {
	/*if (o < 0 || d < 0 || o == d) {
		cout << "Invalid edge " << origin << " and " << dest << endl;
		throw std::exception();
	}*/
	//In order to avoid duplicate edges, the origin value id is always set as the smaller of the 2
	if (o < d) {
		origin = o;
		dest = d;
	}
	else {
		origin = d;
		dest = o;
	}
}

Edge::Edge(const Edge& edge) {
	origin = edge.origin;
	dest = edge.dest;
}

int Edge::getO() {
	return origin;
}

int Edge::getD() {
	return dest;
}

bool Edge::isEqual(Edge anEdge) {
	return (anEdge.getO() == origin && anEdge.getD() == dest);
}

bool Edge::isEqual(int o, int d) {
	return (origin == o && dest == d);
}

Edge& Edge::operator=(const Edge& original) {
	origin = original.origin;
	dest = original.dest;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Edge& edge) {
	return (out << "Connects territories " << edge.origin << " and " << edge.dest);
}

//=====================
//	Map
//=====================
Map::Map(string _name) {
	name = _name;
	numTerr = 0;
	territories = new Territory[numTerr];
	numEdges = 0;
	edges = new Edge[numEdges];
}

Map::Map(const Map& original) {
	name = original.name;
	numTerr = original.numTerr;
	territories = new Territory[numTerr];
	for (int i = 0; i < numTerr; i++) {
		territories[i] = original.territories[i];
	}
	numEdges = original.numEdges;
	edges = new Edge[numEdges];
	for (int i = 0; i < numEdges; i++) {
		edges[i] = original.edges[i];
	}
}

Map::~Map() {
	delete[] territories;
	delete[] edges;
}

bool Map::validate() {
	return false;
}

void Map::addEdge(int n1, int n2) {
	/*numEdges++;
	Edge* newList = new Edge[numEdges];
	for (int i = 0; i < numEdges - 1; i++) {
		newList[i] = edges[i];
	}
	newList[numEdges - 1] = Edge(n1, n2);
	delete[] edges;
	edges = newList;*/
	this->addEdge(Edge(n1, n2));
}

void Map::addEdge(const Edge edge) {
	numEdges++;
	Edge* newList = new Edge[numEdges];
	for (int i = 0; i < numEdges - 1; i++) {
		newList[i] = edges[i];
		//do not add an edge if theyre the same edge
		if (edges[i].isEqual(edge)) {
			cout << "Duplicate edge not added: " << edge << endl;
			numEdges--;
			delete[] newList;
			return;
		}
	}
	newList[numEdges - 1] = edge;
	delete[] edges;
	edges = newList;
}

void Map::addTerritory(const Territory territory) {
	numTerr++;
	Territory* newList = new Territory[numTerr];
	for (int i = 0; i < numTerr - 1; i++) {
		newList[i] = territories[i];
		if (territories[i].isEqual(territory)) {
			cout << "Duplicate country not added: " << territory << endl;
			numTerr--;
			delete[] newList;
			return;
		}
	}
	newList[numTerr - 1] = territory;
	delete[] territories;
	territories = newList;
}

Territory Map::getTerritory(int id) {
	if (id < numTerr && id > 0) {
		return territories[id];
	}
	return Territory();
}

Map& Map::operator=(const Map& original) {
	name = original.name;
	numTerr = original.numTerr;
	territories = new Territory[numTerr];
	for (int i = 0; i < numTerr; i++) {
		territories[i] = original.territories[i];
	}
	numEdges = original.numEdges;
	edges = new Edge[numEdges];
	for (int i = 0; i < numEdges; i++) {
		edges[i] = original.edges[i];
	}
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Map& map) {
	out << "Map: " << map.name << endl;
	out << "Number of territories: " << map.numTerr << endl;
	for (int i = 0; i < map.numTerr; i++) {
		out << map.territories[i] << endl;
	}
	return out;
}


//=====================
//	Continent
//=====================
Continent::Continent(int _id, string _name, int _reinforcements) {
	id = _id;
	name = _name;
	totalReinforcements = _reinforcements;
	numTerr = 0;
	territories = new Territory[numTerr];
}

Continent::Continent(const Continent& original) {
	id = original.id;
	name = original.name;
	totalReinforcements = original.totalReinforcements;
	numTerr = original.numTerr;
	territories = new Territory[numTerr];
	for (int i = 0; i < numTerr; i++) {
		territories[i] = original.territories[i];
	}
}

Continent::~Continent() {
	delete[] territories;
}

void Continent::addTerritory(const Territory territory) {
	numTerr++;
	Territory* newList = new Territory[numTerr];
	for (int i = 0; i < numTerr - 1; i++) {
		newList[i] = territories[i];
		if (territories[i].isEqual(territory)) {
			cout << "Duplicate country found. Not added: " << territory << endl;
			numTerr--;
			delete[] newList;
			return;
		}
	}
	newList[numTerr - 1] = territory;
	delete territories;
	territories = newList;
}

Continent& Continent::operator=(const Continent& original) {
	id = original.id;
	name = original.name;
	totalReinforcements = original.totalReinforcements;
	numTerr = original.numTerr;
	territories = new Territory[numTerr];
	for (int i = 0; i < numTerr; i++) {
		territories[i] = original.territories[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Continent& continent) {
	return (out << "Continent: " << continent.name << "has " << continent.numTerr << " territories. Gives " << continent.totalReinforcements << " total reinforcements.");
}