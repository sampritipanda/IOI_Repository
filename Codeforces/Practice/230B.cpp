// T-primes

#include <iostream>
#include <cmath>

using namespace std;

inline bool is_prime(int a) {
  if(a == 1) return false;

  for(int i = 2; i*i <= a; i++) {
    if(a % i == 0) return false;
  }
  return true;
}

int main() {
  int N; cin >> N;

  while(N--) {
    long long a; cin >> a;
    double prime_d = sqrt(a);
    bool possible = false;
    if((prime_d - int(prime_d)) <= 0.000001) {
      if(is_prime(prime_d)) {
        possible = true;
      }
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
