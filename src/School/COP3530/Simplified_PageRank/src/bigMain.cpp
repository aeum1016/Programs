#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

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

/**
 * Inserts a site-to-site relationship into the graph.
 *
 * @param from  The site that is referencing another site
 * @param to    The site that being referenced
 */
void Graph::addEdge(string from, string to)
{
  if(siteToInt.find(to) == siteToInt.end())
  {
  // If the TO site has not been seen
    if(siteToInt.find(from) == siteToInt.end())
    {
      // If the FROM site has not been seen
      // Add the FROM site to the graph
      unordered_map<int, double> newAdjList2;
      edges.push_back(newAdjList2);
      siteToInt.emplace(from, (int) edges.size()-1);
      intToSite.emplace((int) edges.size()-1, from);
      edgeOutDegrees.emplace(edges.size()-1, 1);
    }
    else
    {
      // If the FROM site has been seen
      // Increment the FROM site's outdegree
      if(edgeOutDegrees.find(siteToInt.at(from)) == edgeOutDegrees.end())
      {
        edgeOutDegrees.emplace(siteToInt.at(from), 1);
      }
      else{
        edgeOutDegrees.at(siteToInt.at(from)) += 1;
      }
    }

    // Add the TO site to the graph
    unordered_map<int, double> newAdjList;
    newAdjList.emplace(siteToInt.at(from), 0.0);
    edges.push_back(newAdjList);
    siteToInt.emplace(to, (int) edges.size()-1);
    intToSite.emplace((int) edges.size()-1, to);
  }
  else
  {
    // If the TO site has been seen
    if(siteToInt.find(from) == siteToInt.end())
    {
      // If the FROM site has not been seen
      // Add the FROM site to the graph
      edges.push_back(unordered_map<int, double>());
      siteToInt.emplace(from, (int) edges.size()-1);
      intToSite.emplace((int) edges.size()-1, from);
      edgeOutDegrees.emplace(edges.size()-1, 1);
    }
    else
    {
      // If the FROM site has been seen
      // Increment the outdegree of the FROM site
      if(edgeOutDegrees.find(siteToInt.at(from)) == edgeOutDegrees.end())
      {
        edgeOutDegrees.emplace(siteToInt.at(from), 1);
      }
      else{
        edgeOutDegrees.at(siteToInt.at(from)) += 1;
      }
    }
    // Add the FROM site to the adj list of the TO site
    edges.at(siteToInt.at(to)).emplace(siteToInt.at(from), 0.0);
  }
}

/**
 * Calculates the values of 1/out_degree for all edges in
 * the graph, i.e. the weights of the edges in the graph.
 */
void Graph::calcEdgeValues()
{
  for(auto it = intToSite.begin(); it != intToSite.end(); it++)
    {
      int to_vertex = it->first;
      pageRanks.emplace(to_vertex, 1.0/intToSite.size());
      if(edges.at(to_vertex).size() != 0)
      {
        for(auto j = edges.at(to_vertex).begin(); j != edges.at(to_vertex).end(); j++)
        {
          double from_outdegree = edgeOutDegrees.at(j->first);
          if(from_outdegree != 0)
          {
            j->second = 1.0/from_outdegree;
          }
        }
      }
    }
}

/**
 * Calculates the ranks of the pages in the graph after
 * pIterations iterations.
 * 
 * @param pIterations The number of iterations that the graph
 * should run through
 */
void Graph::calcPageRanks(int pIterations)
{
  for(int i = 1; i < pIterations; i++)
  {
    unordered_map<int, double> newRanks;
    for(auto it = pageRanks.begin(); it != pageRanks.end(); it++)
    {
      double newRank = 0.0;
      for(auto it2 = edges.at(it->first).begin(); it2 != edges.at(it->first).end(); it2++)
      {
        double prevRank = pageRanks.at(it2->first);
        double weight = it2->second;
        newRank += prevRank * weight;
      }
      newRanks.emplace(it->first, newRank);
    }
    pageRanks = newRanks;
  }
}

/**
 * Used for testing
 * Prints a destination site followed by all of the site's 
 * source sites and their respective weights
 */
void Graph::printEdges()
{
  for(int i = 0; i < edges.size(); i++)
  {
    cout << intToSite.at(i) << endl;
    for(auto it = edges.at(i).begin(); it != edges.at(i).end(); it++)
    {
      cout << intToSite.at(it->first) << " " << it->second << endl; 
    }
  }
}

/**
 * Used for testing
 * Prints the site name followed by the
 * outdegree for every site in the graph 
 */
void Graph::printOutDegrees()
{
  for(auto it = edgeOutDegrees.begin(); it != edgeOutDegrees.end(); it++)
  {
    cout << intToSite.at(it->first) << " " << it->second << endl;
  }
}

/**
 * Prints the ranks of the sites in alphabetical
 * order.
 */
void Graph::printRanks()
{
  map<string, double> ordered_ranks;
  for(int i = 0; i < edges.size(); i++)
  {
    ordered_ranks.emplace(intToSite.at(i), pageRanks.at(i));
  }
  for(auto it = ordered_ranks.begin(); it != ordered_ranks.end(); it++)
  {
    cout << it->first << " " << it->second << endl;
  }
}

int main()
{
  Graph myGraph;
  int no_of_lines, power_iterations;
  string from, to;
  cin >> no_of_lines >> power_iterations;
  for(int i = 0; i < no_of_lines; i++)
  {
    cin >> from;
    cin >> to;
    myGraph.addEdge(from, to);
  }
  cout << std::fixed << std::showpoint;
  cout << std::setprecision(2);
  myGraph.calcEdgeValues();
  myGraph.calcPageRanks(power_iterations);
  myGraph.printRanks();
  // myGraph.printEdges();
  // myGraph.printOutDegrees();
}