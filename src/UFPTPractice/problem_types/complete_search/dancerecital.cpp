#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S));

string recitals[10];

int main() {

  int n; cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> recitals[i];
  }
  
  sort(recitals, recitals+n);

  int ans = 500;

  do{
    int changes = 0, dance1 = 0, dance2 = 0;

    for (auto dancer: recitals[0]) {
      dance2 = dance2 | (1<<(dancer - 'A'));
    }

    for(int i = 1; i < n; i++) {
      dance1 = dance2;
      dance2 = 0;
      for(auto dancer : recitals[i]) {
        dance2 = dance2 | (1 << (dancer - 'A'));
      }

      int dance_combine = dance1 & dance2;

      while(dance_combine > 0) {
        dance_combine -= LSOne(dance_combine);
        changes++;
      }

      if (changes > ans) break;
    }

    ans = min(ans, changes);
  }
  while(next_permutation(recitals, recitals+n));
  
  cout << ans;

  return 0; 
}