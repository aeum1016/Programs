#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;
  vector<char> output;
  for(int i = 0; i < b.size()-1; i++)
  {
    if((int)a.size()-1-i >= 0)
    {
      if(a.at(a.size()-1-i) == '0' && output.size() == 0) continue;
      else output.push_back(a.at(a.size()-1-i));
    }
    else
    {
      output.push_back('0');
    }
  }
  if(output.size())output.push_back('.');
  if(b.size() > a.size()) output.push_back('0');
  else{
    for(int i = 0; i <= a.size() - b.size(); i++)
    {
      output.push_back(a.at((a.size()-b.size())-i));
    }
  }
  for(int i = output.size()-1; i >= 0; i--)
  {
    cout << output.at(i);
  }
  return 0;
}