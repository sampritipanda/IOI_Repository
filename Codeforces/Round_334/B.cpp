#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A;

int main() {
  ios::sync_with_stdio(false);

  int N, K; cin >> N >> K;
  A.resize(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  K = min(K, N);

  int ans = 0;
  for(int i = 0; i < 2*K - N; i++) {
    ans = max(ans, *A.rbegin());
    A.pop_back();
  }

  N = A.size();
  for(int i = 0, j = N - 1; i <= j; i++, j--) {
    if(i == j) ans = max(ans, A[i]);
    else ans = max(ans, A[i] + A[j]);
  }
  cout << ans << endl;
}
