// Special Economic Zone

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M; cin >> N >> M;

  vector<vector<int> > graph(N);
  pair<int, int> edges[M];

  for(int i = 0; i < M; i++){
    int u, v; cin >> u >> v;
    u--; v--;
    edges[i] = {u, v};
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int max_ans = 0;
  for(int mask = 0; mask < (1 << N); mask++){
    bool possible = true;
    for(int i = 0; i < M; i++){
      int u = edges[i].first, v = edges[i].second;
      if((mask & (1 << u)) && (mask & (1 << v))){
        possible = false;
        break;
      }
    }
    if(!possible) continue;

    int x = __builtin_popcount(mask), y = 0;
    for(int i = 0; i < N; i++){
      if(mask & (1 << i)) continue;

      for(auto v: graph[i]){
        if(mask & (1 << v)) {
          y++;
          break;
        }
      }
    }
    max_ans = max(max_ans, x - y);
  }

  cout << max_ans << endl;
}
