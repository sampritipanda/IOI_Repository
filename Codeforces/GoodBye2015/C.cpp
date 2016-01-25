#include <iostream>
#include <algorithm>

using namespace std;

int A[500][500];
int row[500][500];
int col[500][500];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      char c; cin >> c;
      if(c == '.') A[i][j] = 1;
      else A[i][j] = 0;
    }
  }

  for(int i = 0; i < N; i++) {
    row[i][0] = 0;
    for(int j = 1; j < M; j++) {
      row[i][j] = row[i][j - 1];
      if(A[i][j] == 1 && A[i][j - 1] == 1) row[i][j]++;
    }
  }

  for(int j = 0; j < M; j++) {
    col[j][0] = 0;
    for(int i = 1; i < N; i++) {
      col[j][i] = col[j][i - 1];
      if(A[i][j] == 1 && A[i - 1][j] == 1) col[j][i]++;
    }
  }

  int Q; cin >> Q;

  while(Q--) {
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;

    int ans = 0;
    for(int i = r1; i <= r2; i++) {
      if(c1 == 0) ans += row[i][c2];
      else {
        ans += row[i][c2];
        ans -= row[i][c1 - 1];
        if(A[i][c1] == 1 && A[i][c1 - 1] == 1) ans--;
      }
    }

    for(int j = c1; j <= c2; j++) {
      if(r1 == 0) ans += col[j][r2];
      else {
        ans += col[j][r2];
        ans -= col[j][r1 - 1];
        if(A[r1][j] == 1 && A[r1 - 1][j] == 1) ans--;
      }
    }

    cout << ans << endl;
  }
}
