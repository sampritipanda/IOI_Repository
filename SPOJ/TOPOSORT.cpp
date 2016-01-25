#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > G;
vector<int> indegree;
vector<bool> vis, vis2;
bool dag = true;

void dfs(int i) {
  if(vis2[i]) {
    dag = false;
    return;
  }

  if(vis[i]) {
    return;
  }
  vis[i] = true;

  vis2[i] = true;

  for(auto v: G[i]) {
    dfs(v);
  }

  vis2[i] = false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  G.resize(N + 1);
  indegree.resize(N + 1, 0);
  vis.resize(N + 1, false);
  vis2.resize(N + 1, false);

  while(M--) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    indegree[y]++;
  }

  for(int i = 1; i <= N; i++) {
    if(!vis[i]) dfs(i);
  }

  if(dag) {
    priority_queue<int, vector<int>, greater<int> > Q;
    for(int i = 1; i <= N; i++)
      if(indegree[i] == 0)
        Q.push(i);

    vector<int> toposort;

    while(!Q.empty()) {
      int u = Q.top(); Q.pop();
      toposort.push_back(u);

      for(auto v: G[u]) {
        indegree[v]--;
        if(indegree[v] == 0) Q.push(v);
      }
    }

    for(auto it: toposort) cout << it << " "; cout << endl;
  }
  else {
    cout << "Sandro fails." << endl;
  }
}
