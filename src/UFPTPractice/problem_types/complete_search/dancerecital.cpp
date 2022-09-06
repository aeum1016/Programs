#include <bits/stdc++.h>

using namespace std;

int main() {

  int n; cin >> n;
  vector<int> recitals(n, 0);

  string s;

  for(int i = 0; i < n; i++) {
    cin >> s;
    for(int j = 0; j < s.size(); j++) {
      recitals[i] += 1 << (s.at(j)-'a');
    }
  }
  
  sort(recitals.begin(), recitals.end());

  int ans = 500;
  int cur = 0;

  while(next_permutation(recitals.begin(), recitals.end())) {
    cur = 0;
    for(int i = 0; i < n-1; i++) {
      for(int j =  0; j < 26; j++) {
        if(recitals[i] & (1 << j) && recitals[i+1] & (1 << j)) {
          cur++;
          if(cur > ans) break;
        }
      }
      if(cur > ans) break;
    }
    ans = min(ans, cur);
  }
  
  cout << ans;

  return 0; 
}