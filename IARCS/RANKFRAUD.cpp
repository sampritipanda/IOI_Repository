// Rank Fraud

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > G;
bool found = false;
int N;

void bfs(int i) {
  queue<pair<int, pair<vector<int>, vector<bool> > > > Q;
  vector<bool> t(N + 1, false); vector<int> t2;
  Q.push(make_pair(i, make_pair(t2, t)));

  while(!Q.empty()) {
    pair<int, pair<vector<int>, vector<bool> > > it = Q.front(); Q.pop();
    int u = it.first; vector<int> path = it.second.first; vector<bool> visited = it.second.second;
    visited[u] = true;
    path.push_back(u);

    bool done = true;
    for(int i = 1; i <= N; i++) {
      if(!visited[i]) {
        done = false; break;
      }
    }

    if(done) {
      found = true;
      printf("YES\n");
      for(int i = 0; i < N; i++) printf("%d%c", path[i], i == N - 1 ? '\n' : ' ');
      return;
    }

    for(int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if(visited[v]) continue;
      Q.push(make_pair(v, make_pair(path, visited)));
    }
  }
}

int main() {
  scanf("%d", &N);
  G.resize(N + 1);

  for(int i = 1; i <= N; i++) {
    int M; scanf("%d", &M);
    while(M--) {
      int P; scanf("%d", &P);
      G[i].push_back(P);
    }
  }

  for(int i = 1; i <= N; i++) {
    bfs(i);
    if(found) break;
  }

  if(!found) printf("NO\n");
}
