#include "Simulator.h"
#include "Disassembler.h"

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