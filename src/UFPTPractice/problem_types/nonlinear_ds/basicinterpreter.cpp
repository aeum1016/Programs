#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string line;
  vector<pair<int, string>> commands;
  vector<int> com;
  while(getline(cin, line))
  {
    int label = stoi(line.substr(0, line.find(' ')));
    string rest = line.substr(line.find(' ')+1);
    commands.push_back(make_pair(label, rest));
    com.push_back(label);
  }
  sort(commands.begin(), commands.end());
  sort(com.begin(), com.end());

  vector<int> mem(26, 0);

  for(int i = 0; i < commands.size(); i++)
  {
    stringstream ss(commands[i].second);
    string command;
    ss >> command;
    if(command == "LET")
    {
      char varC; ss >> varC;
      int var = varC - 'A';

      ss >> varC;
      string op1; ss >> op1;
      int op1Val;
      int op3Val = 0;
      if(op1.at(0) >= 'A' && op1.at(0) <= 'Z')
      {
        op1Val = mem.at(op1.at(0)-'A');
      }
      else
      {
        op1Val = stoi(op1);
      }
      char op2 = ' ';
      ss >> op2;
      if(op2 != ' ')
      {
        string op3; ss >> op3;
        if(op3.at(0) >= 'A' && op3.at(0) <= 'Z')
        {
          op3Val = mem.at(op3.at(0)-'A');
        }
        else
        {
          op3Val = stoi(op3);
        }
      }
      if(op2 == '+') mem[var] = op1Val + op3Val;
      else if(op2 == '-') mem[var] = op1Val - op3Val;
      else if(op2 == '*') mem[var] = op1Val * op3Val;
      else if(op2 == '/') mem[var] = op1Val / op3Val;
      else mem[var] = op1Val;
    }
    else if(command == "PRINT")
    {
      string printed = commands[i].second.substr(6);
      if(printed.at(0) == '"')
      {
        cout << printed.substr(1, printed.size()-2);
      }
      else
      {
        cout << mem[printed.at(0)-'A'];
      }
    }
    else if(command == "PRINTLN")
    {
      string printed = commands[i].second.substr(8);
      if(printed.at(0) == '"')
      {
        cout << printed.substr(1, printed.size()-2) << endl;
      }
      else
      {
        cout << mem[printed.at(0)-'A'] << endl;
      }
    }
    else
    {
      string op1, op2, op3;
      int op1Val, op3Val;
      ss >> op1 >> op2 >> op3;
      string goVal;
      ss >> goVal >> goVal >> goVal;

      if(op1.at(0) >= 'A' && op1.at(0) <= 'Z')
      {
        op1Val = mem.at(op1.at(0)-'A');
      }
      else
      {
        op1Val = stoi(op1);
      }
      if(op3.at(0) >= 'A' && op3.at(0) <= 'Z')
      {
        op3Val = mem.at(op3.at(0)-'A');
      }
      else
      {
        op3Val = stoi(op3);
      }

      bool go = false;
      if(op2 == "=")
      {
        go = (op1Val == op3Val);
      }
      else if(op2 == ">")
      {
        go = (op1Val > op3Val);
      }
      else if(op2 == "<")
      {
        go = (op1Val < op3Val);
      }
      else if(op2 == "<>")
      {
        go = (op1Val != op3Val);
      }
      else if(op2 == "<=")
      {
        go = (op1Val <= op3Val);
      }
      else
      {
        go = (op1Val >= op3Val);
      }
      if(go)
      {
        auto lower = lower_bound(com.begin(), com.end(), stoi(goVal));
        i = (lower - com.begin())-1;
      }
    }
  }
  return 0;
}