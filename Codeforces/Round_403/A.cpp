#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[200001];
int C[200001];

void solve(int i, int p, int p_c) {
  int k = 1;
  for(int u: G[i]) {
    if(u == p) continue;
    if(k == C[i] || k == p_c) k++;
    if(k == C[i] || k == p_c) k++;
    C[u] = k;
    k++;
    solve(u, i, C[i]);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int max_deg = 0, max_vert = 0;
  for(int i = 1; i <= N; i++) {
    if(G[i].size() > max_deg) {
      max_deg = G[i].size();
      max_vert = i;
    }
  }

  C[max_vert] = 1;
  solve(max_vert, -1, -1);

  cout << (max_deg + 1) << endl;
  for(int i = 1; i <= N; i++) cout << C[i] << " ";
  cout << endl;
}
