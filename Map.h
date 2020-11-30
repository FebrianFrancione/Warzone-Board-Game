#include <string>
using namespace std;

#pragma once

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
	void setOwner(string _player);
	string getOwner();
	//army count getter/setter
	void setArmyCount(int count);
	int getArmyCount();
	//setting adjacent territories
	void addAdjacent(int id);
	bool isAdjacent(int id);
	//checker
	bool isEqual(Territory territory);
	Territory& operator= (const Territory& original);
	friend std::ostream& operator<< (std::ostream& out, const Territory& territory);
private:
	int id;
	string name;
	int* adjTerr;	//array of the ids of adjacent territories
	int numAdj;
	int armyCount;
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

//Graph
//Implemented as a sort of modified edge list structure
class Map {
public:
	Map(string name);
	Map(const Map& original);
	~Map();
	bool validate();
	void addEdge(const Edge edge);
	void addEdge(int n1, int n2);
	void addTerritory(const Territory territory);
	Territory getTerritory(int id);
	Map& operator= (const Map& original);
	friend std::ostream& operator<< (std::ostream& out, const Map& map);
private:
	string name;
	Territory* territories;
	int numTerr;
	Edge* edges;
	int numEdges;
};

/*#endif*/ // !Maps

//Subgraph of the graph
//Similar to the Map graph but only holds a list of the territories pertaining to it

class Continent {
public:
	Continent(int cId, string cName, int reinforcements);
	Continent(const Continent& original);
	~Continent();
	//void addEdge(int n1, int n2);
	void addTerritory(const Territory territory);
	Continent& operator= (const Continent& original);
	friend std::ostream& operator<< (std::ostream& out, const Continent& continent);
private:
	int id;
	string name;
	Territory* territories;
	int numTerr;
	int totalReinforcements;
	//Edge* edges;
};
