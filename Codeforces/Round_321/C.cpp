#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int> > graph;
// vector<bool> visited;
vector<bool> A;

int solve(int i, int c, int parent) {
  if(c > M) return 0;
  if(graph[i].size() == 1 && graph[i][0] == parent) return 1;

  int ans = 0;
  for(auto v: graph[i]) {
    if(v == parent) continue;

    ans += solve(v, A[v] ? c + 1 : 0, i);
  }

  return ans;
}

int main() {
  cin >> N >> M;

  A.resize(N + 1);
  // visited.resize(N + 1, false);
  graph.resize(N + 1);

  for(int i = 1; i <= N; i++) {
    int a; cin >> a;
    A[i] = (a == 1);
  }

  for(int i = 0; i < (N - 1); i++) {
    int x, y; cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  cout << solve(1, (A[1] ? 1 : 0), -1) << endl;
}
