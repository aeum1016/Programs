/*  On  my  honor,  I  have  neither  given  nor  received 
unauthorized aid on this assignment */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

Simulator::Simulator()
{
  initializeCategories();
  initializeOpcodes();
  registers = vector<int>(32, 0);
}

void Simulator::simulate(ifstream& inputFile)
{ 
  Disassembler d;
  instructions = d.disassemble(inputFile);
  memory = d.getMemory();

  ofstream outFile("simulation.txt");
  int branchAddress = 64;
  int cycle = 1;
  while(instructions.at(branchAddress).second != "DUMMY\n")
  {
    handleInstruction(cycle, branchAddress, instructions.at(branchAddress), outFile);
    cycle++;
  }
  handleInstruction(cycle, branchAddress, instructions.at(branchAddress), outFile);
}

void Simulator::handleInstruction(int cycle, int& address, pair<string, string> instruction, ofstream& outFile)
{
  for(int i = 0; i < 20; i++)
  {
    outFile << '-';
  }
  outFile << "\n";
  outFile << "Cycle " << cycle << ": \t" << address << "\t" << instruction.second << "\n";
  string inst = instruction.second.substr(0, instruction.second.find(" "));
  string line = instruction.first;
  int src1, src2, dest, srcdst, imm, branchOffset;
  switch(opCodeMap.at(inst))
  {
    case CBZ:
      src1 = binaryToValue(line.substr(8, 5));
      branchOffset = signedBinaryToValue(line.substr(13, 19));
      if(registers[src1] == 0) address += (branchOffset << 2);
      else address += 4;
      break;
    case CBNZ:
      src1 = binaryToValue(line.substr(8, 5));
      branchOffset = signedBinaryToValue(line.substr(13, 19));
      if(registers[src1] != 0) address += (branchOffset << 2);
      else address += 4;
      break;
    
    case ADDI:
      address+=4;
      dest = binaryToValue(line.substr(10, 5));
      src1 = binaryToValue(line.substr(15, 5));
      imm = signedBinaryToValue(line.substr(20, 12));
      registers[dest] = registers[src1] + imm;
      break;
    case SUBI:
      address+=4;
      dest = binaryToValue(line.substr(10, 5));
      src1 = binaryToValue(line.substr(15, 5));
      imm = signedBinaryToValue(line.substr(20, 12));
      registers[dest] = registers[src1] - imm;
      break;
    case ANDI:
      address+=4;
      dest = binaryToValue(line.substr(10, 5));
      src1 = binaryToValue(line.substr(15, 5));
      imm = binaryToValue(line.substr(20, 12));
      registers[dest] = registers[src1] & imm;
      break;
    case ORRI:
      address+=4;
      dest = binaryToValue(line.substr(10, 5));
      src1 = binaryToValue(line.substr(15, 5));
      imm = binaryToValue(line.substr(20, 12));
      registers[dest] = registers[src1] | imm;
      break;
    case EORI:
      address+=4;
      dest = binaryToValue(line.substr(10, 5));
      src1 = binaryToValue(line.substr(15, 5));
      imm = binaryToValue(line.substr(20, 12));
      registers[dest] = registers[src1] ^ imm;
      break;
    
    case ADD:
      address+=4;
      dest = binaryToValue(line.substr(11, 5));
      src1 = binaryToValue(line.substr(16, 5));
      src2 = binaryToValue(line.substr(21, 5));
      registers[dest] = registers[src1] + registers[src2];
      break;
    case SUB:
      address+=4;
      dest = binaryToValue(line.substr(11, 5));
      src1 = binaryToValue(line.substr(16, 5));
      src2 = binaryToValue(line.substr(21, 5));
      registers[dest] = registers[src1] - registers[src2];
      break;
    case AND:
      address+=4;
      dest = binaryToValue(line.substr(11, 5));
      src1 = binaryToValue(line.substr(16, 5));
      src2 = binaryToValue(line.substr(21, 5));
      registers[dest] = registers[src1] & registers[src2];
      break;
    case ORR:
      address+=4;
      dest = binaryToValue(line.substr(11, 5));
      src1 = binaryToValue(line.substr(16, 5));
      src2 = binaryToValue(line.substr(21, 5));
      registers[dest] = registers[src1] | registers[src2];
      break;
    case EOR:
      address+=4;
      dest = binaryToValue(line.substr(11, 5));
      src1 = binaryToValue(line.substr(16, 5));
      src2 = binaryToValue(line.substr(21, 5));
      registers[dest] = registers[src1] ^ registers[src2];
      break;
    case LSL:
      address+=4;
      dest = binaryToValue(line.substr(11, 5));
      src1 = binaryToValue(line.substr(16, 5));
      src2 = binaryToValue(line.substr(21, 5));
      registers[dest] = registers[src1] << registers[src2];
      break;
    case LSR:
      address+=4;
      dest = binaryToValue(line.substr(11, 5));
      src1 = binaryToValue(line.substr(16, 5));
      src2 = binaryToValue(line.substr(21, 5));
      registers[dest] = registers[src1] >> registers[src2];
      break;

    case LDUR:
      address+=4;
      srcdst = binaryToValue(line.substr(11, 5));
      src1 = binaryToValue(line.substr(16, 5));
      imm = signedBinaryToValue(line.substr(21, 11));
      registers[srcdst] = memory.at(registers[src1] + imm);
      break;
  
    case STUR:
      address+=4;
      srcdst = binaryToValue(line.substr(11, 5));
      src1 = binaryToValue(line.substr(16, 5));
      imm = signedBinaryToValue(line.substr(21, 11));
      memory.at(registers[src1] + imm) = registers[srcdst];
      break;

    case DUMMY:

    default:
      address+=4;
      break;
  }
  if(registers[31] != 0) registers[31] = 0;
  outFile << "Registers\n";
  printRegisters(outFile);
  outFile << "\n";
  outFile << "Data\n";
  printMemory(outFile);
  outFile << "\n\n";
}

