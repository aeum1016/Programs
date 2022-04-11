#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <cmath>

#include "handler.h"

using namespace std;

// Read file name from cin
// Open file
// Take 32 bit instruction
// Read line
// Read first 3 bits for instruction type
// Continue while instruction isn't the dummy.
// Read opcode to determine what comes next
// Probably use an enum to store all instruction types and opcodes. and stuff too.
// Use a switch for all of the things.

int main()
{
  initialize();
  
  int branchAddress = 64;

  string filename;
  cin >> filename;
  ifstream ifs(filename);

  string line;
  while(getline(ifs, line))
  {
    if(!handleInstruction(line)) break;
  }

  return 0;
}