#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long calc(long long X) {
  if(X == 0) return 0;

  long long L = 1, R = 100000;
  while(L < R) {
    long long mid = (L + R + 1)/2;
    if(mid * mid * mid > X) {
      R = mid - 1;
    }
    else {
      L = mid;
    }
  }

  return X/(L * L * L) + calc(X % (L * L * L));
}

int main() {
  long long M; cin >> M;

  long long ans = 0, X = -1;
  for(long long i = M; i >= max(M - 6458247, 0LL); i--) {
    long long curr = calc(i);
    if(curr > ans) {
      ans = curr;
      X = i;
      cout << ans << " " << X << endl;
    }
  }
}
