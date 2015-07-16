#include <iostream>

using namespace std;

long long long_pow(int base, int exp) {
  long long result = 1;
  while(exp--) result *= base;
  return result;
}

int main() {
  int N, K; cin >> N >> K;
  long long ans = 0;

  for(int mask = 0; mask < (1 << N); mask++) {
    int set_bits = __builtin_popcount(mask);
    if(!(mask & (1 << (N - 1)))) continue;
    bool correct = true;
    for(int i = 0; i < (N - 1); i++) {
      int curr_bit = (mask & (1 << i) ? 1 : 0);
      int next_bit = (mask & (1 << (i + 1)) ? 1 : 0);
      if(curr_bit == 0 && next_bit == 0) {
        correct = false;
        break;
      }
    }
    if(!correct) continue;
    ans += long_pow(K - 1, set_bits);
  }
  cout << ans << endl;
}
