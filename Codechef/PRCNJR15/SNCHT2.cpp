// Painting Logs

#include <iostream>
#include <algorithm>

using namespace std;

long long A[100010];
long long prefix[100010];

long long prefix_sum(int L, int R) {
  if(L > R) return 0;
  return prefix[R] - prefix[L - 1];
}

int main() {
  for(int i = 0; i <= 100000; i++) {
    prefix[i] = 0;
  }

  int N, Q; cin >> N >> Q;

  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) {
    prefix[i] = prefix[i - 1] + A[i];
  }

  while(Q--) {
    int L, R; cin >> L >> R;

    long long ans = 0;
    ans += prefix_sum(1, L - 1);
    ans += prefix_sum(R + 1, N);
    cout << ans << endl;
  }
}
