#include <iostream>
#include <algorithm>

using namespace std;

int A[101];

int main() {
  int N, M, K; cin >> N >> M >> K;
  for(int i = 1; i <= N; i++) cin >> A[i];

  int ans = 100000;
  for(int i = 1; i <= N; i++) {
    if(A[i] > 0 && A[i] <= K) ans = min(ans, abs(i - M) * 10);
  }
  cout << ans << endl;
}
