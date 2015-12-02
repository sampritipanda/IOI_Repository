#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<vector<int> > G;
vector<int> A;

long long dp[100001], dp2[100001];

void dfs(int i, int parent) {
  dp[i] = 1;
  int j = A[i] == 1 ? 0 : 1;

  for(auto v: G[i]) {
    if(v == parent) continue;
    dfs(v, i);
    if(A[v] == j) dp[i] = (dp[i] + dp[v]) % MOD;
  }
}

void dfs2(int i, int parent) {
  int j = A[i] == 1 ? 0 : 1;

  long long sum = 0;
  for(auto v: G[i]) {
    if(v == parent) continue;
    if(A[v] == j) sum = (sum + dp[v]) % MOD;
  }

  for(auto v: G[i]) {
    if(v == parent) continue;
    if(A[v] != j) continue;

    sum -= dp[v]; sum = (sum + MOD) % MOD;
    dp[i] += (dp[v] * sum) % MOD; dp[i] %= MOD;
  }

  for(auto v: G[i]) {
    if(v == parent) continue;
    dfs2(v, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;

  G.resize(N + 1); A.resize(N + 1);

  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) {
    char c; cin >> c;
    if(c == 'W') {
      A[i] = 1;
    }
    else {
      A[i] = 0;
    }
  }

  dfs(1, -1);
  dfs2(1, -1);

  long long ans = 0;
  for(int i = 1; i <= N; i++) ans = (ans + dp[i]) % MOD;
  cout << ans << endl;
}
