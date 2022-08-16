#include <bits/stdc++.h>

using namespace std;

int main() {

  int i, j, row, col;
  int totDif = 0;
  char c;
  for(int k = 0; k < 16; k++) {
    cin >> c;
    if(c == '.') continue;
    i = k % 4;
    j = k / 4;
    col = (c - 'A') % 4;
    row = (c - 'A') / 4;
    totDif += abs(col-i) + abs(row-j);
  }
  cout << totDif;
}