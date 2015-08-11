// Primes or Palindromes?

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

#define MAX_N 10000000

bool sieve[MAX_N + 1];

void precalc() {
  for (int i = 2; i <= MAX_N; i++) {
    if (sieve[i]) {
      for(int j = i + i; j <= MAX_N; j += i) {
        sieve[j] = false;
      }
    }
  }
}

int main() {
  sieve[1] = false;
  for(int i = 2; i <= MAX_N; i++) sieve[i] = true;
  precalc();

  double p, q; cin >> p >> q;
  double A = p/q;

  int pal_count = 0, prime_count = 0;
  string dig, dig2;
  int ans;
  for(int i = 1; i <= MAX_N; i++) {
    int n = i;
    int rev = 0;
    while (n > 0)
    {
      int dig = n % 10;
      rev = rev * 10 + dig;
      n = n / 10;
    }
    if(i == rev) pal_count++;

    if(sieve[i]) prime_count++;

    if(prime_count <= (pal_count * p)/q) {
      ans = i;
    }
  }

  cout << ans << endl;
}
