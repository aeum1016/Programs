#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & (-S))

typedef vector<long long> vll;

class FenwickTree {
private:
  vll ft;
public:
  FenwickTree(long long m) {ft.assign(m+1, 0);}

  long long rsq(long long j) {
    long long sum = 0;
    for(; j > 0; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  long long rsq(long long i, long long j) {return rsq(j) - rsq(i-1);}

  void update(long long i, long long v) {
    for(; i < ft.size(); i += LSOne(i))
      ft[i] += v;
  }
};

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int bits, q; cin >> bits >> q;
  char c;
  int p1, p2;
  FenwickTree ft(bits);
  while(q--) {
    cin >> c;
    if(c == 'F') {
      cin >> p1;
      if(ft.rsq(p1, p1)) ft.update(p1, -1);
      else ft.update(p1, 1);
    }
    else {
      cin >> p1 >> p2;
      cout << ft.rsq(p1, p2) << endl;
    }

  }

}