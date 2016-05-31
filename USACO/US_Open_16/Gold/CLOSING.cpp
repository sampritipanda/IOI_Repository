#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> G[200001];
int U[200001];
int A[200001];
bool ans[200001];
map<int, int> added;

int find(int i) {
  if(i == U[i]) return i;
  else return U[i] = find(U[i]);
}

void merge(int a, int b) {
  a = find(a); b = find(b);

  if(a != b) {
    U[a] = b;
  }
}

int main() {
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);

  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 1; i <= N; i++) U[i] = i;

  while(M--) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) cin >> A[i];

  set<int> disconnect;
  int check = A[N];
  for(int i = N; i >= 1; i--) {
    int u = A[i];
    added[u] = true;
    for(int v: G[u]) {
      if(added[v]) merge(u, v);
    }
    if(find(u) != find(check)) disconnect.insert(u);

    while(disconnect.size() > 0) {
      u = *disconnect.begin();
      if(find(u) != find(check)) break;
      disconnect.erase(u);
    }

    if(disconnect.size() == 0) ans[i] = true;
    else ans[i] = false;
  }

  for(int i = 1; i <= N; i++) {
    if(ans[i]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
