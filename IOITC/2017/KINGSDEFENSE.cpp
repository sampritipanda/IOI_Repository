#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[100001];
vector<pair<int, pair<int, int> > > edges;
int deg[100001];
int U[100001];

int find(int u) {
  if(u == U[u]) return u;
  return U[u] = find(U[u]);
}

void merge(int a, int b) {
  a = U[a], b = U[b];
  if(a != b) {
    U[b] = a;
  }
}

int main() {
  int N, M, K; cin >> N >> M >> K;

  while(K--) {
    int x; cin >> x;
    A[x] = 1;
  }

  while(M--) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({w, {u, v}});
    deg[u]++; deg[v]++;
  }

  sort(edges.begin(), edges.end());

  for(int i = 1; i <= N; i++) U[i] = i;

  long long ans = 0;
  for(auto it: edges) {
    int w = it.first, u = it.second.first, v = it.second.second;
    if(find(u) == find(v)) continue;
    if(A[u] == 1 && A[v] == 1 && deg[u] > 1 && deg[v] > 1) continue;
    if(A[u] == -1 || A[v] == -1) continue;

    ans += w;
    merge(u, v);
    if(A[u] == 1) A[u] = -1;
    if(A[v] == 1) A[v] = -1;
  }
  cout << ans << endl;
}
