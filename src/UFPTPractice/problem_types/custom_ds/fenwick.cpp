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
    i++;
    for(; i < ft.size(); i += LSOne(i))
      ft[i] += v;
  }
};


int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n, m; cin >> n >> m;
  
  FenwickTree ft(n);

  char c; long long a, b; 
  
  while(m--) {
    cin >> c;
    if(c == '+') {
      cin >> a >> b;
      ft.update(a, b);
    }

    if (c == '?') {
      cin >> a;
      cout << ft.rsq(a) << "\n";
    }
  }
  return 0;
}