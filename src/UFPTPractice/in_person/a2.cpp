#include <bits/stdc++.h>

using namespace std;

int main() {

  int low = 1, high = 1000;

  while(low < high) {
    int mid = (low+high)/2;
    cout << mid << endl;
    string s; cin >> s;
    if(s == "correct") return 0;
    else if(s == "higher") {
      low = mid+1;
    }
    else high = mid-1;
  }
  cout << high;

  return 0;
}