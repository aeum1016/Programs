#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 2147483647;
    map<int, int> lasts;

    for(int i = 0; i < n; i++)
    {
      int q;
      cin >> q;
      try{
        int last = lasts.at(q);
        ans = min(i - last, ans);
      }
      catch(exception e){}

      lasts[q] = i;
    }

    cout << ((ans == 2147483647) ? -1 : ans);

    return 0;
}