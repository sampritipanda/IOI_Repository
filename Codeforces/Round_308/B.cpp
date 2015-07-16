// Vanya and Books

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long mypow(int base, int exp) {
  long long result = 1;
  while(exp > 0) {
    if(exp & 1) result *= base;
    base = base * base;
    exp >>= 1;
  }
  return result;
}

int main() {
  long long N; cin >> N;
  int d = floor(log10(N)) + 1;
  long long ans = (N + 1) * d - (mypow(10, d) - 1)/9;
  cout << ans << endl;
}
