#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long A, long long B) {
  if(B == 0) return A;
  return gcd(B, A % B);
}

long long lcm(long long A, long long B) {
  return (A * B)/gcd(A, B);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; long long K; cin >> N >> K;

  long long mod = 1;
  while(N--) {
    long long C; cin >> C;
    mod = gcd(K, lcm(mod, C));
  }
  if(mod == K) cout << "Yes" << endl;
  else cout << "No" << endl;
}
