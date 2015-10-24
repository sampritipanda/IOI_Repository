#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int A[1000000];

int main() {
  int T; cin >> T;

  while(T--) {
    int N; long long K; cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A, A + N);

    long long ans = 0;
    for(int i = 1; i < N; i++) {
      ans += K * (A[i] - A[i - 1]) + 42;
      ans %= MOD;
    }

    cout << ans << endl;
  }
}
