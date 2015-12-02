#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N;
int C[300001];
int A[300001];
vector<vector<int> > G;
int U[300001];
int D[300001];

long long R = 101LL;
long long H1[300001], H2[300001];
long long M1 = 1099511627791LL, M2 = 999998727899999LL;

set<pair<long long, long long> > S[300001];

int find(int i) {
  if(i == U[i]) return i;
  else return U[i] = find(U[i]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if(a == b) return;

  if(S[a].size() < S[b].size()) swap(a, b);
  for(auto it: S[b]) S[a].insert(it);
  S[b].clear();
  U[b] = a;
}

void dfs(int i, int parent) {
  H1[i] = (H1[parent] * R + A[i]) % M1;
  H2[i] = (H2[parent] * R + A[i]) % M2;

  for(auto v: G[i]) {
    if(v == parent) continue;

    dfs(v, i);
  }
}

void dfs2(int i, int parent) {
  for(auto v: G[i]) {
    if(v == parent) continue;
    dfs2(v, i);
  }

  S[find(i)].insert({H1[i], H2[i]});
  for(auto v: G[i]) {
    if(v == parent) continue;
    merge(i, v);
  }

  D[i] = S[find(i)].size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for(int i = 0; i <= N; i++) U[i] = i;

  for(int i = 1; i <= N; i++) cin >> C[i];

  for(int i = 1; i <= N; i++) {
    char c; cin >> c;
    A[i] = c - 'a' + 1;
  }

  G.resize(N + 1);
  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  H1[0] = 0; H2[0] = 0;
  dfs(1, 0);
  dfs2(1, 0);

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    ans = max(ans, D[i] + C[i]);
  }
  int cnt = 0;
  for(int i = 1; i <= N; i++) {
    if(D[i] + C[i] == ans) cnt++;
  }

  cout << ans << endl;
  cout << cnt << endl;
}
