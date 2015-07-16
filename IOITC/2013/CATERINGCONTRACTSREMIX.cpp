// Catering Contracts Remix

#include <iostream>
#include <set>
#include <map>
#include <climits>

using namespace std;

set<int> graph[100005];
map<pair<int, int>, int> weights;
int stations[100005];
int parent[100005];
bool visited[100005];
bool leaf[100005];
long long dp[100005][105];
int N, M;

long long solve(int i, int previous){
  if(dp[i][previous] != -1) return dp[i][previous];

  long long ans = LLONG_MAX;
  if(stations[i] == -1) {
    for(int j = 0; j <= M; j++){
      long long curr = 0;
      for(auto v: graph[i]){
        curr += solve(v, j);
      }
      if(j != previous) curr += weights[{parent[i], i}];
      ans = min(ans, curr);
    }
  }
  else {
    long long curr = 0;
    for(auto v: graph[i]){
      curr += solve(v, stations[i]);
    }
    if(stations[i] != previous) curr += weights[{parent[i], i}];
    ans = min(ans, curr);
  }

  dp[i][previous] = ans;
  return ans;
}

void dfs(int curr){
  if(visited[curr]) return;

  visited[curr] = true;
  int count = 0;
  for(auto v: graph[curr]){
    if(!visited[v]){
      parent[v] = curr;
      count++;
      dfs(v);
    }
  }

  if(count == 0) leaf[curr] = true;
}

int main() {
  for(int i = 0; i < 100005; i++) {
    visited[i] = false;
    leaf[i] = false;
    for(int j = 0; j < 105; j++){
      dp[i][j] = -1;
    }
  }

  cin >> N;
  for(int i = 0; i < (N - 1); i++){
    int u, v, w; cin >> u >> v >> w;
    graph[u].insert(v);
    graph[v].insert(u);
    weights[{u, v}] = w;
    weights[{v, u}] = w;
  }

  weights[{0, 1}] = 0;
  weights[{1, 0}] = 0;

  M = -1;
  for(int i = 1; i <= N; i++){
    cin >> stations[i];
    M = max(M, stations[i]);
  }

  parent[1] = 0;
  dfs(1);

  for(int i = 1; i <= N; i++){
    graph[i].erase(parent[i]);
  }

  cout << solve(1, -1) << endl;
}
