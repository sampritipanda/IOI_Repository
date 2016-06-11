#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long A, long long B) {
  if(B == 0) return A;
  return gcd(B, A % B);
}

long long __abs(long long X) {
  if(X < 0) return -X;
  return X;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long A, B, C, D; cin >> A >> B >> C >> D;
    long long g = gcd(C, D);
    long long x = __abs(A - B);

    long long ans = x;
    ans = min(ans, x % g);
    ans = min(ans, g - (x % g));
    cout << ans << endl;
  }
}
