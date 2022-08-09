#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;

class UnionFind {
private:
  vi p, rank, setSize;
  vll vals, setSums;
  int numSets;
  int counter;
public:
  vi m;
  UnionFind(int N)
  {
    p.assign(N, 0);
    m.assign(N, 0);
    vals.assign(N, 0);
    rank.assign(N, 0);
    setSize.assign(N, 1);
    setSums.assign(N, 0);
    numSets = N;
    for(int i = 0; i < N; ++i) {
      p[i] = i;
      m[i] = i;
      vals[i] = i+1;
      setSums[i] = i+1;
    }
    counter = N;
  }

  int findSet(int i){
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
  }
  int numDisjointSets(){
    return numSets;
  }
  int sizeOfSet(int i)
  {
    return setSize[findSet(i)];
  }

  long long sumOfSet(int i) {
    return setSums[findSet(i)];
  }

  void unionSet(int i, int j)
  {
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) ++rank[y];
    setSize[y] += setSize[x];
    setSums[y] += setSums[x];
    --numSets;
  }

  void moveSet(int i, int j) {
    if(isSameSet(m[i], m[j])) return;

    p.push_back(counter);
    rank.push_back(0);
    setSize.push_back(1);
    vals.push_back(vals[i]);
    setSums.push_back(vals[i]);

    setSize[findSet(m[i])]--;
    setSums[findSet(m[i])] -= vals[m[i]];

    m[i] = counter;
    counter++;

    unionSet(m[i], m[j]);
  }
};

int main() {
  int n, m, t, p, q;
  while(scanf("%d %d", &n, &m) != EOF) {
    UnionFind uf(n);
    for(int i = 0; i < m; i++) {
      scanf("%d", &t);
      if(t == 1) {
        scanf("%d %d", &p, &q);
        p--; q--;
        uf.unionSet(uf.m[p], uf.m[q]);
      }
      else if (t == 2) {
        scanf("%d %d", &p, &q);
        p--; q--;
        uf.moveSet(p, q);
      }
      else {
        scanf("%d", &p);
        p--;
        printf("%d %lld\n", uf.sizeOfSet(uf.m[p]), uf.sumOfSet(uf.m[p]));
      }
    }
  }
}