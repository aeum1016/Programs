#include <iostream>
#include <fstream>
#include <vector>

#include "json-develop/single_include/nlohmann/json.hpp"

#include "Graph.cpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    json j;
    ifstream ifs("top_5000_mydramalist.json");

    ifs >> j;

    Graph g;
    for(int i = 0; i < j.size(); i++)
    {
        vector<string> genres = j[i].at("genres");
        g.addVertice(j[i].at("name"), genres);
    }

    g.computeEdges();

    g.printGraph();

    return 0;
}