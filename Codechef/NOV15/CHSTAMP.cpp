#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

map<pair<int, int>, int> node_map;
vector<vector<int> > days;
map<int, vector<int> > deals;
vector<pair<pair<int, int>, int> > relations;
vector<vector<int> > G;
vector<int> visited;
vector<int> component;
unordered_map<int, int> ans;
vector<pair<int, int> > nodes;
vector<long long> stamps;

void reset() {
  node_map.clear();
  days.clear();
  relations.clear();
  G.clear();
  visited.clear();
  component.clear();
  ans.clear();
  nodes.clear();
  stamps.clear();
  deals.clear();
}

void dfs(int i, int id) {
  if(visited[i]) return;
  visited[i] = true;

  component[i] = id;
  ans[id] = max(ans[id], nodes[i].first);
  for(auto v: G[i]) {
    dfs(v, id);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;

  while(T--) {
    reset();

    int X, M; cin >> X >> M;
    int N = 50000;

    stamps.resize(N + 1);
    days.resize(N + 1);

    for(int i = 1; i <= X; i++) {
      int a; cin >> a;
      stamps[a]++;
    }

    for(int i = 0; i < M; i++) {
      int A, B, T; cin >> T >> A >> B;
      node_map[{A, T}] = 0;
      node_map[{B, T}] = 0;
      days[A].push_back(T); days[B].push_back(T);
      deals[T].push_back(A); deals[T].push_back(B);
      relations.push_back({{A, B}, T});
    }

    for(int i = 1; i <= N; i++){
      sort(days[i].begin(), days[i].end()); unique(days[i].begin(), days[i].end());
      sort(deals[i].begin(), deals[i].end()); unique(deals[i].begin(), deals[i].end());
    }

    int count = 0;
    for(auto it: node_map) {
      node_map[it.first] = count++;
      nodes.push_back(it.first);
    }

    G.resize(count); visited.resize(count); component.resize(count);
    for(auto it: relations) {
      int A = it.first.first, B = it.first.second, T = it.second;
      int i = node_map[{A, T}], j = node_map[{B, T}];
      G[i].push_back(j); G[j].push_back(i);
    }

    for(int i = 1; i <= N; i++) {
      for(int j = 0; j < int(days[i].size()) - 1; j++) {
        int A = days[i][j], T = i, B = days[i][j + 1];
        int a = node_map[{A, T}], b = node_map[{B, T}];
        G[a].push_back(b);
      }
    }

    int id = 0;
    for(auto day: deals) {
      for(auto type: day.second) {
        int i = node_map[{type, day.first}];
        if(visited[i]) continue;

        ans[id] = 0;
        dfs(i, id);
        id++;
      }
    }

    long long best = 0;
    for(int i = 1; i <= N; i++) {
      if(days[i].empty() || node_map.count({i, days[i][0]}) == 0) continue;
      else {
        best += stamps[i] * ans[component[node_map[{i, days[i][0]}]]];
      }
    }
    cout << best << endl;
  }
}
