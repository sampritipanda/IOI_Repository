#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int> > G;
int visited[101];

void dfs(int i, int j) {
  if(visited[i]) return;

  visited[i] = j;

  int nex = (j == 1 ? 2 : 1);

  for(auto v: G[i]) {
    dfs(v, nex);
  }
}

int main() {
  int N; cin >> N;
  G.resize(N + 1);

  for(int i = 1; i <= N; i++) {
    while(true) {
      int x; cin >> x;
      if(!x) break;

      G[i].push_back(x);
    }
  }

  for(int i = 1; i <= N; i++) {
    if(!visited[i]) dfs(i, 1);
  }

  vector<int> A;
  for(int i = 1; i <= N; i++) {
    if(visited[i] == 1) A.push_back(i);
  }
  cout << A.size() << endl;
  for(auto it: A) cout << it << " "; cout << endl;
}
