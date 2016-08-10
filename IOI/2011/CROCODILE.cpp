#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>

using namespace std;

vector<pair<int, long long> > G[100000];
int E[100000];
long long D[100000], D2[100000];
int P[100000], P2[100000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, K; cin >> N >> M >> K;

  while(M--) {
    int u, v; long long d; cin >> u >> v >> d;
    G[u].push_back({v, d});
    G[v].push_back({u, d});
  }

  for(int i = 0; i < K; i++) cin >> E[i];

  for(int i = 0; i < N; i++) {
    D[i] = D2[i] = LLONG_MAX/2;
    P[i] = P2[i] = -1;
  }

  set<pair<long long, int> > Q;
  for(int i = 0; i < K; i++) {
    Q.insert({0, E[i]});
    D[E[i]] = D2[E[i]] = 0;
  }

  while(!Q.empty()) {
    auto it = *Q.begin(); Q.erase(Q.begin());
    int u = it.second;

    for(auto it2: G[u]) {
      int v = it2.first; long long dist = it2.second;
      if(P[u] == v || P2[u] == v) continue;
      if(P[v] == u) continue;

      if(D2[u] + dist < D[v]) {
        if(D[v] != LLONG_MAX/2) {
          Q.erase({D[v], v});
          D2[v] = D[v]; P2[v] = P[v];
          Q.insert({D2[v], v});
        }
        D[v] = D2[u] + dist;
        P[v] = u;
      }
      else if(D2[u] + dist < D2[v]) {
        Q.erase({D2[v], v});
        D2[v] = D2[u] + dist;
        P2[v] = u;
        Q.insert({D2[v], v});
      }
    }
  }

  cout << D2[0] << endl;
}
