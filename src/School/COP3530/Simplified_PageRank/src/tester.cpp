#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Graph.h"

#include <chrono>

using namespace std;
using namespace std::chrono;

uint64_t timeSinceEpochMillisec() {
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int main()
{
  Graph myGraph;
  int no_of_lines = 0, power_iterations = 0;
  string from, to;
  ifstream ifs("./src/test.txt");
  string line;
  uint64_t start = timeSinceEpochMillisec();
  cout << "Start" << start;
  while(getline(ifs, line))
  {
    stringstream ss(line);
    if(power_iterations == 0)
    {
      ss >> no_of_lines >> power_iterations;
    }
    else{
      ss >> from;
      ss >> to;
      myGraph.addEdge(from, to);
    }
  }
  cout << "done adding elements" << endl;
  cout << std::fixed << std::showpoint;
  cout << std::setprecision(2);
  myGraph.calcEdgeValues();
  cout << "done calculating edge values" << endl;
  myGraph.calcPageRanks(power_iterations);
  cout << "done calculating ranks" << endl;
  myGraph.printRanks();
  uint64_t end = timeSinceEpochMillisec();
  cout << "End" << end;
  cout << "Time Elapsed" << end - start;
}