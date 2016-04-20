// Facebook

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <climits>

using namespace std;

vector<vector<pair<int, int> > > G;
vector<pair<pair<int, int>, int> > edges;
vector<int> D;
set<pair<int, int> > PQ;
int N;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int M, Q; cin >> N >> M >> Q;

  G.resize(N); edges.resize(M); D.resize(N);

  for(int i = 0; i < M; i++) {
    int x, y, d; cin >> x >> y >> d;
    G[x].push_back({y, d}); G[y].push_back({x, d});

    edges[i] = {{x, y}, d};
  }

  while(Q--) {
    int id; cin >> id;
    int x = edges[id].first.first, y = edges[id].first.second;

    fill(D.begin(), D.end(), INT_MAX/2); PQ.clear();

    D[0] = 0;
    PQ.insert({D[0], 0});
    while(!PQ.empty()) {
      auto it = *PQ.begin(); PQ.erase(it);
      int u = it.second, d = it.first;

      for(auto it: G[u]) {
        int v = it.first, cost = it.second;

        if((u == x && v == y) || (u == y && v == x)) continue;

        if(D[v] > D[u] + cost) {
          if(D[v] != INT_MAX/2) {
            PQ.erase({D[v], v});
          }
          D[v] = D[u] + cost;
          PQ.insert({D[v], v});
        }
      }
    }

    if(D[N - 1] == INT_MAX/2) cout << -1 << endl;
    else cout << D[N - 1] << endl;
  }
}
