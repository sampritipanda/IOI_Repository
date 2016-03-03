#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

long long fact[100001];
vector<vector<int> > G;
vector<bool> visited;
int cnt = 0;

void dfs(int i) {
  if(visited[i]) return;
  visited[i] = true;
  cnt++;

  for(auto u: G[i]) {
    dfs(u);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i <= 100000; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  int N, M; cin >> N >> M;
  G.resize(N + 1);
  visited.resize(N + 1);

  while(M--) {
    int x, y; cin >> x >> y;

    G[x].push_back(y);
    G[y].push_back(x);
  }

  long long ways = 1;

  for(int i = 1; i <= N; i++) {
    if(visited[i]) continue;
    cnt = 0;
    dfs(i);
    ways *= fact[cnt];
    ways %= MOD;
  }

  cout << ways << endl;
}
