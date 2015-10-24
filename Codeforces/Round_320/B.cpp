#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long A[200000];

int main() {
  ios::sync_with_stdio(false);

  int N, K, X; cin >> N >> K >> X;
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int b = 33; b >= 0; b--) {
    bool set = false;
    for(int i = 0; i < N; i++) {
      if(A[i] & (1LL << b)) {
        set = true; break;
      }
    }
    if(set) continue;

    long long cur_pow = 1;
    for(int k = 1; k <= K; k++) {
      bool change = false;
      cur_pow *= X;
      for(int i = 0; i < N; i++) {
        if((A[i] * cur_pow) & (1LL << b)) {
          A[i] *= cur_pow;
          K -= k; change = true;
          break;
        }
      }
      if(change) break;
    }
  }

  long long ans = 0;
  for(int i = 0; i < N; i++) ans |= A[i];

  cout << ans << endl;
}
