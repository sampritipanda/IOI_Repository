#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_LOG 14

vector<vector<pair<int, int> > > G;
int parent[10000];
int dist[10000];
int lca[10000][MAX_LOG];
int level[10000];

void reset() {
  G.clear();
  for(int i = 0; i < 10000; i++) {
    parent[i] = -1;
    dist[i] = 0;
    level[i] = -1;
    for(int j = 0; j < MAX_LOG; j++) {
      lca[i][j] = -1;
    }
  }
}

void dfs(int i, int d, int l) {
  level[i] = l;
  dist[i] = d;

  for(auto it: G[i]) {
    int u = it.first, cost = it.second;
    if(u == parent[i]) continue;

    parent[u] = i;
    dfs(u, d + cost, l + 1);
  }
}

int lca_query(int a, int b) {
  if(level[a] > level[b]) swap(a, b);

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[b][j] != -1 && level[lca[b][j]] >= level[a])
      b = lca[b][j];
  }

  if(a == b) return a;

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[a][j] != -1 && lca[b][j] != -1 && lca[a][j] != lca[b][j]) {
      a = lca[a][j], b = lca[b][j];
    }
  }

  return lca[a][0];
}

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    reset();

    int N; scanf("%d", &N);
    G.resize(N);

    for(int i = 0; i < N - 1; i++) {
      int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
      G[a].push_back({b, c});
      G[b].push_back({a, c});
    }

    dfs(0, 0, 0);

    for(int i = 0; i < 10000; i++) lca[i][0] = parent[i];
    for(int j = 1; j < MAX_LOG; j++) {
      for(int i = 0; i < 10000; i++) {
        if(lca[i][j - 1] != -1) {
          lca[i][j] = lca[lca[i][j - 1]][j - 1];
        }
      }
    }

    while(true) {
      char type[100]; scanf(" %s", type);

      if(type[0] == 'D' && type[1] == 'I') {
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        int l = lca_query(a, b);
        printf("%d\n", dist[a] + dist[b] - 2 * dist[l]);
      }
      else if(type[0] == 'K') {
        int a, b, k; scanf("%d %d %d", &a, &b, &k); a--; b--;
        int l = lca_query(a, b);

        int half_dist = level[a] - level[l] + 1;
        if(k <= half_dist) {
          k--;
          int res = a;
          for(int i = MAX_LOG - 1; i >= 0; i--) {
            if(k & (1 << i))
              res = lca[res][i];
          }
          printf("%d\n", res + 1);
        }
        else {
          int full_dist = (level[a] - level[l] + 1) + (level[b] - level[l]);
          k = full_dist - k;
          int res = b;
          for(int i = MAX_LOG - 1; i >= 0; i--) {
            if(k & (1 << i))
              res = lca[res][i];
          }
          printf("%d\n", res + 1);
        }
      }
      else break;
    }

    printf("\n");
  }
}

