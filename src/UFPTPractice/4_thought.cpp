#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void buildAllEquations(vector<string>& equations, string equation, int op)
{
  if(op == 4)
  {
    equations.push_back(equation);
    return;
  }
  buildAllEquations(equations, equation.append("+"), op+1);
  equation = equation.substr(0, equation.length()-1);
  buildAllEquations(equations, equation.append("-"), op+1);
  equation = equation.substr(0, equation.length()-1);
  buildAllEquations(equations, equation.append("*"), op+1);
  equation = equation.substr(0, equation.length()-1);
  buildAllEquations(equations, equation.append("/"), op+1);
}

void evalMult(string& equation, vector<int>& nums)
{
  int i = 0;
  while(i < equation.length())
  {
    if(equation.at(i) == '*')
    {
      nums[i] = nums[i] * nums[i+1];
      nums.erase(nums.begin() + i + 1);
      equation.erase(equation.begin() + i);
    }
    else if(equation.at(i) == '/')
    {
      nums[i] = nums[i] / nums[i+1];
      nums.erase(nums.begin() + i + 1);
      equation.erase(equation.begin() + i);
    }
    else i++;
  }
}

void evalAdd(string& equation, vector<int>& nums)
{
  int i = 0;
  while(i < equation.length())
  {
    if(equation.at(i) == '+')
    {
      nums[i] = nums[i] + nums[i+1];
      nums.erase(nums.begin() + i + 1);
      equation.erase(equation.begin() + i);
    }
    else if(equation.at(i) == '-')
    {
      nums[i] = nums[i] - nums[i+1];
      nums.erase(nums.begin() + i + 1);
      equation.erase(equation.begin() + i);
    }
    else i++;
  }
}

int evalEquation(string equation)
{
  vector<int> nums = {4, 4, 4, 4};
  evalMult(equation, nums);
  evalAdd(equation, nums);
  return nums[0];
}


int main()
{
  vector<string> equations;
  unordered_map<int, string> mapping;

  buildAllEquations(equations, "", 1);

  for(string eq : equations)
  {
    mapping.emplace(evalEquation(eq), eq);
  }

  int q; scanf("%d", &q);

  while(q--)
  {
    int N; scanf("%d", &N);
    if(mapping.find(N) != mapping.end())
    {
      string eq = mapping.at(N);
      printf("4 %c 4 %c 4 %c 4 = %d\n", eq.at(0), eq.at(1), eq.at(2), N);
    }
    else printf("no solution\n");
  }
}