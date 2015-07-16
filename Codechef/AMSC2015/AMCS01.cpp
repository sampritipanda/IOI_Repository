#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

set<int> graph[100010];
bool visited[100010];
int distance_from_u[100010], distance_from_v[100010];
int children[100010];
int parent[100010];
int degree[100010];
int depth[100010], count_depth[100010];

int bfs(int start) {
  int last_visited = start;
  queue<int> Q;
  Q.push(start);

  while(!Q.empty()) {
    int v = Q.front();
    Q.pop();

    if(visited[v]) continue;
    last_visited = v;
    visited[v] = true;

    for(auto u: graph[v]) {
      Q.push(u);
    }
  }

  return last_visited;
}

void dfs_u(int i, int dist) {
  if(visited[i]) return;
  visited[i] = true;
  distance_from_u[i] = dist;

  for(auto v: graph[i]) {
    dfs_u(v, dist + 1);
  }
}

void dfs_v(int i, int dist) {
  if(visited[i]) return;
  visited[i] = true;
  distance_from_v[i] = dist;

  for(auto v: graph[i]) {
    dfs_u(v, dist + 1);
  }
}

int dfs_parent(int i, int par) {
  parent[i] = par;

  for(auto v: graph[i]) {
    if(v == parent[i]) continue;
    dfs_parent(v, i);
  }
}

void dfs_depth(int i, int dep) {
  depth[i] = dep;
  count_depth[dep]++;

  for(auto v: graph[i]) {
    if(v == parent[i]) continue;

    dfs_depth(v, dep + 1);
  }
}

int main() {
  int N; cin >> N;

  for(int i = 0; i <= N; i++) graph[i].clear();

  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    graph[u].insert(v);
    graph[v].insert(u);
  }

  for(int i = 0; i < N; i++) {
    degree[i] = graph[i].size();
  }

  memset(visited, false, sizeof visited);
  int u = bfs(0);
  memset(visited, false, sizeof visited);
  int v = bfs(u);

  memset(visited, false, sizeof visited);
  dfs_u(u, 0);
  memset(visited, false, sizeof visited);
  dfs_v(v, 0);

  queue<int> center_Q;
  for(int i = 0; i < N; i++) {
    if(degree[i] == 1) center_Q.push(i);
  }
  while(center_Q.size() > 1) {
    int u = center_Q.front();
    center_Q.pop();
    degree[u]--;

    for(auto v: graph[u]) {
      if(degree[v] > 0) {
        degree[v]--;
        if(degree[v] == 1) center_Q.push(v);
      }
    }
  }

  int center = center_Q.front();

  memset(children, 0, sizeof children);
  memset(parent, -1, sizeof parent);
  dfs_parent(center, -1);

  memset(depth, -1, sizeof children);
  memset(count_depth, 0, sizeof parent);

  dfs_depth(center, 0);

  for(int i = 0; i < N; i++) {
    int max_dist = max(distance_from_u[i], distance_from_v[i]);
    int ans = count_depth[max_dist - depth[i]];
    if(depth[i] == max_dist - depth[i]) ans--;
    cout << ans << " ";
  }
  cout << endl;
}
