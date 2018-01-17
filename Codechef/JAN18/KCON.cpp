#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long A[100000];
long long P[100000];
long long S[100000];

int main() {
  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;

    for(int i = 0; i < N; i++) cin >> A[i];

    P[0] = A[0];
    for(int i = 1; i < N; i++) P[i] = P[i - 1] + A[i];

    S[N - 1] = A[N - 1];
    for(int i = N - 2; i >= 0; i--) S[i] = S[i + 1] + A[i];

    long long ans = LLONG_MIN/2;

    long long curr = LLONG_MIN/2;
    for(int i = 0; i < N; i++) {
      curr = max(curr + A[i], A[i]);
      ans = max(ans, curr);
    }

    long long best_P = LLONG_MIN/2;
    for(int i = 0; i < N; i++) best_P = max(best_P, P[i]);
    long long best_S = LLONG_MIN/2;
    for(int i = 0; i < N; i++) best_S = max(best_S, S[i]);


    if(K >= 2) {
      ans = max(ans, best_S + best_P);
    }

    if(K >= 3) {
      if(P[N - 1] > 0) {
        ans = max(ans, best_S + P[N - 1] * (K - 2) + best_P);
      }
    }

    cout << ans << endl;
  }
}
