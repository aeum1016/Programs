#include <bits/stdc++.h>

using namespace std;

class Flight{
public:
  int source;
  int destination;
  int capacity;
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // have an array of the current number of people at an airport
  // have a count of non-specified destination people - (anyone who took a flight)
  // that's it

  int airports, days, flights; cin >> airports >> days >> flights;

  vector<vector<Flight>> allFlights(days, vector<Flight>());
  vector<vector<int>> people(days+1, vector<int>(airports, 0));

  for(int i = 0; i < flights; i++)
  {
    int u, v, d, z; cin >> u >> v >> d >> z;
    Flight nf;
    nf.source = u-1;
    nf.destination = v-1;
    nf.capacity = z;
    allFlights[d-1].push_back(nf);
  }

  for(int i = 0; i < airports*days; i++)
  {
    int airport, day, p; cin >> airport >> day >> p;
    people[day-1][airport-1] += p;
  }

  for(int i = 0; i < days; i++)
  {
    for(int j = 0; j < allFlights[i].size(); j++)
    {
      int airport = allFlights[i][j].source;
      int requiredPeople = allFlights[i][j].capacity;
      int dest = allFlights[i][j].destination;
      if(people[i][airport] < requiredPeople) {
        cout << "suboptimal";
        return 0;
      }
      else {
        people[i][airport] -= requiredPeople;
        people[i+1][dest] += requiredPeople;
      }
    }
    for(int j = 0; j < airports; j++) {
      people[i+1][j] += people[i][j];
    }
  }
  cout << "optimal";
  return 0;
}