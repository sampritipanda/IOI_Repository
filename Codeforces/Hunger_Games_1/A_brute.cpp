// Good Numbers

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long l, r, p, q; cin >> l >> r >> p >> q;

  long long count = 0;
  for(long long i = l; i <= r; i++) {
    long long ans1 = 1, ans2 = 1;
    long long p_prod = 1;
    for(; ; ans1++, p_prod *= p) {
      if(i % p_prod != 0) break;
    }
    ans1--;
    long long q_prod = 1;
    for(; ; ans2++, q_prod *= q) {
      if(i % q_prod != 0) break;
    }
    ans2--;

    if(ans1 > ans2) {
      count++;
      cout << i << endl;
    }
  }

  cout << count << endl;
}
