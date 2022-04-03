#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

#pragma once

class Graph{
  private:
    unordered_set<string> vertices;
    unordered_map<string, unordered_map<string, double>> incoming_edges;
    unordered_map<string, unordered_set<string>> outgoing_edges;
    map<string, double> page_ranks;
  public:
    void addEdge(string from, string to);
    void calcEdgeValues();
    void pageRanks(int pIterations);
    void printEdges();
    void printRanks();
};