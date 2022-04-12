#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

class Disassembler
{
  private:
    unordered_map<string, int> category;
    unordered_map<string, string> opCodes;
    map<int, int> memory;
  public:
    Disassembler();
    unordered_map<int, pair<string,string>> disassemble(ifstream& inputFile);
    void initializeCategories();
    void initializeOpcodes();
    int binaryToValue(string bin);
    int signedBinaryToValue(string bin);
    string convert(int regNum);
    void printMemory(ofstream& outFile);
    map<int, int> getMemory();
};