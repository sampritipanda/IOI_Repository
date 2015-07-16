// A game on a graph

#include <iostream>
#include <algorithm>

using namespace std;

vector<int> graph[2001];

int main() {
  int T; cin >> T;

  while(T--) {
    for(int i = 0; i <= 2000; i++) graph[i].clear();

    int N, M; cin >> N >> M;

    for(int i = 0; i < M; i++) {
      int u, v; cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
  }
}
