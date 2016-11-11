// Friend Subtask 5 with Bipartite Matching

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <climits>
#include <cstring>

using namespace std;

struct edge {
  int u, v;
  int f;
  int cap;

  edge(int _u, int _v, int _cap, int _f = 0) {
    u = _u;
    v = _v;
    f = _f;
    cap = _cap;
  }
};

int N;
int C[1000];
vector<int> G[1000];
vector<edge> edges;
vector<int> G2[2002];
int col[1000];
int vis[2002];
int s, t;

void dfs(int i, int j) {
  if(col[i] != -1) {
    if(col[i] != j) assert(false);
    return;
  }
  col[i] = j;

  for(int u: G[i]) {
    dfs(u, j ^ 1);
  }
}

void add_edge(int u, int v, int cap) {
  edges.push_back(edge(u, v, cap));
  G2[u].push_back(edges.size() - 1);

  edges.push_back(edge(v, u, cap, cap));
  G2[v].push_back(edges.size() - 1);
}

int pushFlow(int u, int f = INT_MAX/2) {
  vis[u] = true;
  if(u == t) return f;

  for(int e_id: G2[u]) {
    int v = edges[e_id].v;
    int v_f = edges[e_id].f;
    int v_cap = edges[e_id].cap;

    if(vis[v] || v_f == v_cap) continue;

    int f_n = pushFlow(v, min(f, v_cap - v_f));
    if(f_n > 0) {
      edges[e_id].f += f_n;
      edges[e_id ^ 1].f -= f_n;
      return f_n;
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> C[i];
    assert(C[i] == 1);
  }

  for(int i = 1; i < N; i++) {
    int h, p; cin >> h >> p;

    // I am your Friend
    if(p == 0) {
      G[h].push_back(i);
      G[i].push_back(h);
    }
    // My friends are your friends
    else if(p == 1) {
      for(int u: G[h]) {
        G[u].push_back(i);
        G[i].push_back(u);
      }
    }
    // We are your friends
    else {
      assert(false);
    }
  }

  memset(col, -1, sizeof col);

  for(int i = 0; i < N; i++) {
    if(col[i] == -1) {
      dfs(i, 0);
    }
  }

  s = 0, t = 2 * N + 1;
  for(int i = 1; i <= N; i++) {
    add_edge(s, i, 1);
    add_edge(N + i, t, 1);
  }

  for(int i = 0; i < N; i++) {
    if(col[i] != 0) continue;

    for(int u: G[i]) {
      assert(col[u] == 1);
      add_edge(i + 1, N + u + 1, 1);
    }
  }

  int ans = 0;

  while(true) {
    memset(vis, 0, sizeof vis);
    int flow = pushFlow(s);
    if(flow == 0) break;
    ans += flow;
  }

  cout << N - ans << endl;
}
