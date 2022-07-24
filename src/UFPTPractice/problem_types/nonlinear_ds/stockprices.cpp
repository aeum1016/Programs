#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q; cin >> q;
  while(q--)
  {
    int a; cin >> a;
    priority_queue<pair<int, int>> buy;
    priority_queue<pair<int, int>> sell;
    int last = -1;
    while(a--)
    {
      string aN;
      int b;
      cin >> aN >> b;

      if(aN == "buy")
      {
        cin >> aN >> aN >> aN;
        buy.push(make_pair(stoi(aN), b));
      }
      else
      {
        cin >> aN >> aN >> aN;
        sell.push(make_pair(-stoi(aN), b));
      }

      if(!sell.empty() && !buy.empty())
      {
        while(buy.top().first >= abs(sell.top().first))
        {
          last = abs(sell.top().first);
          if(sell.top().second < buy.top().second)
          {
            int prevB = buy.top().first;
            int newB = buy.top().second - sell.top().second;
            buy.pop();
            buy.push(make_pair(prevB, newB));
            sell.pop();
          }
          else if(sell.top().second > buy.top().second)
          {
            int newS = sell.top().second - buy.top().second;
            sell.pop();
            sell.push(make_pair(-last, newS));
            buy.pop();
          }
          else
          {
            sell.pop();
            buy.pop();
          }
          if(sell.empty() || buy.empty()) break;
        }
      }

      if(sell.empty()) cout << "-";
      else cout << abs(sell.top().first);
      cout << " ";
      if(buy.empty()) cout << "-";
      else cout << buy.top().first;
      cout << " ";
      if(last == -1) cout << "-";
      else cout << last;
      cout << endl;
    }
  }
}