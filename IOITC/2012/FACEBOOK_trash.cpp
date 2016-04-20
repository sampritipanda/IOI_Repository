// SOLUTION DOESN'T WORK
// Facebook

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <climits>

using namespace std;

vector<vector<pair<int, int> > > G, tree, tree2;
vector<pair<pair<int, int>, int> > edges;
map<pair<int, int>, int> E_map;
vector<int> visited, D, D2, P;
set<pair<int, int> > PQ;
int N;

bool dfs(int i, int p, int x, int y) {
  if(i == N - 1) return true;

  bool leaf = true;

  for(auto it: tree[i]) {
    int v = it.first, d = it.second;
    if(v == p) continue;
    if((i == x && v == y) || (i == y && v == x)) continue;

    leaf = false;
    if(dfs(v, i, x, y)) return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int M, Q; cin >> N >> M >> Q;

  G.resize(N); edges.resize(M); D.resize(N); D2.resize(N); P.resize(N);

  for(int i = 0; i < M; i++) {
    int x, y, d; cin >> x >> y >> d;
    G[x].push_back({y, d}); G[y].push_back({x, d});

    edges[i] = {{x, y}, d};
    E_map[{x, y}] = i;
    E_map[{y, x}] = i;
  }

  fill(D.begin(), D.end(), INT_MAX/2);
  fill(P.begin(), P.end(), -1);

  D[0] = 0;
  PQ.insert({D[0], 0});
  while(!PQ.empty()) {
    auto it = *PQ.begin(); PQ.erase(it);
    int u = it.second, d = it.first;

    for(auto it: G[u]) {
      int v = it.first, cost = it.second;

      if(D[v] > D[u] + cost) {
        if(D[v] != INT_MAX/2) {
          PQ.erase({D[v], v});
        }
        D[v] = D[u] + cost;
        P[v] = u;
        PQ.insert({D[v], v});
      }
    }
  }

  tree.resize(N);
  for(int i = 1; i < N; i++) {
    tree[P[i]].push_back({i, edges[E_map[{P[i], i}]].second});
    tree[i].push_back({P[i], edges[E_map[{i, P[i]}]].second});
  }

  while(Q--) {
    int id; cin >> id;
    int x = edges[id].first.first, y = edges[id].first.second;

    tree2.clear(); tree2.resize(N);

    bool result = dfs(0, P[0], x, y);

    if(D[N - 1] == INT_MAX/2) {  // Disconnected
      cout << -1 << endl;
    }
    else if(result) {   // Node exists in new dijsktra tree
      cout << D[N - 1] << endl;
    }
    else {
      fill(D2.begin(), D2.end(), INT_MAX/2); PQ.clear();

      D2[0] = 0;
      PQ.insert({D2[0], 0});
      while(!PQ.empty()) {
        auto it = *PQ.begin(); PQ.erase(it);
        int u = it.second, d = it.first;

        for(auto it: G[u]) {
          int v = it.first, cost = it.second;

          if((u == x && v == y) || (u == y && v == x)) continue;

          if(D2[v] > D2[u] + cost) {
            if(D2[v] != INT_MAX/2) {
              PQ.erase({D2[v], v});
            }
            D2[v] = D2[u] + cost;
            PQ.insert({D2[v], v});
          }
        }
      }

      if(D2[N - 1] == INT_MAX/2) cout << -1 << endl;
      else cout << D2[N - 1] << endl;
    }
  }
}
