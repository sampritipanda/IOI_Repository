// Solution is wrong because 2-sat finds any assignement and not the assignment with minimum number of swaps

// Same Side => (u | v) & (!u | !v)
// Different => (u | !v) & (!u | v)

#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

const int MAX_M = 100000;

int A[50000];
int B[50000];
vector<int> I_A[MAX_M + 1];
vector<int> I_B[MAX_M + 1];

vector<int> G[100000];
vector<int> G2[100000];
int dfs_num[100000], dfs_low[100000];
bool on_stack[100000];
int scc[100000];
stack<int> S;
int timer = 0;
vector<int> topo;
int R_topo[100000];
bool vis[100000];
bool ans[50000];

void add(int u, int v) {
  // (u | v) === (!u => v) === (!v => u)
  G[u ^ 1].push_back(v);
  G[v ^ 1].push_back(u);
}

void dfs(int u) {
  dfs_num[u] = dfs_low[u] = ++timer;
  S.push(u);
  on_stack[u] = true;

  for(int j = 0; j < G[u].size(); j++) {
    int v = G[u][j];

    if(dfs_num[v] == 0) {
      dfs(v);
    }

    if(on_stack[v]) {
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
  }

  if(dfs_num[u] == dfs_low[u]) {
    while(true) {
      int v = S.top(); S.pop();
      scc[v] = u;
      if(v == u) break;
    }
  }
}

void dfs2(int i) {
  if(vis[i]) return;
  vis[i] = true;

  for(int j = 0; j < G2[i].size(); j++) {
    int u = G2[i][j];
    dfs2(u);
  }

  topo.push_back(i);
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    I_A[A[i]].push_back(i);
  }
  for(int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
    I_B[B[i]].push_back(i);
  }

  for(int i = 1; i <= MAX_M; i++) {
    if(I_A[i].size() == 2) {
      int u = I_A[i][0] * 2, v = I_A[i][1] * 2;
      add(u, v); add(u ^ 1, v ^ 1);
    }
    else if(I_B[i].size() == 2) {
      int u = I_B[i][0] * 2, v = I_B[i][1] * 2;
      add(u, v); add(u ^ 1, v ^ 1);
    }
    else if(I_A[i].size() == 1 && I_B[i].size() == 1) {
      int u = I_A[i][0] * 2, v = I_B[i][0] * 2;
      add(u, v ^ 1); add(u ^ 1, v);
    }
  }

  for(int i = 0; i < 2*N; i++) {
    if(dfs_num[i] == 0)
      dfs(i);
  }

  for(int i = 0; i < 2*N; i++) {
    for(int j = 0; j < G[i].size(); j++) {
      int u = G[i][j];
      G2[scc[i]].push_back(scc[u]);
    }
  }

  for(int i = 0; i < 2*N; i++) {
    if(vis[i]) continue;
    if(scc[i] != i) continue;
    dfs2(i);
  }
  reverse(topo.begin(), topo.end());

  for(int i = 0; i < topo.size(); i++) {
    R_topo[topo[i]] = i;
  }

  int cnt = 0;
  for(int i = 0; i < N; i++) {
    assert(scc[2 * i] != scc[2 * i ^ 1]);

    if(R_topo[scc[2 * i]] < R_topo[scc[2 * i ^ 1]]) {
      ans[i] = false;
    }
    else {
      ans[i] = true;
      cnt++;
    }
  }
  if(cnt > N/2) {
    cnt = N - cnt;
    for(int i = 0; i < N; i++) {
      if(ans[i]) ans[i] = false;
      else ans[i] = true;
    }
  }

  printf("%d\n", cnt);
  for(int i = 0; i < N; i++)
    if(ans[i])
      printf("%d ", i + 1);
  printf("\n");
}
