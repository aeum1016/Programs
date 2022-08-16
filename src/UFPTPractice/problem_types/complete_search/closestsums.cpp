#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  int c = 1;
  vector<int> raw;
  vector<int> sums;
  while(scanf("%d\n", &a) != EOF) {
    raw.clear();
    sums.clear();

    printf("Case %d:\n", c);

    for(int i = 0; i < a; i++) {
      scanf("%d\n", &b);
      raw.push_back(b);
    }

    for(int i = 0; i < a; i++) {
      for(int j = 0; j < a; j++) {
        if(i != j) sums.push_back(raw[i] + raw[j]);
      }
    }
    sort(sums.begin(), sums.end());


    scanf("%d\n", &a);
    for(int i = 0; i < a; i++) {
      scanf("%d\n", &b);
      auto lowerBound = lower_bound(sums.begin(), sums.end(), b);
      int closest;
      if(lowerBound != sums.end() && abs(*(lowerBound) - b) <= abs(*(lowerBound-1) - b) || lowerBound == sums.begin()) closest = *lowerBound;
      else closest = *(lowerBound-1);

      printf("Closest sum to %d is %d.\n", b, closest);
    }
    c++;
  }
  return 0;
}