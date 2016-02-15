#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > G;
vector<int> A;

void dfs(int u, int p, int d) {
  bool leaf = true;

  for(auto v: G[u]) {
    if(v == p) continue;
    leaf = false;

    dfs(v, u, d + 1);
  }

  if(leaf) A.push_back(d);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  G.resize(N + 1);

  for(int i = 1; i < N; i++) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  int fin_time = 0;

  for(auto i: G[1]) {
    A.clear();
    dfs(i, 1, 1);

    sort(A.begin(), A.end());

    int ans = 0;
    for(auto j: A) {
      ans = max(1 + ans, j);
    }

    fin_time = max(fin_time, ans);
  }

  cout << fin_time << endl;
}
