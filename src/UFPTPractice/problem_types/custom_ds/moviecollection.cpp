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

  int tc, m, q;
  int j = 0;
  int r = 0;
  cin >> tc;
  while(tc--) {
    
    cin >> m >> q;

    FenwickTree ft(m+q+1);
    vector<int> pos(m+1); 
    for(int i = 1; i <= m; i++) pos[i] = m-i+1;

    for(int i = 1; i <= m; i++) {
      ft.update(i, 1);
    }

    for(int i = 0; i < q; i++) {
      int c; cin >> c;
      cout << m - ft.rsq(pos[c]) - 1 << " ";
      ft.update(pos[c], -1);
      pos[c] = m+i+1;
      ft.update(pos[c], 1);
    }
    cout << "\n";
  }

}