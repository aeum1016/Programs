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

  int N, Q; cin >> N >> Q;
  vector<int> values;
  FenwickTree gem1(N), gem2(N), gem3(N), gem4(N), gem5(N), gem6(N);

  for(int i = 0; i < 6; i++) {
    int value; cin >> value;
    values.push_back(value);
  }

  for(int i = 0; i < N; i++) {
    char gem; cin >> gem;
    gem = gem-'0';
    if(gem == 1) gem1.update(i, 1);
    if(gem == 2) gem2.update(i, 1);
    if(gem == 3) gem3.update(i, 1);
    if(gem == 4) gem4.update(i, 1);
    if(gem == 5) gem5.update(i, 1);
    if(gem == 6) gem6.update(i, 1);
  }

  int type, p1, p2;
  for(int i = 0; i < Q; i++) {
    cin >> type;
    if(type == 1) {
      cin >> p1 >> p2;
      
      if(gem1.rsq(p1, p1)) gem1.update(p1-1, -1);
      if(gem2.rsq(p1, p1)) gem2.update(p1-1, -1);
      if(gem3.rsq(p1, p1)) gem3.update(p1-1, -1);
      if(gem4.rsq(p1, p1)) gem4.update(p1-1, -1);
      if(gem5.rsq(p1, p1)) gem5.update(p1-1, -1);
      if(gem6.rsq(p1, p1)) gem6.update(p1-1, -1);

      if(p2 == 1) gem1.update(p1-1, 1);
      if(p2 == 2) gem2.update(p1-1, 1);
      if(p2 == 3) gem3.update(p1-1, 1);
      if(p2 == 4) gem4.update(p1-1, 1);
      if(p2 == 5) gem5.update(p1-1, 1);
      if(p2 == 6) gem6.update(p1-1, 1);
    }
    else if(type == 2) {
      cin >> p1 >> p2;
      values[p1-1] = p2;
    }
    else if(type == 3) {
      cin >> p1 >> p2;
      long long sum = 0;
      sum += gem1.rsq(p1, p2) * values[0];
      sum += gem2.rsq(p1, p2) * values[1];
      sum += gem3.rsq(p1, p2) * values[2];
      sum += gem4.rsq(p1, p2) * values[3];
      sum += gem5.rsq(p1, p2) * values[4];
      sum += gem6.rsq(p1, p2) * values[5];
      cout << sum << endl;
    }
  }
}