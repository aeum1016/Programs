#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
  vi p, rank, setSize;
  vi setEmpty;
  int numSets;
public:
  UnionFind(int N)
  {
    p.assign(N, 0); for(int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);
    setSize.assign(N, 1);
    numSets = N;
    setEmpty.assign(N, 1);
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
  int numEmptyOfSet(int i){return setEmpty[findSet(i)];}
  void fillSet(int a) { setEmpty[findSet(a)]--; }

  void unionSet(int i, int j)
  {
    if(isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if(rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if(rank[x] == rank[y]) ++rank[y];
    setSize[y] += setSize[x];
    --numSets;
    setEmpty[y] += setEmpty[x];
  }
};

int main() {
  int items, drawers; cin >> items >> drawers;

  UnionFind uf(drawers+1);

  while(items--) {
    int a, b; cin >> a >> b;
    bool included = true;

    if(uf.sizeOfSet(a) == 1)
    {
      uf.fillSet(a);
      uf.unionSet(a, b);
    }
    else if(uf.sizeOfSet(b) == 1)
    {
      uf.fillSet(b);
      uf.unionSet(a, b);
    }
    else if(uf.numEmptyOfSet(a) > 0)
    {
      uf.fillSet(a);
      uf.unionSet(a, b);
    }
    else if(uf.numEmptyOfSet(b) > 0)
    {
      uf.fillSet(b);
      uf.unionSet(a, b);
    }
    else {
      included = false;
    }

    if(included) cout << "LADICA" << endl;
    else cout << "SMECE" << endl;

  }
  return 0;
}