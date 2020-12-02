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

void Territory::addTroops(int qty) {
	armyCount += qty;
}

void Territory::removeTroops(int qty) {
	armyCount -= qty;
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

int Territory::getNumberAdj() {
	return numAdj;
}

int Territory::getAdjacent(int index) {
	return adjTerr[index];
}

int Territory::getContinentId() {
	return continentID;
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
	//Undirected edges
	//In order to avoid duplicate edges, the origin value id is always set as the smaller of the 2
	/*if (o < d) {
		origin = o;
		dest = d;
	}
	else {
		origin = d;
		dest = o;
	}*/
	//Directional edges
	origin = o;
	dest = d;
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
//	Continent
//=====================
Continent::Continent() {
	id = -1;
	totalReinforcements = 0;
	numTerr = 0;
	territoryIds = new int[numTerr];
}

Continent::Continent(int _id, string _name, int _reinforcements) {
	id = _id;
	name = _name;
	totalReinforcements = _reinforcements;
	numTerr = 0;
	territoryIds = new int[numTerr];
}

Continent::Continent(const Continent& original) {
	id = original.id;
	name = original.name;
	totalReinforcements = original.totalReinforcements;
	numTerr = original.numTerr;
	territoryIds = new int[numTerr];
	for (int i = 0; i < numTerr; i++) {
		territoryIds[i] = original.territoryIds[i];
	}
}

Continent::~Continent() {
	delete[] territoryIds;
}

void Continent::addTerritory(int id) {
	numTerr++;
	int* newList = new int[numTerr];
	for (int i = 0; i < numTerr - 1; i++) {
		newList[i] = territoryIds[i];
	}
	newList[numTerr - 1] = id;
	delete territoryIds;
	territoryIds = newList;
}

int Continent::getTerritoryId(int index) {
	if (index < numTerr && index >= 0) {
		return territoryIds[index];
	}
	throw exception();
}

int Continent::getNumTerritories() {
	return numTerr;
}

int Continent::getReinforcementBonus() {
	return totalReinforcements;
}

Continent& Continent::operator=(const Continent& original) {
	id = original.id;
	name = original.name;
	totalReinforcements = original.totalReinforcements;
	numTerr = original.numTerr;
	territoryIds = new int[numTerr];
	for (int i = 0; i < numTerr; i++) {
		territoryIds[i] = original.territoryIds[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Continent& continent) {
	return (out << "Continent: " << continent.name << " has " << continent.numTerr << " territories. Gives " << continent.totalReinforcements << " total reinforcements.");
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
	numContinents = 0;
	continents = new Continent[numContinents];
}

Map::Map(const Map& original) {
	name = original.name;
	numTerr = original.numTerr;
	numContinents = original.numContinents;
	territories = new Territory[numTerr];
	for (int i = 0; i < numTerr; i++) {
		territories[i] = original.territories[i];
	}
	numEdges = original.numEdges;
	edges = new Edge[numEdges];
	for (int i = 0; i < numEdges; i++) {
		edges[i] = original.edges[i];
	}
	continents = new Continent[numContinents];
	for (int i = 0; i < numContinents; i++) {
		continents[i] = original.continents[i];
	}
}

Map::~Map() {
	delete[] territories;
	delete[] edges;
}

//Big function
bool Map::validate() {
	//Check if there was anything ever initialized or if it's a default map
	if (numTerr < 1) {
		return false;
	}
	//Part of the validation is done in the respective add() functions for countries and edges
	for (int i = 0; i < numTerr; i++) {
		//Check if all territories have at least one adjacent territory, and therefore, everything is connected
		if (territories[i].getNumberAdj() < 1) {
			return false;
		}
		//Check that for every territory, one of it's neighbours is in the same continent, because if it isn't, gg
		//isolated territory that either isn't connected to its continent, or single territory exists for whole continent
		bool hasNeighbour = false;
		for (int j = 0; j < territories[i].getNumberAdj(); j++) {
			//for each neighbour check if they share the same continent id. if there is one, we gucci
			if (territories[territories[i].getAdjacent(j)].getContinentId() == territories[i].getContinentId()) {
				hasNeighbour = true;
			}
		}
		if (!hasNeighbour) {
			return false;
		}
		//Verify that there isn't the same territory already
		for (int j = i + 1; j < numTerr; j++) {
			if (territories[i].isEqual(territories[j])) {
				return false;
			}
		}
	}
	//For each continent, make sure that the id's in its list arent found in another continent
	for (int i = 0; i < numContinents; i++) {
		//For each territory in the continent
		for (int j = 0; j < continents[i].getNumTerritories(); j++) {
			//get the territory id, pass it to the array of territories, get the continent id associated, match against i
			//in this case, i is equivalent to the continent id because we used the index of the array as the id
			if (territories[continents[i].getTerritoryId(j)].getContinentId() != i) {
				return false;
			}
		}
	}
	return true;
}

void Map::addEdge(int n1, int n2) {
	this->addEdge(Edge(n1, n2));
}

void Map::addEdge(const Edge edge) {
	numEdges++;
	Edge* newList = new Edge[numEdges];
	for (int i = 0; i < numEdges - 1; i++) {
		newList[i] = edges[i];
		//do not add an edge if theyre the same edge
		if (edges[i].isEqual(edge)) {
			//cout << "Duplicate edge not added: " << edge << endl;
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
		//do not add a country if theyre the same id or name
		//if (territories[i].isEqual(territory)) {
		//	//cout << "Duplicate country not added: " << territory << endl;
		//	numTerr--;
		//	delete[] newList;
		//	return;
		//}
		///////////////////////////Commented out in favour of the validate() check instead
	}
	newList[numTerr - 1] = territory;
	delete[] territories;
	territories = newList;
}

void Map::addContinent(const Continent continent) {
	numContinents++;
	Continent* newList = new Continent[numContinents];
	for (int i = 0; i < numContinents - 1; i++) {
		newList[i] = continents[i];
	}
	newList[numContinents - 1] = continent;
	delete[] continents;
	continents = newList;
}

Territory* Map::getTerritory(int id) {
	if (id < numTerr && id >= 0) {
		return &territories[id];
	}
	throw exception();
}

Edge* Map::getEdge(int id) {
	if (id < numEdges && id >= 0) {
		return &edges[id];
	}
	throw exception();
}

Continent* Map::getContinent(int id) {
	if (id < numContinents && id >= 0) {
		return &continents[id];
	}
	throw exception();
}

int Map::getNumTerritories() {
	return numTerr;
}

int Map::getNumEdges() {
	return numEdges;
}

int Map::getNumContinents() {
	return numContinents;
}

string Map::getName() {
	return name;
}

Map& Map::operator=(const Map& original) {
	name = original.name;
	numTerr = original.numTerr;
	numContinents = original.numContinents;
	territories = new Territory[numTerr];
	for (int i = 0; i < numTerr; i++) {
		territories[i] = original.territories[i];
	}
	numEdges = original.numEdges;
	edges = new Edge[numEdges];
	for (int i = 0; i < numEdges; i++) {
		edges[i] = original.edges[i];
	}
	continents = new Continent[numContinents];
	for (int i = 0; i < numContinents; i++) {
		continents[i] = original.continents[i];
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