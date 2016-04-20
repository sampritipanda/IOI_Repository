#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <climits>

using namespace std;

long long D[100001];
set<pair<long long, int> > Q;
vector<pair<int, long long> > G[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, P; cin >> N >> M >> P;
  for(int i = 1; i <= N; i++) D[i] = LLONG_MAX/2;

  while(P--) {
    int x; cin >> x;
    D[x] = 0;
    Q.insert({D[x], x});
  }

  while(M--) {
    int u, v; long long d; cin >> u >> v >> d;
    G[u].push_back({v, d});
    G[v].push_back({u, d});
  }

  while(!Q.empty()) {
    auto curr = *Q.begin(); Q.erase(Q.begin());

    int u = curr.second;

    for(auto it: G[u]) {
      int v = it.first; long long d2 = it.second;

      if(D[u] + d2 < D[v]) {
        if(D[v] != LLONG_MAX/2) {
          Q.erase({D[v], v});
        }
        D[v] = D[u] + d2;
        Q.insert({D[v], v});
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    if(D[i] == 0) continue;

    if(D[i] == LLONG_MAX/2) D[i] = -1;
    cout << i << " " << D[i] << endl;
  }
}
