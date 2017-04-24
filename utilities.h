#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Graph.h"

using namespace std;

// TO DO
// Read a list of integer, string pairs representing a station name and its identifier from a text file
// return a vector of strings containing the stations names indexed by their identifiers
// throw an exception if there was a problem opening or reading the file
std::vector<string> readStationNames(const std::string& filename) {
    vector<string> StationNames;
    string s = "";
    StationNames.push_back(s);
    int iden;
    ifstream file;
    file.open(filename);
    if (!file) {throw invalid_argument("Unable to open file " + filename);}
    while (file) {
        file >> s;
        file >> iden;
        StationNames.push_back(s);
    }
    StationNames.pop_back();
    file.close();
    return StationNames;
}

// TO DO
// Read a list of (integer, integer) pairs representing station identifiers that are next to each other
// return a graph representing these station links
// throw an exception if there was a problem opening or reading the file
Graph *buildGraphfromDatafile(const std::string& filename) {
    Graph *a = new Graph(325);
    int station, connection;
    ifstream file;
    file.open(filename);
    if (!file) {throw invalid_argument("Unable to open file " + filename);}
    while (file) {
        file >> station >> connection;
        a->add_edge(station, connection);
        //cout << "Added " << station << " " << connection << endl;
    }
    file.close();
    return a;
}
