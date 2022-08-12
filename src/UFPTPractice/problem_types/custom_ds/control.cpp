#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N)
  {
    p.assign(N, 0); for(int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);
    setSize.assign(N, 1);
    numSets = N;
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

  void unionSet(int i, int j)
  {
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) ++rank[y];
    setSize[y] += setSize[x];
    --numSets;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  UnionFind uf(500001);
  int recipes = 0;

  while(n--) {
    unordered_set<int> sets; 
    int size = 0;
    int s; cin >> s;
    for(int i = 0; i < s; i++)
    {
      int j; cin >> j;
      if(sets.find(uf.findSet(j)) == sets.end()){
        sets.emplace(uf.findSet(j));
        size += uf.sizeOfSet(j);
      }
    }
    if(size == s) {
      recipes++;
      int prev = -1;
      for(auto it = sets.begin(); it != sets.end(); it++)
      {
        if(prev == -1) prev = *it;
        else {
          uf.unionSet(prev, *it);
          prev = *it;
        }
      }
    }
  }
  cout << recipes << endl;
  return 0;
}