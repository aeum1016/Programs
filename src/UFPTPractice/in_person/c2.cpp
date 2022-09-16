#include <bits/stdc++.h>

using namespace std;

int main() {

  int t; cin >> t;
  long long n, h;
  while(t--) {
    
    cin >> n >> h;
    vector<long long> seconds(n, 0);
    int a;
    for(int i = 0; i < n; i++) {
      cin >> a;
      seconds[i] = a;
    }

    long long low = 0, high = h;
    long long damage;
    int prevT = 0;
    while(low < high) {
      long long mid = (high+low) / 2;

      damage = 0;
      for(int i = 0; i < n; i++) {
        if(prevT == 0) prevT = seconds[i];
        else {
          if(seconds[i] - prevT < mid) damage += seconds[i] - prevT;
          else damage += mid;
          cout << damage << endl;
          prevT = seconds[i];
        }
      }
      damage += mid;
      cout << mid << " " << damage << endl;
      if(damage < h) {
        low = mid+1;
      }
      else {
        high = mid;
      }
    }
    cout << high << endl;
  }
  return 0;
}