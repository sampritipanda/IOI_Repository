#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<int> G[100001];
long long dp[100001];
long long fact[100001];

void dfs(int i, int p) {
  long long ans = 1;

  int cnt = 0;
  for(int u: G[i]) {
    if(u == p) continue;

    cnt++;
    dfs(u, i);
    ans = (ans * dp[u]) % MOD;
  }

  ans = (ans * fact[cnt]) % MOD;
  dp[i] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i <= 100000; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    for(int i = 0; i <= N; i++) {
      G[i].clear();
      dp[i] = 0;
    }

    for(int i = 0; i < N - 1; i++) {
      int u, v; cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    int A; cin >> A;
    dfs(A, -1);

    cout << dp[A] << endl;
  }
}
