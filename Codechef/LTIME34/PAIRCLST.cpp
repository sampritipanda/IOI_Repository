#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>

using namespace std;

vector<pair<int, long long> > G[100001];
int is_spl[100001];
vector<long long> D;
set<pair<long long, int> > Q;

int main() {
  int N, M, K; scanf("%d %d %d", &N, &M, &K);

  D.resize(N + 1);

  for(int i = 0; i < K; i++) {
    int x; scanf("%d", &x);
    is_spl[x] = 1;
  }

  while(M--) {
    int X, Y; long long Z; scanf("%d %d %lld", &X, &Y, &Z);

    G[X].push_back({Y, Z});
    G[Y].push_back({X, Z});
  }

  long long curr_ans = LLONG_MAX/2;

  for(int k = 1; k <= N; k++) {
    if(!is_spl[k]) continue;

    Q.clear();
    for(int i = 1; i <= N; i++) D[i] = LLONG_MAX/2;
    Q.insert({0, k}); D[k] = 0;

    while(!Q.empty()) {
      auto curr = *Q.begin(); Q.erase(Q.begin());
      int u = curr.second;

      if(u != k && is_spl[u]) {
        curr_ans = D[u];
        break;
      }

      for(auto it: G[u]) {
        long long w = it.second; int v = it.first;
        if(D[u] + w < D[v] && D[u] + w < curr_ans) {
          if(D[v] != LLONG_MAX/2) {
            Q.erase({D[v], v});
          }
          D[v] = D[u] + w;
          Q.insert({D[v], v});
        }
      }
    }
  }

  printf("%lld\n", curr_ans);
}
