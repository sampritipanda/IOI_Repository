#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

const int MAX = 100000;
const int MAX_LOG = 17;
vector<int> G[MAX + 1];
vector<int> C[MAX + 1];   // Centroid Tree
int P_C[MAX + 1];
int label[MAX + 1];
int sz[MAX + 1];
int currComp;

int D[MAX + 1];
int lca[MAX + 1][MAX_LOG];

int ans[MAX + 1]; // max dist to red node in subtree

void centroid_dfs(int i, int p) {
  sz[i] = 1;
  currComp++;

  for(int v: G[i]) {
    if(v == p || label[v]) continue;
    centroid_dfs(v, i);
    sz[i] += sz[v];
  }
}

int find(int i, int p) {
  for(int v: G[i]) {
    if(v == p || label[v]) continue;
    if(sz[v] >= currComp/2) return find(v, i);
  }
  return i;
}

int decompose(int i, int p, int j) {
  currComp = 0;
  centroid_dfs(i, p);

  int root = find(i, p);
  label[root] = j;

  for(int v: G[root]) {
    if(v == p || label[v]) continue;
    int nextRoot = decompose(v, root, j + 1);
    C[root].push_back(nextRoot);
    P_C[nextRoot] = root;
  }

  return root;
}

void dfs(int i, int p, int d) {
  D[i] = d;
  lca[i][0] = p;

  for(int v: G[i]) {
    if(v == p) continue;
    dfs(v, i, d + 1);
  }
}

int lca_query(int a, int b) {
  if(D[a] > D[b]) swap(a, b);

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(D[b] - (1 << j) >= D[a]) {
      b = lca[b][j];
    }
  }

  if(a == b) return a;

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[a][j] && lca[b][j] && lca[a][j] != lca[b][j]) {
      a = lca[a][j];
      b = lca[b][j];
    }
  }

  assert(lca[a][0] == lca[b][0]);
  return lca[a][0];
}

int dist(int a, int b) {
  int l = lca_query(a, b);
  return D[a] + D[b] - 2*D[l];
}

void color_node(int x) {
  int c = x;
  while(c != 0) {
    ans[c] = min(ans[c], dist(c, x));
    c = P_C[c];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  decompose(1, 0, 1);

  dfs(1, 0, 0);

  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 1; i <= N; i++) {
      if(lca[i][j - 1])
        lca[i][j] = lca[lca[i][j - 1]][j - 1];
    }
  }

  for(int i = 0; i <= N; i++) ans[i] = INT_MAX/2;

  color_node(1);

  while(M--) {
    int t, v; cin >> t >> v;;

    if(t == 1) {
      color_node(v);
    }
    else {
      int curr_ans = INT_MAX/2;
      int c = v;
      while(c != 0) {
        curr_ans = min(curr_ans, ans[c] + dist(c, v));
        c = P_C[c];
      }
      cout << curr_ans << endl;
    }
  }
}
