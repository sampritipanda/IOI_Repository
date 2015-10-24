// gCampus

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define INF 1000000007

using namespace std;

vector<vector<pair<int, int> > > graph;
vector<pair<int, int> > edges;
map<pair<int, int>, int> edge_map;
vector<int> edge_ineff_count;
vector<bool> visited;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int N, M; cin >> N >> M;

    graph.clear();
    graph.resize(N);
    edges.clear();
    edge_ineff_count.clear();
    edge_ineff_count.resize(M, 0);

    for(int i = 0; i < M; i++) {
      int u, v, c; cin >> u >> v >> c;
      graph[u].push_back({v, c});
      graph[v].push_back({u, c});
      edges.push_back({u, v});
    }

    for(int i = 0; i < N; i++) {
      visited.clear();
      visited.resize(N, false);

      vector<int> D(N, INF);
      vector<int> parent(N, -1);
      set<pair<int, int> > Q;
      D[i] = 0;
      Q.insert({0, i});

      while(!Q.empty()) {
        auto top = *Q.begin();
        Q.erase(Q.begin());
        int v = top.second, cost = top.first;
        for(auto it: graph[v]) {
          int v2 = it.first, cost2 = it.second;
          if(D[v2] > D[v] + cost2) {
            if(D[v2] != INF) {
              Q.erase({D[v2], v2});
            }
            D[v2] = D[v] + cost2;
            parent[v2] = v;
            Q.insert({D[v2], v2});
          }
        }
      }

      for(int i = 0; i < M; i++) edge_map[edges[i]] = i;

      for(int j = 0; j < N; j++) {
        if(j == i) continue;

        edge_map.erase({j, parent[j]});
        edge_map.erase({parent[j], j});
      }

      for(auto it: edge_map) {
        edge_ineff_count[it.second]++;
      }
      edge_map.clear();
    }

    cout << "Case #" << t << ":" << endl;
    for(int i = 0; i < M; i++) {
      if(edge_ineff_count[i] >= N) cout << i << endl;
    }
  }
}
