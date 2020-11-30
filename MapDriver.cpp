/*
#include "Map.h"
#include <iostream>

void f1() {

	Territory Canada = Territory(0, "Canada", 0);
	Territory US = Territory(1, "US", 0);
	Territory Mexico = Territory(2, "Mexico", 0);
	Territory France = Territory(3, "France", 1);
	Territory England = Territory(4, "England", 1);

	Territory Canada2 = Canada;

	Edge e1 = Edge(0, 1);
	Edge e2 = Edge(0, 3);
	Edge e3 = Edge(0, 4);
	Edge e4 = Edge(2, 1);
	Edge e5 = Edge(3, 1);
	Edge e6 = Edge(4, 3);
	Edge e11 = Edge(1, 0);

	Map gameMap = Map("Mini World");

	gameMap.addTerritory(Canada);
	gameMap.addTerritory(US);
	gameMap.addTerritory(Mexico);
	gameMap.addTerritory(France);
	gameMap.addTerritory(England);
	gameMap.addTerritory(Canada);
	gameMap.addTerritory(Canada2);

	gameMap.addEdge(e1);
	gameMap.addEdge(e2);
	gameMap.addEdge(e3);
	gameMap.addEdge(e4);
	gameMap.addEdge(e5);
	gameMap.addEdge(e6);
	gameMap.addEdge(e11);

	cout << gameMap;
}

int main() {

	f1();

}*/
