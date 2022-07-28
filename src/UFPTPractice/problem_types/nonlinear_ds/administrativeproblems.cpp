#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;

  vector<string> events;
  map<string, int> ledger;
  unordered_map<string, string> carUse;
  unordered_map<string, vector<int>> cars;

  while(tc--)
  {
    events.clear();
    ledger.clear();
    carUse.clear();
    cars.clear();

    int nCars, nEvents; cin >> nCars >> nEvents;
    while(nCars--)
    {
      string n;
      int p, c, m;
      cin >> n >> p >> c >> m;
      cars.emplace(n, vector<int>({p, c, m})); 
    }

    while(nEvents--)
    {
      int t; cin >> t;
      string name; cin >> name;
      char action; cin >> action;
      string x; cin >> x;

      if(carUse.find(name) == carUse.end())
      {
        carUse.emplace(name, "");
        ledger.emplace(name, 0);
      }

      if(ledger.at(name) == -1) continue;

      if(action == 'p')
      {
        string car = x;
        if(carUse.at(name) != "")
        {
          ledger[name] = -1;
        }
        else
        {
          carUse[name] = car;
          ledger[name] += cars[car].at(1);
        }
      }
      else if(action == 'r')
      {
        int km = stoi(x);
        if(carUse[name] == "")
        {
          ledger[name] = -1;
        }
        else
        {
          ledger[name] += km * cars[carUse[name]].at(2);
          carUse[name] = "";
        }
      }
      else if(action == 'a')
      {
        int damage = stoi(x);
        if(carUse[name] == "")
        {
          ledger[name] = -1;
        }
        else
        {
          string car = carUse[name];
          if(cars.find(car) != cars.end())
          {
            ledger[name] += (int) ceil(cars[car][0] * damage / 100.0);
          }
        }
      }
    }

    for(auto spy : ledger)
    {
      cout << spy.first << " ";
      if(spy.second == -1 || carUse[spy.first] != "") cout << "INCONSISTENT\n";
      else cout << spy.second << endl;
    }
  }
}