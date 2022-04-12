#include "Disassembler.h"

Disassembler::Disassembler()
{
  initializeCategories();
  initializeOpcodes();
}

unordered_map<int, pair<string, string>> Disassembler::disassemble(ifstream& inputFile)
{
  ofstream outFile("disassembly.txt");
  int branchAddress = 64;
  unordered_map<int, pair<string, string>> instructions;
  
  string line;
  string opCode, instruction;
  int src1, src2, dest, srcdst, imm, branchOffset;
  bool onInstructions = true;
  while(getline(inputFile, line))
  {
    if(onInstructions)
    {
      switch(category.at(line.substr(0, 3)))
      {
        case -1:
          instruction = "DUMMY\n";
          onInstructions = false;
          break;

        case 1:
          opCode = opCodes.at(line.substr(3, 5));
          src1 = binaryToValue(line.substr(8, 5));
          branchOffset = signedBinaryToValue(line.substr(13, 19));
          instruction = opCode + " " + convert(src1) + ", #" + to_string(branchOffset) + "\n";
          break;
        
        case 2:
          opCode = opCodes.at(line.substr(3, 7));
          dest = binaryToValue(line.substr(10, 5));
          src1 = binaryToValue(line.substr(15, 5));
          if(opCode == "ADDI" || opCode == "SUBI") 
            imm = signedBinaryToValue(line.substr(20, 12));
          else
            imm = binaryToValue(line.substr(20, 12));
          instruction = opCode + " " + convert(dest) + ", " + convert(src1) + ", #" + to_string(imm) + "\n";
          break;

        case 3:
          opCode = opCodes.at(line.substr(3, 8));
          dest = binaryToValue(line.substr(11, 5));
          src1 = binaryToValue(line.substr(16, 5));
          src2 = binaryToValue(line.substr(21, 5));
          instruction = opCode + " " + convert(dest) + ", " + convert(src1) + ", " + convert(src2) + "\n";
          break;

        case 4:
          opCode = opCodes.at(line.substr(3, 8));
          srcdst = binaryToValue(line.substr(11, 5));
          src1 = binaryToValue(line.substr(16, 5));
          imm = signedBinaryToValue(line.substr(21, 11));
          instruction = opCode + " " + convert(srcdst) + ", [" + convert(src1) + ", #" + to_string(imm) + "]\n";
          break;
      }
      outFile << line << "\t" << to_string(branchAddress) << "\t" << instruction;
      instructions.emplace(branchAddress, pair<string, string>(line, instruction));
    }
    else
    {
      outFile << line << "\t" << to_string(branchAddress) << "\t" << binaryToValue(line) << "\n";
      memory.emplace(branchAddress, binaryToValue(line));
    }
    branchAddress += 4;
  }
  outFile.close();
  return instructions;
}

void Disassembler::initializeCategories()
{
  category.emplace("101", -1);
  category.emplace("001", 1);
  category.emplace("010", 2);
  category.emplace("011", 3);
  category.emplace("100", 4);
}
void Disassembler::initializeOpcodes()
{
  opCodes.emplace("10000", "CBZ");
  opCodes.emplace("10001", "CBNZ");
  opCodes.emplace("1000000", "ORRI");
  opCodes.emplace("1000001", "EORI");
  opCodes.emplace("1000010", "ADDI");
  opCodes.emplace("1000011", "SUBI");
  opCodes.emplace("1000100", "ANDI");
  opCodes.emplace("10100000", "EOR");
  opCodes.emplace("10100010", "ADD");
  opCodes.emplace("10100011", "SUB");
  opCodes.emplace("10100100", "AND");
  opCodes.emplace("10100101", "ORR");
  opCodes.emplace("10100110", "LSR");
  opCodes.emplace("10100111", "LSL");
  opCodes.emplace("10101010", "LDUR");  
  opCodes.emplace("10101011", "STUR");  
}

int Disassembler::binaryToValue(string bin)
{
  int val = 0;
  for(int i = 0; i < bin.length(); i++)
  {
    int addition = pow(2, bin.length()-i-1);
    if(bin.at(i) != '0') val += addition;
  }
  return val;
}

int Disassembler::signedBinaryToValue(string bin)
{
  int val = 0;
  for(int i = 0; i < bin.length(); i++)
  {
    int addition = pow(2, bin.length()-i-1);
    if(bin.at(i) == '1') i == 0 ? val -= addition : val += addition;
  }
  return val;
}

string Disassembler::convert(int regNum)
{
  if(regNum == 31) return "XZR";
  else return "X" + to_string(regNum);
}

map<int, int> Disassembler::getMemory()
{
  return memory;
}