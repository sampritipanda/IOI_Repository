// Good Numbers

#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  long long l, r, p, q; cin >> l >> r >> p >> q;

  long long count = 0;
  int max_power = int(ceil(log(r)/log(p)));
  long long p_power = 1, q_power = 1;
  long long divi = q/gcd(p, q);

  if(p != q) {
    for(int i = 1; i <= max_power; i++) {
      p_power *= p;
      if(i >= 2) q_power *= q;

      long long curr_count = 0;
      curr_count += r/(p_power * q_power) - (l - 1)/(p_power * q_power);
      curr_count -= r/(p_power * q_power * divi) - (l - 1)/(p_power * q_power * divi);

      count += curr_count;
    }
  }

  cout << count << endl;
}
