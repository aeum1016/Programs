#include <bits/stdc++.h>

using namespace std;

#include <bits/extc++.h>                         // pbds

using namespace __gnu_pbds;

typedef tree<long long, null_type, greater_equal<long long>, rb_tree_tag,
            tree_order_statistics_node_update> ost;
            
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ost tree;
  vector<long long> teams((1E5)+1, 0);

  int n, m; cin >> n >> m;
  int t, p;
  while(m--)
  {
    cin >> t >> p;
    if(teams[t] != 0)
    {
      tree.erase(tree.upper_bound(teams[t]));
    }
    teams[t] += 1E9 - p;
    tree.insert(teams[t]);

    auto it = tree.upper_bound(teams[1]);
    if(it == tree.end()) cout << tree.size()+1 << endl;
    else cout << tree.order_of_key(*it)+1 << endl;
  }
  return 0;
}