#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, m; cin >> n >> m;
  vector<int> wh(n, 0);
  int h;
  while(n--) {
    cin >> h; wh[wh.size()-n-1] = h;
  }
  vector<long long> increasing(wh.size(), 0);
  vector<long long> decreasing(wh.size(), 0);
  for(int i = 1; i < wh.size(); i++) {
    increasing[i] = increasing[i-1] + (max(0, wh[i-1] - wh[i]));
  }
  for(int i = wh.size()-1; i > 0; i--) {
    decreasing[i-1] = decreasing[i] + (max(0, wh[i] - wh[i-1]));
  }

  int s, t;
  while(m--) {
    cin >> s >> t;
    long long a = 0;
    if(t > s) {
      a = increasing[t-1] - increasing[s-1];
    }
    else {
      a = decreasing[t-1] - decreasing[s-1];
    }
    cout << a << "\n";
  }

  return 0;
}