#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
  string domain, codomain;
  while(getline(cin, domain))
  {
    string in, out;
    vector<string> inputs;
    vector<string> outputs;
    stringstream d(domain.substr(6));
    while(getline(d, in, ' '))
    {
      inputs.push_back(in);
    }
    
    getline(cin, codomain);
    stringstream cd(codomain.substr(9));
    while(getline(cd, out, ' '))
    {
      outputs.push_back(out);
    }

    unordered_map<int, int> maps;
    bool function = true, surjective = true, injective = true;

    int q;
    cin >> q;
    while(q--)
    {
      string a, b, t;
      cin >> a >> t >> b;
      int ia = find(inputs.begin(), inputs.end(), a) - inputs.begin(), ib = find(outputs.begin(), outputs.end(), b) - outputs.begin();
      if(maps.find(ia) != maps.end())
      {
        if(maps.at(ia) != ib)
        {
          function = false;
        }
      }
      else
      {
        maps.emplace(ia, ib);
      }
    }

    vector<int> found(outputs.size(), 0);
    
    for(auto it = maps.begin(); it != maps.end(); it++)
    {
      found[it->second]++;
    }

    for(int a : found)
    {
      if(a == 0) surjective = false;
      if(a > 1) injective = false;
    }

    if(!function) cout << "not a function" << endl;
    else if(surjective && injective) cout << "bijective" << endl;
    else if(surjective) cout << "surjective" << endl;
    else if(injective) cout << "injective" << endl;
    else cout << "neither injective nor surjective" << endl;

    char c;
    cin >> c;
  }
}