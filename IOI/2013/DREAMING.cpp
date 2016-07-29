#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cassert>

using namespace std;

vector<int> G[100000];
map<pair<int, int>, int> edge_map;
vector<int> comp[100000];
bool vis[100000];
bool vis2[100000]; int P[100000];
int center[100000];  // center of ith comp
int length[100000];

void dfs_comp(int i, int timer) {
  if(vis[i]) return;
  vis[i] = true;
  comp[timer].push_back(i);

  for(int u: G[i]) {
    dfs_comp(u, timer);
  }
}

void calc_long_path(int c) {
  if(comp[c].size() == 1) {
    center[c] = comp[c][0];
    length[c] = 0;
    return;
  }

  for(int x: comp[c]) vis2[x] = false;

  int i = -1, len = -1;
  queue<pair<int, int> > Q;
  Q.push({comp[c][0], 0});
  while(!Q.empty()) {
    int u = Q.front().first, d = Q.front().second;
    Q.pop();
    if(d > len) {
      len = d; i = u;
    }
    vis2[u] = true;

    for(int v: G[u]) {
      if(vis2[v]) continue;
      Q.push({v, d + edge_map[{u, v}]});
    }
  }

  for(int x: comp[c]) vis2[x] = false, P[x] = -1;

  int i2 = -1; len = -1;

  Q.push({i, 0});
  while(!Q.empty()) {
    int u = Q.front().first, d = Q.front().second;
    Q.pop();
    if(d > len) {
      len = d; i2 = u;
    }
    vis2[u] = true;

    for(int v: G[u]) {
      if(vis2[v]) continue;
      Q.push({v, d + edge_map[{u, v}]});
      P[v] = u;
    }
  }

  vector<int> path;
  while(i2 != -1) {
    path.push_back(i2);
    i2 = P[i2];
  }
  reverse(path.begin(), path.end());
  vector<int> longest(path.size(), 0);

  int curr = 0;
  for(int i = 1; i < path.size(); i++) {
    curr += edge_map[{path[i - 1], path[i]}];
    longest[i] = max(longest[i], curr);
  }

  curr = 0;
  for(int i = path.size() - 2; i >= 0; i--) {
    curr += edge_map[{path[i], path[i + 1]}];
    longest[i] = max(longest[i], curr);
  }

  int ind = min_element(longest.begin(), longest.end()) - longest.begin();
  center[c] = path[ind];
  length[c] = longest[ind];
}

int main() {
  ios::sync_with_stdio(false);

  int N, M, L; cin >> N >> M >> L;

  for(int i = 0; i < M; i++) {
    int A, B, T; cin >> A >> B >> T;
    G[A].push_back(B);
    edge_map[{A, B}] = T;

    G[B].push_back(A);
    edge_map[{B, A}] = T;
  }

  int timer = 0;
  for(int i = 0; i < N; i++) {
    if(vis[i]) continue;

    dfs_comp(i, timer);
    calc_long_path(timer);
    timer++;
  }
  assert(((N - 1) - M + 1) == timer);

  vector<int> temp;
  for(int i = 0; i < timer; i++) temp.push_back(i);

  sort(temp.begin(), temp.end(), [](int a , int b){
      return length[a] > length[b];
  });

  for(int i = 1; i < timer; i++) {
    int u = center[temp[0]], v = center[temp[i]];

    G[u].push_back(v);
    edge_map[{u, v}] = L;

    G[v].push_back(u);
    edge_map[{v, u}] = L;
  }

  for(int i = 0; i < N; i++) vis[i] = false;

  int i = -1, len = -1;
  queue<pair<int, int> > Q;

  Q.push({0, 0});
  while(!Q.empty()) {
    int u = Q.front().first, d = Q.front().second;
    Q.pop();
    if(d > len) {
      i = u;
      len = d;
    }
    vis[u] = true;

    for(int v: G[u]) {
      if(vis[v]) continue;
      Q.push({v, d + edge_map[{u, v}]});
    }
  }

  len = 0;
  for(int i = 0; i < N; i++) vis[i] = false;

  Q.push({i, 0});
  while(!Q.empty()) {
    int u = Q.front().first, d = Q.front().second;
    Q.pop();
    len = max(len, d);
    vis[u] = true;

    for(int v: G[u]) {
      if(vis[v]) continue;
      Q.push({v, d + edge_map[{u, v}]});
    }
  }

  cout << len << endl;
}

