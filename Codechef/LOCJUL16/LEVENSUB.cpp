#include <iostream>
#include <algorithm>

using namespace std;

long long A[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++) A[i] += A[i - 1];

    int j_0 = N + 1;
    int ans = 0;
    for(int i = N; i >= 1; i--) {
      if(A[i] % 2 == 0) {
        j_0 = i;
        break;
      }
    }
    int i_1 = -1, j_1 = N + 1;
    for(int i = 0; i < N; i++) {
      if(A[i] % 2 == 1) {
        i_1 = i;
        break;
      }
    }
    for(int i = N; i >= 1; i--) {
      if(A[i] % 2 == 1) {
        j_1 = i;
        break;
      }
    }
    if(j_0 != N + 1) ans = max(ans, j_0);
    if(i_1 != -1 && j_1 != N + 1) ans = max(ans, j_1 - i_1);

    cout << ans << endl;
  }
}
