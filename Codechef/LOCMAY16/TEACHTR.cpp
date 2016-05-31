#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 100000;
const int MAX_LOG = 17;

vector<int> G[MAX + 1];
int lca[MAX + 1][MAX_LOG];
int level[MAX + 1];

int lca_query(int a, int b) {
  if(level[a] > level[b]) swap(a, b);

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[b][j] != -1 && level[lca[b][j]] >= level[a])
      b = lca[b][j];
  }

  if(a == b) return a;

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[a][j] != -1 && lca[b][j] != -1 && lca[a][j] != lca[b][j])
      a = lca[a][j], b = lca[b][j];
  }

  return lca[a][0];
}

void dfs(int i, int d) {
  level[i] = d;

  for(int u: G[i]) {
    dfs(u, d + 1);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  memset(lca, -1, sizeof lca);

  for(int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    lca[b][0] = a;
  }

  dfs(1, 0);

  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 1; i <= N; i++) {
      if(lca[i][j - 1] != -1) {
        lca[i][j] = lca[lca[i][j - 1]][j - 1];
      }
    }
  }

  int Q; cin >> Q;

  while(Q--) {
    int a, b; cin >> a >> b;

    int l = lca_query(a, b);
    if(l == a) cout << a << " taught " << b << endl;
    else if(l == b) cout << b << " taught " << a << endl;
    else cout << "No idea" << endl;
  }
}
