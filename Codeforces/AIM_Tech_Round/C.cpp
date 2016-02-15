#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool G[501][501];
bool G2[501][501];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  vector<int> A(N + 1, -1);

  while(M--) {
    int u, v; cin >> u >> v;
    G[u][v] = 1;
    G[v][u] = 1;
  }

  for(int i = 1; i <= N; i++) {
    if(A[i] != -1) continue;

    A[i] = 1;

    for(int j = 1; j <= N; j++) {
      if(j == i || G[i][j]) continue;

      A[j] = 3;

      for(int k = 1; k <= N; k++) {
        if(i == k || j == k) continue;

        if(G[i][k] && G[j][k]) A[k] = 2;
      }
    }
  }

  bool pos = true;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(i == j) continue;

      if(A[i] == A[j] || abs(A[i] - A[j]) == 1) {
        G2[i][j] = 1;
      }

      if(G[i][j] != G2[i][j]) pos = false;
    }
  }

  if(pos) {
    cout << "Yes" << endl;
    for(int i = 1; i <= N; i++) cout << char('a' + A[i] - 1); cout << endl;
  }
  else {
    cout << "No" << endl;
  }
}
