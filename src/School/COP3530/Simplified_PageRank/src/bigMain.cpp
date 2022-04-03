#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

class Graph{
  private:
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

void Graph::addEdge(string from, string to)
{
  if(incoming_edges.find(to) == incoming_edges.end())
  {
    unordered_map<string, double> edge;
    edge.emplace(from, -1);
    incoming_edges.emplace(to, edge);
  }
  else
  {
    incoming_edges.find(to)->second.emplace(from, 1);
  }

  if(outgoing_edges.find(from) == outgoing_edges.end())
  {
    unordered_set<string> edge;
    edge.emplace(to);
    outgoing_edges.emplace(from, edge);
  }
  else
  {
    outgoing_edges.find(from)->second.emplace(to);
  }
}

void Graph::calcEdgeValues()
{
  for(auto i = incoming_edges.begin(); i != incoming_edges.end(); i++)
    {
      string to_vertex = i->first;
      page_ranks.emplace(to_vertex, 1.0/incoming_edges.size());
      for(auto j = i->second.begin(); j != i->second.end(); j++)
      {
        double from_outdegree = outgoing_edges.at(j->first).size();
        page_ranks.emplace(j->first, 1.0/incoming_edges.size());
        j->second = 1.0/from_outdegree;
      }
    }
}

void Graph::pageRanks(int pIterations)
{
  for(int i = 1; i < pIterations; i++)
  {
    map<string, double> new_page_ranks;
    for(auto it = page_ranks.begin(); it != page_ranks.end(); it++)
    {
      double new_rank = 0;
      auto firstIt = incoming_edges.at(it->first);
      for(auto it2 = page_ranks.begin(); it2 != page_ranks.end(); it2++)
      {
        if(firstIt.find(it2->first) != firstIt.end())
        {
          new_rank += it2->second * firstIt.at(it2->first);
        }
      }
      new_page_ranks.emplace(it->first, new_rank);
    }
    page_ranks = new_page_ranks;
  }
}

void Graph::printEdges()
{
  for(auto it = incoming_edges.begin(); it != incoming_edges.end(); it++)
  {
    cout << it->first << endl;
    for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
    {
      cout << it2->first << " " << it2->second << endl;
    }
  }
}

void Graph::printRanks()
{
  for(auto it = page_ranks.begin(); it != page_ranks.end(); it++)
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
  myGraph.pageRanks(power_iterations);
  myGraph.printRanks();
}