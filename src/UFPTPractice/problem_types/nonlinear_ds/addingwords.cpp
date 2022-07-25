#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unordered_map<string, int> a;

  string line;
  while(getline(cin, line))
  {
    string command = "";
    string var;
    stringstream ss(line);
    getline(ss, command, ' ');
    if(command == "def")
    {
      string c;
      int v;
      ss >> c >> v;
      if(a.find(c) == a.end())
      {
        a.emplace(c, v);
      }
      else a[c] = v;
    }
    else if(command == "clear")
    {
      a.clear();
    }
    else
    {
      cout << line.substr(5) << " ";
      int result;
      string c; getline(ss, c, ' ');
      if(a.find(c) != a.end())
      {
        result = a[c];
      }
      else
      {
        result = -1001;
      }
      while(getline(ss, c, ' '))
      {
        if(c == "=") break;
        string b; getline(ss, b, ' ');
        if(c == "+")
        {
          if(a.find(b) != a.end() && result != -1001)
          {
            result+=a[b];
          }
          else
          {
            result = -1001;
          }
        }
        else
        {
          if(a.find(b) != a.end() && result != -1001)
          {
            result-=a[b];
          }
          else
          {
            result = -1001;
          }
        }
      }
      bool found = false;
      for(auto it = a.begin(); it != a.end(); it++)
      {
        if(it->second == result)
        {
          found = true;
          cout << it->first << endl;
        }
      }
      if(!found) cout << "unknown\n";
    }
  }
}
