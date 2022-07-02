#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
  string T, t;
  while(getline(cin, t))
  {

    if(t.find(".......") == 0)
    {
      t = t.substr(7);
      T.append(t);
      break;
    }
    T.append(t);
    T.append(" ");
  }


  string input; getline(cin, input);
  vector<int> index;
  while(T.find(input, index.size() == 0 ? 0 : index.at(index.size()-1)+1) != string::npos)
  {
    index.push_back(T.find(input, index.size() == 0 ? 0 : index.at(index.size()-1)+1));
  }

  if(index.size() == 0) cout << -1;
  else
  {
    for(int i : index)
    {
      cout << i << endl;
    }
  }

  transform(T.begin(), T.end(), T.begin(), [](unsigned char c){return tolower(c);});

  vector<string> tokens;
  index.clear();

  while(T.find_first_of(" .\0", index.size() == 0 ? 0 : index.at(index.size()-1)+1) != string::npos)
  {
    index.push_back(T.find_first_of(" .\0", index.size() == 0 ? 0 : index.at(index.size()-1)+1));
    T.find_first_of(" .\0", index.size() == 0 ? 0 : index.at(index.size()-1)+1);
    tokens.push_back(T.substr(index.at(index.size()-1)+1, T.find_first_of(" .\0", index.size() == 0 ? 0 : index.at(index.size()-1)+1)));
  }

  if(tokens.size() == 0) cout << -1;
  else
  {
    for(string i : tokens)
    {
      cout << i << endl;
    }
  }

  return 0;
}