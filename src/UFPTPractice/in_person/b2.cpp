#include <bits/stdc++.h>

using namespace std;

int main() {

  int q;
  cin >> q;

  int k, n, a, b;
  while(q--) {
    cin >> k >> n >> a >> b;

    int low = 0, high = n;
    
    while(low < high) {
      long long mid = (low+high)/2;
      long long drain = mid*a + (n-mid)*b;
      long long nDrain = (mid+1)*a + (n-mid-1)*b;
      if(drain < k && nDrain >= k) {
        cout << mid << endl;
        break;
      }
      if(drain < k) {
        low = mid+1;
      }
      else high = mid;
    }
    if(high == 0) cout << -1 << endl;
    if(low == n) cout << n << endl;
  }

  return 0;
}