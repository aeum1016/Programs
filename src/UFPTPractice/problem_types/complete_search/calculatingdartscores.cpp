#include <bits/stdc++.h>

using namespace std;

void printDart(int val, int mult) {
  if(val) {
    if(mult == 3) cout << "triple ";
    else if(mult == 2) cout << "double ";
    else cout << "single ";
    cout << val << "\n";
  }
}

int main() {

  int n; cin >> n;

  for(int i = 20; i > 0; i--) {
    for(int i2 = 3; i2 > 0; i2--) {
      for(int j = 20; j >= 0; j--) {
        for(int j2 = 3; j2 > 0; j2--) {
          for(int k = 20; k >= 0; k--) {
            for(int k2 = 3; k2 > 0; k2--) {
              if(i*i2 + j*j2 + k*k2 == n)
              {
                printDart(i, i2);
                printDart(j, j2);
                printDart(k, k2);
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "impossible";
}