#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[50001];
int B[50001];
int C[100003];
int Z[100003];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 0; i < K; i++) cin >> B[i];

    int i = 0;
    for(int j = 0; j < K; j++, i++) {
      C[i] = B[j];
    }
    C[i++] = -101010;
    for(int j = 1; j <= N; j++, i++) {
      C[i] = A[j] - A[j - 1];
    }

    int tot = i;

    int L = 0, R = 0;
    for(int i = 1; i < tot; i++) {
      if(i > R) {
        L = R = i;
        while(R < tot && C[R] == C[R-L]) R++;
        Z[i] = R-L; R--;
      }
      else {
        int x = i - L;
        if(Z[x] < R-i+1) {
          Z[i] = Z[x];
        }
        else {
          L = i;
          while(R < tot && C[R] == C[R-L]) R++;
          Z[i] = R-L; R--;
        }
      }
    }

    int ans = 0;
    for(int i = K + 1; i < tot; i++) {
      if(Z[i] >= K) ans++;
    }
    cout << ans << endl;
  }
}
