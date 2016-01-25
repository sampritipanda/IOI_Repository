#include <iostream>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

vector<vector<pair<int, int> > > G;
vector<long long> D[5];
vector<bool> visited;
int market[5];
set<pair<long long, int> > Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M, K; cin >> N >> M >> K;
  G.resize(N + 1);
  visited.resize(N + 1);

  for(int i = 0; i < K; i++) cin >> market[i];

  while(M--) {
    int i, j, L; cin >> i >> j >> L;
    G[i].push_back({j, L});
    G[j].push_back({i, L});
  }

  for(int i = 0; i < K; i++) {
    D[i].resize(N + 1, LLONG_MAX/2);
    Q.clear();

    fill(visited.begin(), visited.end(), false);

    Q.insert({0, market[i]});
    D[i][market[i]] = 0;

    while(!Q.empty()) {
      int u = Q.begin()->second, d = Q.begin()->first;
      Q.erase(Q.begin());

      if(visited[u]) continue;
      visited[u] = true;

      for(auto it: G[u]) {
        int v = it.first, l = it.second;
        if(D[i][u] + l < D[i][v]) {
          if(D[i][v] != LLONG_MAX/2) {
            Q.erase({D[i][v], v});
          }
          D[i][v] = D[i][u] + l;
          Q.insert({D[i][v], v});
        }
      }
    }
  }

  long long ans = LLONG_MAX;
  for(int i = 1; i <= N; i++) {
    bool rek = false;
    for(int j = 0; j < K; j++){
      if(i == market[j]) rek = true;
    }
    if(rek) continue;

    vector<int> A;
    for(int j = 0; j < K; j++) A.push_back(j);

    do {
      long long curr = 0;
      curr += D[A[0]][i];
      for(int j = 1; j < K; j++) {
        curr += D[A[j - 1]][market[A[j]]];
      }
      curr += D[A[K - 1]][i];
      ans = min(ans, curr);
    } while(next_permutation(A.begin(), A.end()));
  }

  cout << ans << endl;
}
