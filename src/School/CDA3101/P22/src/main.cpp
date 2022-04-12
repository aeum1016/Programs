#include <iostream>
#include <fstream>
#include <string>

#include "Simulator.h"

using namespace std;

int main()
{
  string filename;
  cin >> filename;
  ifstream inputFile(filename);
  Simulator s;
  s.simulate(inputFile);
}