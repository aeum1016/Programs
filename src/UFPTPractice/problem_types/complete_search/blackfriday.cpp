#include <bits/stdc++.h>

using namespace std;

int main() {
  int q; cin >> q;

  vector<int> first(6, 0);
  bitset<6> good;
  good.set();

  int val;
  int i = 0;
  while(i < q) {
    cin >> val;
    i++;
    if(!first[val-1]) first[val-1] = i;
    else good[val-1] = false;
  }

  for(int j = 5; j >= 0; j--) {
    if(good[j] && first[j]) {
      cout << first[j];
      return 0;
    }
  }
  cout << "none";
  return 0;
}