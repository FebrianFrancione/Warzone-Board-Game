#include "Map.h"
#include "MapLoader.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>

MapLoader::MapLoader() {
    map = nullptr;
    success = false;
    //filename = "";
}

MapLoader::MapLoader(string _filename) {
    map = new Map(_filename);
    filename = _filename;
    success = false;
}

void MapLoader::loadMap() {

    int readState = ReadState::none;
    string line;
    ifstream mapFile(filename);

    if (!mapFile.is_open() || map == nullptr) {
        cout << "Could not load map from " << filename << ". File does not exist" << endl;
        throw exception();

    }

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(mapFile, line)) {

        if (line.empty()) {
            continue;
        }

        //If keyword continent found
        //Set read state for text parsing to continent
        if (line.find(CONTINENTS_HEADER) != std::string::npos) {
            readState = ReadState::continent;
            continue;
        }
        //If keyword countries found
        //Set read state for text parsing to countries
        else if (line.find(COUNTRIES_HEADER) != std::string::npos) {
            readState = ReadState::countries;
            continue;
        }
        //If keyword borders found
        //Set read state for text parsing to borders
        else if (line.find(BORDERS_HEADER) != std::string::npos) {
            readState = ReadState::borders;
            continue;
        }

        stringstream split(line);
        try {
            if (readState == ReadState::continent) {
                string name;
                string reinforcements;
                getline(split, name, ' ');
                getline(split, reinforcements, ' ');
                //We set the current number of continents as the id, since
                //our array is 0 based anyways
                map->addContinent(Continent(map->getNumContinents(), name, stoi(reinforcements)));
            }
            else if(readState == ReadState::countries){
                string id;
                string name;
                string continentId;
                getline(split, id, ' ');
                getline(split, name, ' ');
                getline(split, continentId, ' ');
                //The ID from the map file is 1 based, but the arrays are 0 based
                //The functions needed it by 0 based, so insert as 0 based
                map->addTerritory(Territory(stoi(id) - 1, name, stoi(continentId) - 1));
                map->getContinent(stoi(continentId)-1)->addTerritory(stoi(id) - 1);
            }
            else if (readState == ReadState::borders) {
                string origin;
                string destination;
                getline(split, origin, ' ');
                while (getline(split, destination, ' ')) {
                    //Same thing for each border, insert with 0 based ids
                    map->addEdge(Edge(stoi(origin) - 1, stoi(destination) - 1));
                    map->getTerritory(stoi(origin) - 1)->addAdjacent(stoi(destination) - 1);
                }
            }
        }
        catch (const std::exception& e) {
            cout << "Data in map file: " << filename << " is not formatted properly." << endl << e.what();
            exit(1001);
        }
    }//End of while loop reading in each line from file
    success = true;
}

void MapLoader::printMap() {
    if (!success) {
        cout << "Map was never loaded, or did not load properly. Aborting" << endl;
        return;
    }
    cout << "Printing the map: " << filename << endl;
    cout << "==============================" << endl;
    cout << "Territories" << endl;
    Territory* aTerritory = new Territory();
    for (int i = 0; i < map->getNumTerritories(); i++) {
        aTerritory = map->getTerritory(i);
        cout << aTerritory->getName() << ": ";// << endl;
        for (int j = 0; j < aTerritory->getNumberAdj(); j++) {
            cout << map->getTerritory(aTerritory->getAdjacent(j))->getName() << ", ";
        }
        cout << endl;
    }
    cout << "==============================" << endl;
    cout << "The continents and their territories" << endl;
    Continent aContinent;
    for (int i = 0; i < map->getNumContinents(); i++) {
        aContinent = *(map->getContinent(i));
        cout << aContinent << endl;
        for (int j = 0; j < aContinent.getNumTerritories(); j++) {
            cout << map->getTerritory(aContinent.getTerritoryId(j))->getName() << endl;
        }
        cout << "---" << endl;
    }
    cout << "==============================" << endl;
    cout << "The borders" << endl;
    for (int i = 0; i < map->getNumEdges(); i++) {
        cout << map->getTerritory(map->getEdge(i)->getO())->getName() << " - " << map->getTerritory(map->getEdge(i)->getD())->getName() << endl;
    }
    cout << "==============================" << endl;
    cout << endl;
}

Map MapLoader::getMapCopy() {
    return *map;
}
