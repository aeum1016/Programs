#include <iomanip>
#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

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