#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

int U[201];
int sz[201];
set<pair<int, pair<int, int> > > edges;

int find(int i) {
  if(i == U[i]) return i;
  return U[i] = find(U[i]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);

  sz[a] += b;
  U[b] = a;
}

int main() {
  int N, W; scanf("%d %d", &N, &W);

  while(W--) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    edges.insert({w, {u, v}});

    for(int i = 1; i <= N; i++) {
      U[i] = i;
      sz[i] = 1;
    }

    int ans = 0;
    for(auto it: edges) {
      int w = it.first, u = it.second.first, v = it.second.second;
      if(find(u) == find(v)) continue;
      ans += w;
      merge(u, v);
    }

    for(int i = 2; i <= N; i++) {
      if(find(1) != find(i)) {
        ans = -1;
        break;
      }
    }

    printf("%d\n", ans);
    fflush(stdout);
  }
}
