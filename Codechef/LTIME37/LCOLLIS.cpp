#include <iostream>
#include <algorithm>

using namespace std;

char A[10][10];

int main() {
  int T; cin >> T;

  while(T--) {
    int N, M; cin >> N >> M;

    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
        cin >> A[i][j];

    int ans = 0;

    for(int i = 0; i < N; i++) {
      for(int j = i + 1; j < N; j++) {
        for(int k = 0; k < M; k++) {
          if(A[i][k] == '1' && A[j][k] == '1') ans++;
        }
      }
    }

    cout << ans << endl;
  }
}
