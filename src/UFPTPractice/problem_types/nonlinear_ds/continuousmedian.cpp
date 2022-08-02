#include <bits/stdc++.h>

using namespace std;

#include <bits/extc++.h>                         // pbds

using namespace __gnu_pbds;

typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag,
            tree_order_statistics_node_update> ost;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q; cin >> q;
  ost t;
  long long ans = 0;
  long long med;
  while(q--)
  {
    t.clear();
    ans = 0;
    int n; cin >> n;
    while(n--)
    {
      int a; cin >> a;
      t.insert(a);
      if(t.size() % 2){
        med = *t.find_by_order((t.size()-1)/2);
        ans += med;
      }
      else{
        med = *t.find_by_order(t.size()/2);
        med += *t.find_by_order((t.size()-1)/2);
        ans += med/2;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
