#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

#pragma once

class Graph{
  private:
    vector<unordered_map<int, double>> edges;
    unordered_map<int, int> edgeOutDegrees;
    unordered_map<int, string> intToSite;
    unordered_map<string, int> siteToInt;
    unordered_map<int, double> pageRanks;
  public:
    void addEdge(string from, string to);
    void calcEdgeValues();
    void calcPageRanks(int pIterations);
    void printEdges();
    void printOutDegrees();
    void printRanks();
};