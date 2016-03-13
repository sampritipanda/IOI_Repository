// Happy Journey

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[100005];
vector<int> G[100005][26];
int D[100005]; // D[x] = distance from Dest to X
pair<int, int> P[100005];
int min_char[100005]; // minimum char for layer i from source

int X, Y;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  cin >> X >> Y;

  while(M--) {
    int u, v; char c; cin >> u >> c >> v;

    G[u][c - 'a'].push_back(v);
    G[v][c - 'a'].push_back(u);
  }

  int dist = -1;

  queue<pair<int, int> > Q;  // {dist, vertex}
  Q.push({0, Y});

  while(!Q.empty()) {
    auto it = Q.front(); Q.pop();
    int d = it.first, u = it.second;

    if(visited[u]) continue;
    visited[u] = true;

    D[u] = d;

    for(int i = 0; i < 26; i++) {
      for(auto v: G[u][i]) {
        Q.push({d + 1, v});
      }
    }
  }

  for(int i = 0; i <= N; i++) {
    visited[i] = false;
    min_char[i] = -1;
  }

  vector<vector<int> > curr_layer, next_layer;  // {character, dist, vertex}
  curr_layer.push_back({-1, 0, X});

  bool reached = false;
  while(!reached) {
    for(auto it: curr_layer) {
      int c = it[0], d = it[1], u = it[2];

      if(visited[u]) continue;
      visited[u] = true;

      if(u == Y) {
        reached = true;
        break;
      }

      int rem_dist = D[X] - d - 1;

      for(int i = 0; i < 26; i++) {
        if(min_char[d] != -1 && i > min_char[d]) continue;
        for(auto v: G[u][i]) {
          if(D[v] == rem_dist) {
            if(i < min_char[d]) {
              next_layer.clear();
              min_char[d] = i;
            }
            min_char[d] = i;
            next_layer.push_back({i, d + 1, v});
          }
        }
      }
    }

    curr_layer = next_layer;
    sort(curr_layer.begin(), curr_layer.end());
    next_layer.clear();
  }

  for(int i = 0; i < D[X]; i++) cout << char('a' + min_char[i]); cout << endl;
}
