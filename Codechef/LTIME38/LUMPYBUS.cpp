#include <iostream>
#include <algorithm>

using namespace std;

long long A[100000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; long long P, Q; cin >> N >> P >> Q;
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);

    int ans = 0;
    for(int i = 0; i < N; i++) {
      if(P + 2 * Q < A[i]) break;

      long long T_P = P, T_Q = Q;

      long long cnt = min(A[i]/2, Q);
      Q -= cnt;
      A[i] -= 2 * cnt;

      cnt = min(A[i], P);
      P -= cnt;
      A[i] -= cnt;

      if(A[i] == 0) ans++;
      else {
        P = T_P;
        Q = T_Q;
      }
    }
    cout << ans << endl;
  }
}
