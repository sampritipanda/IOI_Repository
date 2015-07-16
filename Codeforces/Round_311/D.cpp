// Vitaly and Cycle

#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int> > graph;

int visited[100010];
int black, white;

bool dfs(int i, int color) {
  for(auto v: graph[i]) {
    if(visited[v] == -1) {
      visited[v] = !color;

      if(color == 0) black++;
      else white++;

      if(!dfs(v, !color)) return false;
    }
    else {
      if(visited[v] == color) return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(0);

  int N, M; cin >> N >> M;
  graph.resize(N + 1);

  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  if(M == 0) {
    cout << 3 << " " << (((long long)N) * (N - 1) * (N - 2))/6 << endl;
  }
  else {
    long long ans = 0, min_edges = -1;
    for(int i = 1; i <= N; i++) visited[i] = -1;
    for(int i = 1; i <= N; i++) {
      if(visited[i] != -1) continue;

      black = 0, white = 1;
      visited[i] = 0;
      if(dfs(i, 0)) {
        if(black + white == 2) {
          if(min_edges == -1) min_edges = 2;
          if(min_edges == 2) {
            ans += N - 2;
          }
        }
        else if(black + white > 2) {
          if(min_edges != 1) min_edges = 1, ans = 0;

          ans += (((long long)black) * (black - 1)) / 2;
          ans += (((long long)white) * (white - 1)) / 2;
        }
      }
      else {
        min_edges = -1;
        cout << 0 << " " << 1 << endl;
        break;
      }
    }

    if(min_edges != -1) {
      cout << min_edges << " " << ans << endl;
    }
  }
}
