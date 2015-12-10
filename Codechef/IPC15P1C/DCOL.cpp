#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N;
int A[100001];
vector<vector<int> > G;
int U[100001];
int D[100001];

set<int> S[100001];

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
  for(auto v: G[i]) {
    if(v == parent) continue;
    dfs(v, i);
  }

  S[find(i)].insert(A[i]);
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
  int K; cin >> K;

  for(int i = 0; i <= N; i++) U[i] = i;

  G.resize(N + 1);
  for(int i = 2; i <= N; i++) {
    int x; cin >> x;
    G[i].push_back(x);
    G[x].push_back(i);
  }

  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  dfs(1, 0);

  long long ans = 0;
  for(int i = 1; i <= N; i++) ans += D[i];
  cout << ans << endl;
}
