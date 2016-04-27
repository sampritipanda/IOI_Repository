#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

pair<int, int> A[101][101];
int ans[101][101];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, Q; cin >> N >> M >> Q;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      A[i][j] = {i, j};
    }
  }

  while(Q--) {
    int t; cin >> t;

    if(t == 1) {
      int r; cin >> r;
      auto first_el = A[r][1];
      for(int j = 1; j < M; j++) A[r][j] = A[r][j + 1];
      A[r][M] = first_el;
    }
    else if(t == 2) {
      int c; cin >> c;
      auto first_el = A[1][c];
      for(int i = 1; i < N; i++) A[i][c] = A[i + 1][c];
      A[N][c] = first_el;
    }
    else {
      int r, c, x; cin >> r >> c >> x;
      int i = A[r][c].first, j = A[r][c].second;

      ans[i][j] = x;
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
