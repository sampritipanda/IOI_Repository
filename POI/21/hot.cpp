#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_HEIGHT = 1666;
vector<int> G[5001];
int P[5001];
short sz[5001];
short dp[MAX_HEIGHT + 1][5001];
short dp_sub[MAX_HEIGHT + 1][5001];
int N, K;

void dfs_size(int i, int p) {
  sz[i] = 1;
  for(int id = 0; id < G[i].size(); id++) {
    int u = G[i][id];
    if(u == p) continue;

    dfs_size(u, i);
    sz[i] += sz[u];
  }
}

int find_centroid(int i, int p) {
  for(int id = 0; id < G[i].size(); id++) {
    int u = G[i][id];
    if(u == p) continue;
    if(sz[u] > sz[1]/2) return find_centroid(u, i);
  }
  return i;
}

void dfs(int i, int p) {
  P[i] = p;

  for(int id = 0; id < G[i].size(); id++) {
    int u = G[i][id];
    if(u == p) continue;
    dfs(u, i);
  }

  dp_sub[0][i] = 1;
  for(int j = 1; j <= K; j++) {
    dp_sub[j][i] = 0;
    for(int id = 0; id < G[i].size(); id++) {
      int u = G[i][id];
      if(u == p) continue;
      dp_sub[j][i] += dp_sub[j - 1][u];
    }
  }
}

int main() {
  scanf("%d", &N);
  K = min(N, MAX_HEIGHT);

  for(int i = 0; i < N - 1; i++) {
    int a, b; scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(int i = 1; i <= N; i++) {
    dp[1][i] = dp[0][i] = 1;
    dp[1][i] += G[i].size();
  }

  for(int j = 2; j <= K; j++) {
    for(int i = 1; i <= N; i++) {
      for(int id = 0; id < G[i].size(); id++) {
        int u = G[i][id];
        dp[j][i] += dp[j - 1][u];
        dp[j][i] -= dp[j - 2][i];
      }
      dp[j][i] += dp[j - 2][i];
    }
  }

  for(int j = K; j >= 1; j--) {
    for(int i = 1; i <= N; i++) {
      dp[j][i] -= dp[j - 1][i];
    }
  }

  dfs_size(1, 0);
  int root = find_centroid(1, 0);
  dfs(root, 0);

  long long ans = 0;
  for(int j = 1; j <= K; j++) {
    for(int i = 1; i <= N; i++) {
      long long sing = 0, doub = 0;
      for(int id = 0; id < G[i].size(); id++) {
        int u = G[i][id];
        if(u == P[i]) continue;
        ans += dp_sub[j - 1][u] * doub;
        doub += dp_sub[j - 1][u] * sing;
        sing += dp_sub[j - 1][u];
      }
      long long top = dp[j][i] - dp_sub[j][i];
      ans += top * doub;
    }
  }

  printf("%lld\n", ans);
}
