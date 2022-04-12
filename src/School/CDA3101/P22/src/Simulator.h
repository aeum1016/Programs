#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

class Simulator
{    
  private:
    enum opCodes { CBZ, CBNZ, ADDI, SUBI, ANDI, ORRI, EORI, ADD, SUB, AND, ORR, EOR, LSR, LSL, LDUR, STUR, DUMMY };
    unordered_map<string, int> category;
    unordered_map<string, opCodes> opCodeMap;
    unordered_map<int, pair<string, string>> instructions;
    map<int, int> memory;
    vector<int> registers;

  public:
    Simulator();
    void simulate(ifstream& inputFile);
    void handleInstruction(int cycle, int& address, pair<string, string> instruction, ofstream& outFile);
    void initializeCategories();
    void initializeOpcodes();
    int binaryToValue(string bin);
    int signedBinaryToValue(string bin);
    string convert(int regNum);
    void printRegisters(ofstream& outFile);
    void printMemory(ofstream& outFile);
};