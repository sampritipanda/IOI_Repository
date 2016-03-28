#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[101];
int indeg[101];
bool visited[101];

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    while(true) {
      int x; cin >> x;
      if(x == 0) break;
      indeg[x]++;
      G[i].push_back(x);
    }
  }

  queue<int> Q;
  for(int i = 1; i <= N; i++) {
    if(indeg[i] == 0) Q.push(i);
  }
  vector<int> ans;

  while(!Q.empty()) {
    int u = Q.front(); Q.pop();

    if(visited[u]) continue;
    visited[u] = true;
    ans.push_back(u);

    for(auto v: G[u]) {
      indeg[v]--;
      if(indeg[v] == 0) Q.push(v);
    }
  }

  for(auto it: ans) cout << it << " "; cout << endl;
}
