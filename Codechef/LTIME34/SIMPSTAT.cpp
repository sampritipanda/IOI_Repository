#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    double ans = 0.0;
    for(int i = K; i < N - K; i++) {
      ans += A[i];
    }
    ans /= (N - 2 * K);

    cout << fixed << setprecision(8) << ans << endl;
  }
}
