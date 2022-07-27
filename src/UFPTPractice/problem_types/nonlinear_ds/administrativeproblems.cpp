#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc; cin >> tc;

  while(tc--)
  {
    int nCars, nEvents; cin >> nCars >> nEvents;
    unordered_map<string, vector<int>> cars;
    while(nCars--)
    {
      string n;
      int p, c, m;
      cin >> n >> p >> c >> m;
      cars.emplace(n, vector<int>({p, c, m})); 
    }
    priority_queue<pair<int, string>> events;

    while(nEvents--)
    {
      int t;
      string event;
      cin >> t;
      getline(cin, event);
      events.push({-t, event});
    }

    map<string, int> ledger;
    unordered_map<string, string> carUse;

    while(!events.empty())
    {
      string event = events.top().second;
      events.pop();
      stringstream ss(event);
      string name; ss >> name;
      char action; ss >> action;
      if(action == 'p')
      {
        string car; ss >> car;
        if(carUse.find(name) != carUse.end())
        {
          if(ledger.find(name) != ledger.end())
          {
            ledger[name] = -1;
          }
          else
          {
            ledger.emplace(name, -1);
          }
        }
        else
        {
          int cost = cars[car].at(1);
          if(!(ledger.find(name) != ledger.end() && ledger[name] == -1))
          {
            if(ledger.find(name) != ledger.end()) ledger[name]+=cost;
            else ledger.emplace(name, cost);
          }
          carUse.emplace(name, car);
        }
      }
      else if(action == 'r')
      {
        int miles; ss >> miles;
        if(carUse.find(name) == carUse.end())
        {
          if(ledger.find(name) != ledger.end())
          {
            ledger[name] = -1;
          }
          else
          {
            ledger.emplace(name, -1);
          }
        }
        else
        {
          string car = carUse[name];
          if(cars.find(car) != cars.end())
          {
            int costPerMile = cars[car].at(2);
            int cost = miles * costPerMile;
            if(!(ledger.find(name) != ledger.end() && ledger[name] == -1))
            {
              ledger[name]+=cost;
            }

            carUse.erase(name);
          }
        }
      }
      else
      {
        int damage; ss >> damage;
        if(carUse.find(name) == carUse.end())
        {
          if(ledger.find(name) != ledger.end())
          {
            ledger[name] = -1;
          }
          else
          {
            ledger.emplace(name, -1);
          }
        }
        else
        {
          string car = carUse[name];
          if(cars.find(car) != cars.end())
          {
            int carPrice = cars[car].at(0);
            int cost = (int) ceil(carPrice * (damage/100.0));
            if(!(ledger.find(name) != ledger.end() && ledger[name] == -1))
            {
              ledger[name]+=cost;
            }
          }
        }
      }
    }

    for(auto spy : ledger)
    {
      cout << spy.first << " ";
      if(spy.second == -1 || carUse.find(spy.first) != carUse.end()) cout << "INCONSISTENT\n";
      else cout << spy.second << endl;
    }
  }
}