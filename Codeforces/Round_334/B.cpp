#include <iostream>
#include <algorithm>

using namespace std;

int A[100001];

int main() {
  ios::sync_with_stdio(false);

  int N, K; cin >> N >> K;
  for(int i = 1; i <= N; i++) cin >> A[i];
  K = min(K, N);

  int ans = 0, i = 1;
  while(true) {
    if(K == 0) break;
    if(N - i + 1 == K) break;
    ans = max(ans, A[i] + A[i + 1]);
    i += 1;
  }

  for(; i <= N; i++) ans = max(ans, A[i]);

  cout << ans << endl;
}
