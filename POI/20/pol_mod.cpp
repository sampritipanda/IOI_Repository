#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int N;
vector<int> G[250001];
int sz[250001];
int F[250001];
int dp[250001];

void dfs(int i, int p) {
  sz[i] = 1;

  for(int _ = 0; _ < G[i].size(); _++) {
    int u = G[i][_];
    if(u == p) continue;
    dfs(u, i);
    sz[i] += sz[u];
  }
}

int find_centroid(int i, int p) {
  for(int _ = 0; _ < G[i].size(); _++) {
    int u = G[i][_];
    if(u == p) continue;
    if(sz[u] >= N/2) return find_centroid(u, i);
  }
  return i;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(1, 0);
  int root = find_centroid(1, 0);
  dfs(root, 0);

  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    ans += sz[i] - 1;
  }

  for(int _ = 0; _ < G[root].size(); _++) {
    int i = G[root][_];
    F[sz[i]]++;
  }

  dp[0] = 1;
  for(int i = 1; i <= N; i++) {
    if(F[i] == 0) continue;

    for(int j = 0; j < i; j++) {
      int R = N - j, L = R;
      int sz = 0, cnt_1 = dp[R];
      while(R > 0) {
        while(L >= i && sz < F[i]) {
          L -= i;
          cnt_1 += dp[L];
          sz++;
        }
        if(dp[R]) cnt_1--, sz--;
        else dp[R] = cnt_1 > 0, sz--;
        R -= i;
      }
    }
  }

  long long curr_max = 0;
  for(int i = 0; i <= N; i++) {
    if(dp[i]) {
      curr_max = max(curr_max, 1LL * i * ((N - 1) - i));
    }
  }
  ans += curr_max;

  cout << (N - 1) << " " << ans << endl;
}
