#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

enum opCodes { CBZ, CBNZ, ADDI, SUBI, ANDI, ORRI, EORI, ADD, SUB, AND, ORR, EOR, LSR, LSL, LDUR, STUR };

unordered_map<string, int> category;
unordered_map<string, pair<string, opCodes>> oneOpCodes;
unordered_map<string, pair<string, opCodes>> twoOpCodes;
unordered_map<string, pair<string, opCodes>> threeOpCodes;
unordered_map<string, pair<string, opCodes>> fourOpCodes;

static void initialize()
{
  category.emplace("101", -1);
  category.emplace("001", 1);
  category.emplace("010", 2);
  category.emplace("011", 3);
  category.emplace("100", 4);

  oneOpCodes.emplace("10000", pair<string, opCodes>("CBZ", CBZ));
  oneOpCodes.emplace("10001", pair<string, opCodes>("CBZ", CBZ));

  twoOpCodes.emplace("1000000", pair<string, opCodes>("ORRI", ORRI));
  twoOpCodes.emplace("1000001", pair<string, opCodes>("EORI", EORI));
  twoOpCodes.emplace("1000010", pair<string, opCodes>("ADDI", ADDI));
  twoOpCodes.emplace("1000011", pair<string, opCodes>("SUBI", SUBI));
  twoOpCodes.emplace("1000100", pair<string, opCodes>("ANDI", ANDI));

  threeOpCodes.emplace("10100000", pair<string, opCodes>("EOR", EOR));
  threeOpCodes.emplace("10100010", pair<string, opCodes>("ADD", ADD));
  threeOpCodes.emplace("10100011", pair<string, opCodes>("SUB", SUB));
  threeOpCodes.emplace("10100100", pair<string, opCodes>("AND", AND));
  threeOpCodes.emplace("10100101", pair<string, opCodes>("ORR", ORR));
  threeOpCodes.emplace("10100110", pair<string, opCodes>("LSR", LSR));
  threeOpCodes.emplace("10100111", pair<string, opCodes>("LSL", LSL));
  
  fourOpCodes.emplace("10101010", pair<string, opCodes>("LDUR", LDUR));
  fourOpCodes.emplace("10101011", pair<string, opCodes>("STUR", STUR));
}

static int binaryToValue(string bin)
{
  int val = 0;
  for(int i = 0; i < bin.length(); i++)
  {
    int addition = pow(2, bin.length()-i-1);
    if(bin.at(i) == '1') i == 0 ? val -= addition : val += addition;
  }
  return val;
}

string convert(string rString)
{
  int r = binaryToValue(rString);
  if(r == -1)
  {
    return "XZR";
  }
  else return "X" + to_string(r);
}

static void handleCatOne(pair<string, opCodes> opCode, string src1, int branchOffset)
{
  cout << opCode.first << " " << src1 << ", #" << branchOffset << endl;
}
static void handleCatTwo(pair<string, opCodes> opCode, string dest, string src1, int immediate)
{
  cout << opCode.first << ", " << dest << ", " << src1 << ", #" << immediate << endl;
}
static void handleCatThree(pair<string, opCodes> opCode, string dest, string src1, string src2)
{
  cout << opCode.first << ", " << dest << ", " << src1 << ", " << src2 << endl;
}
static void handleCatFour(pair<string, opCodes> opCode, string srcdst, string src1, int immediate)
{
  cout << opCode.first << " " << srcdst << ", [" << src1 << ", #" << immediate << "]" << endl;
}

static bool handleInstruction(string instruction)
{
  int cat = category.at(instruction.substr(0,3));
  pair<string, opCodes> opCode;
  string src1, src2;
  string dest;
  string srcdst;
  int immediate;
  int branchOffset;
  switch(cat)
  {
    case 1:
      opCode = oneOpCodes.at(instruction.substr(3, 5));
      src1 = convert(instruction.substr(8, 5));
      branchOffset = binaryToValue(instruction.substr(13, 19));
      handleCatOne(opCode, src1, branchOffset);
      break;
    
    case 2:
      opCode = twoOpCodes.at(instruction.substr(3, 7));
      dest = convert(instruction.substr(10, 5));
      src1 = convert(instruction.substr(15, 5));
      immediate = binaryToValue(instruction.substr(20, 12));
      handleCatTwo(opCode, dest, src1, immediate);
      break;

    case 3:
      opCode = threeOpCodes.at(instruction.substr(3, 8));
      dest = convert(instruction.substr(11, 5));
      src1 = convert(instruction.substr(16, 5));
      src2 = convert(instruction.substr(21, 5));
      handleCatThree(opCode, dest, src1, src2);
      break;

    case 4:
      opCode = fourOpCodes.at(instruction.substr(3, 8));
      srcdst = convert(instruction.substr(11, 5));
      src1 = convert(instruction.substr(16, 5));
      immediate = binaryToValue(instruction.substr(21, 11));
      handleCatFour(opCode, srcdst, src1, immediate);
      break;

    case -1:
      return false;
  }
  return true;
}