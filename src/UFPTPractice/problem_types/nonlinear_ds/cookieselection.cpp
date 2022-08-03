#include <bits/stdc++.h>

using namespace std;

#include <bits/extc++.h>                         // pbds

using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
            tree_order_statistics_node_update> ost;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ost t;
  string d;
  while(getline(cin, d))
  {
    if(d == "#")
    {
        cout << *t.find_by_order(t.size()/2) << endl;
        t.erase(t.find_by_order(t.size()/2));
    }
    else
    {
      t.insert(stoi(d));
    }
  }
  return 0;
}