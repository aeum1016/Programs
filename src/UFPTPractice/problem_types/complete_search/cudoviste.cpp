#include <bits/stdc++.h>

using namespace std;

int main() {

  int r, c; cin >> r >> c;
  vector<vector<char>> spots(r, vector<char>(c));
  vector<int> crush(5,0);
  int ctr = 0;
  char ch;
  bool building = false;

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> ch; spots[i][j] = ch;
    }
  }

  for(int i = 0; i < r-1; i++) {
    for(int j = 0; j <  c-1; j++) {
      ctr = 0;
      building = false;
      for(int k = 0; k < 2; k++) {
        for(int l = 0; l < 2; l++) {
          if(spots[i+k][j+l] == '#') {
            building = true;
            break;
          }
          if(spots[i+k][j+l] == 'X') ctr++;
        }
        if(building) break;
      }
      if(building) continue;
      crush[ctr]++;
    }
  }

  for(int a : crush) cout << a << "\n";

  return 0;
}