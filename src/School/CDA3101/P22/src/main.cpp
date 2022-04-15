/*  On  my  honor,  I  have  neither  given  nor  received 
unauthorized aid on this assignment */

#include <iostream>
#include <fstream>
#include <string>

#include "Simulator.h"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream inputFile(argv[argc-1]);
  Simulator s;
  cout << s.binaryToValue("11111111111111111111111111111111");
  s.simulate(inputFile);
}