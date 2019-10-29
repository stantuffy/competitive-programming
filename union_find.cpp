#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

class UnionFind {
  private:
    vi p, rank, m_sizeOfSet;
    int numSets;

  public:
    UnionFind(int N) {
      numSets = N;
      rank.assign(N, 0);
      m_sizeOfSet.assign(N, 1);
      p.assign(N, 0);
      for(int i=0; i<N; i++)
        p[i] = i;
    }

    int findSet(int i) {
      if(p[i] == i)
        return i;

      p[i] = findSet(p[i]);
      return p[i];
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    int numDisjointSets() {
      return numSets;
    }

    int sizeOfSet(int i) {
      return m_sizeOfSet[findSet(i)];
    }

    void unionSet(int i, int j) {
      if(isSameSet(i, j))
        return;

      int x = findSet(i), y = findSet(j);

      if(rank[x] > rank[y]) {
        p[y] = x;
        m_sizeOfSet[x] += m_sizeOfSet[y];
      }
      else {
        p[x] = y;
        m_sizeOfSet[y] += m_sizeOfSet[x];
        if(rank[x] == rank[y])
          rank[y] ++;
      }

      numSets --;
    }
};

int main() {
  int n = 5;
  UnionFind uf(n);

  cout << "Num of sets: " << uf.numDisjointSets() << endl;

  uf.unionSet(0, 1);
  cout << "\nunionSet(0,1)" << endl;
  cout << "Num of sets: " << uf.numDisjointSets() << endl << "size of set 1: " << uf.sizeOfSet(1) << endl;

  uf.unionSet(2, 3);
  cout << "\nunionSet(2,3)" << endl;
  cout << "Num of sets: " << uf.numDisjointSets() << endl << "size of set 2: " << uf.sizeOfSet(2) << endl;

  uf.unionSet(4, 3);
  cout << "\nunionSet(4,3)" << endl;
  cout << "Num of sets: " << uf.numDisjointSets() << endl << "size of set 3: " << uf.sizeOfSet(3) << endl;

  cout << "\nisSameSet(2,4) = " << uf.isSameSet(2, 4) << endl;
}