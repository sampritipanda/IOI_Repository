#include <iostream>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

vector<pair<int, int> > G[10001];  // 1 = up, 2 = down
int D[10001][3];
bool visited[10001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  for(int i = 0; i <= N; i++) {
    D[i][0] = D[i][1] = D[i][2] = INT_MAX/2;
  }

  while(M--) {
    int u, v; cin >> u >> v;
    G[u].push_back({v, 1});
    G[v].push_back({u, 2});
  }

  int S, E; cin >> S >> E;

  set<vector<int> > Q;  // cost, vertex, state
  Q.insert({0, S, 0});
  D[S][0] = 0;

  while(!Q.empty()) {
    auto it = *Q.begin(); Q.erase(Q.begin());
    int d = it[0], u = it[1], s = it[2];

    for(auto it2: G[u]) {
      int v = it2.first, s2 = it2.second;
      int cost = 0;
      if(s == 1 && s2 == 2) cost = 1;
      else if(s == 2 && s2 == 1) cost = 1;

      if(D[u][s] + cost < D[v][s2]) {
        if(D[v][s2] != INT_MAX/2) {
          Q.erase(Q.lower_bound({D[v][s2], v, s2}));
        }
        D[v][s2] = D[u][s] + cost;
        Q.insert({D[v][s2], v, s2});
      }
    }
  }

  cout << min(D[E][1], D[E][2]) << endl;
}
