#include <bits/stdc++.h>

using namespace std;

int main()
{
  int r, b; cin >> r >> b;
  bool rooms[r+1];
  fill(rooms, rooms+r+1, 0);

  if(r == b) 
  {
    cout << "too late";
    return 0;
  }
  while(b--)
  {
    int a; cin >> a;
    rooms[a] = true;
  }
  for(int i = 1; i <= r; i++)
  {
    if(!rooms[i])
    {
      cout << i;
      return 0;
    }
  }
}