// Fort Moo

#include <iostream>
#include <algorithm>

using namespace std;

bool A[200][200];
int down[200][200];
int up[200][200];

int main() {
  freopen("fortmoo.in", "r", stdin);
  freopen("fortmoo.out", "w", stdout);

  int N, M; cin >> N >> M;

  int count_free = 0;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      char c; cin >> c;
      if(c == 'X') A[i][j] = false;
      else {
        A[i][j] = true;
        count_free++;
      }
    }
  }

  if(count_free == 0) {
    cout << 0 << endl;
  }
  else {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(!A[i][j]) down[i][j] = -1;
        else {
          for(down[i][j] = i; down[i][j] < N; down[i][j]++) {
            if(!A[down[i][j]][j]) break;
          }
          down[i][j]--;
        }
      }
    }

    int ans = 1;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(!A[i][j]) continue;
        for(int k = i + 1; k < N; k++) {
          if(!A[k][j]) break;
          for(int l = j + 1; l < M; l++) {
            if(!A[i][l] || !A[k][l]) break;
            if(down[i][l] >= k) ans = max(ans, (k - i + 1) * (l - j + 1));
          }
        }
      }
    }
    cout << ans << endl;
  }
}
