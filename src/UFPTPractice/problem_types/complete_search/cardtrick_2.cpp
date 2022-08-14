#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<vector<int>> cards(13, vector<int>(13, 0));
  queue<int> q; 

  for(int i = 1; i <= 13; i++) {

    q = queue<int>();

    for(int j = 1; j <= i; j++) {
      q.push(j);
    }
    
    for(int j = 1; j <= i; j++) {

      for(int k = 0; k < j; k++) {
        int pos = q.front();
        q.pop();
        q.push(pos);
      }
      cards[i-1][q.front()-1] = j;
      q.pop(); 
    }
  }
  int tc;
  cin >> tc;
  while(tc--) {
    int q; cin >> q;
    for(int j = 0; j < q; j++) {
      cout << cards[q-1][j] << " ";
    }
    cout << "\n";
  }
}