void Simulator::initializeCategories()
{
  category.emplace("101", -1);
  category.emplace("001", 1);
  category.emplace("010", 2);
  category.emplace("011", 3);
  category.emplace("100", 4);
}
void Simulator::initializeOpcodes()
{
  opCodeMap.emplace("CBZ", CBZ);
  opCodeMap.emplace("CBNZ", CBNZ);
  opCodeMap.emplace("ORRI", ORRI);
  opCodeMap.emplace("EORI", EORI);
  opCodeMap.emplace("ADDI", ADDI);
  opCodeMap.emplace("SUBI", SUBI);
  opCodeMap.emplace("ANDI", ANDI);
  opCodeMap.emplace("EOR", EOR);
  opCodeMap.emplace("ADD", ADD);
  opCodeMap.emplace("SUB", SUB);
  opCodeMap.emplace("AND", AND);
  opCodeMap.emplace("ORR", ORR);
  opCodeMap.emplace("LSR", LSR);
  opCodeMap.emplace("LSL", LSL);
  opCodeMap.emplace("LDUR", LDUR);  
  opCodeMap.emplace("STUR", STUR);  
  opCodeMap.emplace("DUMMY\n", DUMMY);  
}

int Simulator::binaryToValue(string bin)
{
  int val = 0;
  for(int i = 0; i < bin.length(); i++)
  {
    int addition = pow(2, bin.length()-i-1);
    if(bin.at(i) != '0') val += addition;
  }
  return val;
}

int Simulator::signedBinaryToValue(string bin)
{
  int val = 0;
  for(int i = 0; i < bin.length(); i++)
  {
    int addition = pow(2, bin.length()-i-1);
    if(bin.at(i) == '1') i == 0 ? val -= addition : val += addition;
  }
  return val;
}

string Simulator::convert(int regNum)
{
  if(regNum == -1) return "XZR";
  else return "X" + to_string(regNum);
}

void Simulator::printRegisters(ofstream& outFile)
{
  int count = 0;
  for(int i = 0; i < 32; i++)
  {
    if(count == 0)
    {
      outFile << "X" << (i<10 ? "0" : "") << i << ": \t" << registers[i];
    }
    else
    {
      outFile << "\t" << registers[i];
    }
    count++;
    if(count == 8) outFile << "\n"; 
    count = count % 8;
  }
}

void Simulator::printMemory(ofstream& outFile)
{
  int count = 0;
  for(auto it = memory.begin(); it != memory.end(); it++)
  {
    if(count == 0)
    {
      outFile << it->first << ": \t" << it->second;
    }
    else
    {
      outFile << "\t" << it->second;
    }
    count++;
    if(count == 8) outFile << "\n"; 
    count = count % 8;
  }
}










int main(int argc, char *argv[])
{
  string fileName;
  ifstream inputFile;
  if(argc > 1)
    inputFile = ifstream(argv[argc-1]);
  else{
      cin >> fileName;
      inputFile = ifstream(fileName);
  }  
  Simulator s;
  s.simulate(inputFile);
}