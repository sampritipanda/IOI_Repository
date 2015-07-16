// Facebook

#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

bool visited[7010];

int main() {
  int N, M, Q; cin >> N >> M >> Q;

  vector<pair<int, int> >* graph = new vector<pair<int, int> >[N];
  pair<int, int>* edges = new pair<int, int>[M];

  for(int i = 0; i < M; i++){
    int x, y, p; cin >> x >> y >> p;
    edges[i] = {x, y};
    graph[x].push_back({y, p});
    graph[y].push_back({x, p});
  }

  while(Q--){
    int m; cin >> m;
    int p;
    pair<int, int> e = edges[m];
    for(auto it = graph[e.first].begin(); it != graph[e.first].end(); it++) {
      if(it->first == e.second){
        p = it->second;
        graph[e.first].erase(it);
        break;
      }
    }
    for(auto it = graph[e.second].begin(); it != graph[e.second].end(); it++) {
      if(it->first == e.second){
        p = it->second;
        graph[e.second].erase(it);
        break;
      }
    }

    queue<pair<int, int> > Q;
    memset(visited, false, sizeof visited);
    int ans = -1;
    Q.push({0, 0});

    while(!Q.empty()){
      auto curr = Q.front();
      Q.pop();
      int i = curr.first, curr_cost = curr.second;

      if(visited[i]) continue;
      if(i == N - 1) {
        ans = curr_cost;
        break;
      }

      visited[i] = true;

      for(auto v: graph[i]){
        Q.push({v.first, curr_cost + v.second});
      }
    }

    cout << ans << endl;
    graph[e.first].push_back({e.second, p});
    graph[e.second].push_back({e.first, p});
  }
}
