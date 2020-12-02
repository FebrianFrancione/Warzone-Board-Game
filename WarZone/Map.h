#pragma once

#include <string>
using namespace std;

//A vertex of the graph
//Contains a list of all the territories connected to it
class Territory {
public:
	//Constructor
	Territory();
	Territory(int id, string name, int _continentId);
	Territory(const Territory& original);
	//Destructor
	~Territory();
	//ID and Name getters
	int getId();
	string getName();
	//player setter/getter
	//TODO REPLACE WITH PLAYER CLASS
	//Player name is unique, could leave as is
	void setOwner(string _player);
	string getOwner();
	//army count getter/setter
	void setArmyCount(int count);
	int getArmyCount();
	void addTroops(int qty);
	void removeTroops(int qty);
	void setVirtualArmy(int qty);
	int getVirtualArmy();
	//setting adjacent territories
	void addAdjacent(int id);
	bool isAdjacent(int id);
	//checker
	bool isEqual(Territory territory);
	//Get number of adjacent territories
	int getNumberAdj();
	int getAdjacent(int index);
	//get continent
	int getContinentId();
	Territory& operator= (const Territory& original);
	friend std::ostream& operator<< (std::ostream& out, const Territory& territory);
private:
	int id;
	string name;
	int* adjTerr;	//array of the ids of adjacent territories
	int numAdj;
	int armyCount;
	int virtualArmyCount;	//because until you deploy the actual fucking troops, you need to pretend theyre there, execept theyre not
	int continentID;
	//TODO
	//Placeholder for player class
	string player;
};

//As a rule of thumb, in order to avoid duplicate edges, always: origin < destination
//Where both are territory id's
class Edge {
public:
	Edge();
	Edge(int o, int d);
	Edge(const Edge& edge);
	~Edge() {};
	int getO();
	int getD();
	bool isEqual(Edge anEdge);
	bool isEqual(int o, int d);
	Edge& operator= (const Edge& original);
	friend std::ostream& operator<< (std::ostream& out, const Edge& edge);
private:
	int origin;
	int dest;
};

//MODIFIED: only contains the territories and reinforcement count
//any other information can be found in the map itself

//Subgraph of the graph
//Similar to the Map graph but only holds a list of the territories pertaining to it
class Continent {
public:
	Continent();
	Continent(int _id, string _name, int _reinforcements);
	Continent(const Continent& original);
	~Continent();
	//void addEdge(int n1, int n2);
	void addTerritory(int territoryId);
	int getTerritoryId(int index);
	int getNumTerritories();
	int getReinforcementBonus();
	Continent& operator= (const Continent& original);
	friend std::ostream& operator<< (std::ostream& out, const Continent& continent);
private:
	int id;
	string name;
	int* territoryIds;
	int numTerr;
	int totalReinforcements;
};

//Graph
//Implemented as a sort of modified edge list structure
class Map {
public:
	Map(string name);
	Map(const Map& original);
	~Map();
	//Validates by game rules
	bool validate();
	//Add objects to the map
	void addEdge(const Edge edge);
	void addEdge(int n1, int n2);
	void addTerritory(const Territory territory);
	void addContinent(const Continent continent);
	//Get objects as pointers from the map
	Territory* getTerritory(int id);
	Edge* getEdge(int id);
	Continent* getContinent(int id);
	//Get values
	int getNumTerritories();
	int getNumEdges();
	int getNumContinents();
	string getName();
	//Operator overloads
	Map& operator= (const Map& original);
	friend std::ostream& operator<< (std::ostream& out, const Map& map);
private:
	string name;
	Territory* territories;
	int numTerr;
	Edge* edges;
	int numEdges;
	Continent* continents;
	int numContinents;
};



