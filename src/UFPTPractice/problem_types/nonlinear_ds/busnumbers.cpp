#include <bits/stdc++.h>

using namespace std;

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  bool buses[1002];
  fill(buses, buses+1002, 0);

  int q; cin >> q;

  while(q--)
  {
    int bus; 
    cin >> bus;
    buses[bus] = true;
  }

  int streak = 0;

  for(int i = 1; i <= 1001; i++)
  {
    if(buses[i])
    {
      if(streak == 0) cout << i;
      streak++;
    }
    else
    {
      if(streak > 1)
      {
        if(streak == 2) cout << " " << i-1 << " ";
        else cout << "-" << i-1 << " ";
      }
      if(streak == 1) cout << " ";
      streak = 0;
    }
  }

  return 0;
}