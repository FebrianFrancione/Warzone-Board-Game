#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MapLoader {
public:
	enum ReadState{none, continent, countries, borders};
	MapLoader();
	MapLoader(string _filename);
	void loadMap();
	void printMap();
	Map getMapCopy();
	//friend std::ostream& operator<< (std::ostream& out, const MapLoader& maploader);
private:
	bool success;
	string filename;
	Map* map;
	string CONTINENTS_HEADER = "[continents]";
	string COUNTRIES_HEADER = "[countries]";
	string BORDERS_HEADER = "[borders]";
};
