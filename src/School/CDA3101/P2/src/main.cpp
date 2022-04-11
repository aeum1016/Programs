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
  bool end = false;

  string filename;
  cin >> filename;
  ifstream ifs(filename);
  ofstream disassemblyFile("./disassembly.txt");

  string line;
  while(getline(ifs, line))
  {
      disassemblyFile << line << "\t" << branchAddress << "\t";
    if(!end)
    {
      if(!handleInstruction(line, disassemblyFile)) 
      {
        end = true;
      }
    }
    else
    {
      disassemblyFile << binaryToValue(line) << "\n";
    }
    branchAddress+=4;
  }

  disassemblyFile.close();

  return 0;
}