#pragma once
#include "Map.h"
class MapLoader
{
public:
	//Default Constructor
	MapLoader();

	//Copy Constructor
	MapLoader(MapLoader& map);
	//Assignment operator
	MapLoader&  operator = (const MapLoader& map);

	//Destructor
	~MapLoader();



	MapLoader(string dominationFileName);

	Map* GetMap(string filePath);

	Map* ReadMap(string domiantionFileName);

	vector<string> SplitWords(string s);

	string FirstComponent(string s);

	friend istream& operator>>(istream& in, string dominationMap);

	//Validate map is a connected graph
	void ValidateConnectedGraph(Map* map);

private:
	Map* finalMap;
	string dominationFileName;


};

