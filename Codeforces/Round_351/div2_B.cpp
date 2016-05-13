#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> G[100001];
int vis[100001];
bool bip;

void dfs(int i, int p, int c) {
  if(vis[i]) {
    if(vis[i] != c) bip = false;
    return;
  }
  vis[i] = c;
  for(int u: G[i]) {
    if(u == p) continue;
    int n_c = (c == 1 ? 2 : 1);
    dfs(u, i, n_c);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  while(M--) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  bip = true;
  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;
    if(G[i].size() == 0) continue;
    dfs(i, -1, 1);
  }

  if(!bip) cout << 0 << endl;
  else {
    set<int> A, B;
    for(int i = 1; i <= N; i++) {
      if(vis[i] == 1) A.insert(i);
      else if(vis[i] == 2) B.insert(i);
    }

    if(A.size() == 0) {
      cout << N - 1 << endl;
      return 0;
    }

    if(*A.rbegin() > *B.begin() && *B.rbegin() > *A.begin()) {
      cout << 0 << endl;
      return 0;
    }

    if(*A.begin() > *B.rbegin()) swap(A, B);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= N; i++) {
      if(vis[i]) continue;
      cnt2++;
      if(i > *B.begin()) cnt1++;
      if(i < *A.rbegin()) cnt1++;
    }

    cout << cnt2 - cnt1 + 1 << endl;
  }
}
