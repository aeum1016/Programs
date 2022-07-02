// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string input; cin >> input;
  string output = "";
  for(int i = 0; i < input.length(); i++)
  {
    string counter;
    if(i+2 < input.length())
    {
      string check = input.substr(i, 3);
      if(check.find("R") != string::npos && check.find("B") != string::npos && check.find("L") != string::npos)
      {
        output.append("C");
        i+=2;
        continue;
      }
    }
    output.append(input[i] == 'R' ? "S" : input[i] == 'B' ? "K" : "H");
  }
  cout << output;
  return 0;
}