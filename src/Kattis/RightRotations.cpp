#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> arr;

    for(int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      arr.push_back(a);
    }

    for(int i = 0; i < q; i++){
      int query;
      cin >> query;
      k = k % n;
      cout << arr.at((n + (query-k)) % n) << endl;
    }

    return 0;
}