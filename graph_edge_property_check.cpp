#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
using vi = vector<int>;

enum class Color {
  UNVISITED, EXPLORED, VISITED
};

vi dfs_parent;
vector<Color> dfs_num;

void graphCheck(int u, vector<vi>& adjList) {
  dfs_num[u] = Color::EXPLORED;

  for(auto &v: adjList[u]) {
    if(dfs_num[v] == Color::UNVISITED) {
      dfs_parent[v] = u;
      graphCheck(v, adjList);
    }
    else if(dfs_num[v] == Color::EXPLORED) {
      if(dfs_parent[u] == v)
        printf("Back Edge - Two Way: (%d -> %d) - (%d -> %d)\n", u, v, v, u);
      else
        printf("Back Edge - Cycle: (%d -> %d)\n", u, v);
    }
    else if(dfs_num[v] == Color::VISITED)
      printf("Cross Edge: (%d -> %d)\n", u, v);
  }

  dfs_num[u] = Color::VISITED;
}

int main() {
  vector<vi> adj;
  adj.assign(5, {});

  dfs_num.assign(5, Color::UNVISITED);
  dfs_parent.assign(5, 0);

  // 0 - 1
  adj[0].push_back(1);
  adj[1].push_back(0);
  
  // 1 - 2
  adj[1].push_back(2);
  adj[2].push_back(1);

  // 1 - 3
  adj[1].push_back(3);
  adj[3].push_back(1);

  // 2 - 3
  adj[2].push_back(3);
  adj[3].push_back(2);

  // 3 - 4
  adj[3].push_back(4);
  adj[4].push_back(3);

  /**
  for(int i=0; i<(int)adj.size(); i++) {
    cout << "edges of node "<< i << ":\n";
    for(auto &e: adj[i])
      cout << "(" << i << "-> " << e << ") ";
    cout << "\n";
  }
  **/

  graphCheck(0, adj);

  for(auto &it: dfs_parent)
    cout << it << " ";
}