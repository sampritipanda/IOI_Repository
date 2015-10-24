// Googol String

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

char solve(long long N, long long K) {
  if(N == 1) {
    assert(K == 1);
    return '0';
  }

  if(N <= 60) {
    long long size = (1LL << N) - 1;
    if(K == (size + 1)/2) return '0';
    else if(K < (size + 1)/2) return solve(N - 1, K);
    else {
      char ans = solve(N - 1, size/2 - (K - (size + 1)/2) + 1);
      return (ans == '0' ? '1' : '0');
    }
  }
  else {
    return solve(N - 1, K);
  }
}

int main() {
  int T; cin >> T;

  for(int i = 1; i <= T; i++) {
    long long K; cin >> K;

    cout << "Case #" << i << ": " << solve(100, K) << endl;
  }
}
