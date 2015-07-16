// Ankit, Srijan and a game of stone piles

#include <iostream>
#include <algorithm>
#include <map>

#define MOD 1000000007

using namespace std;

int A[100010];
int fact[100010];
map<int, int> freq;

/* This function calculates (a^b)%MOD */
long long pow(long long base, long long exp){
  base %= MOD;
  long long result = 1;
  while(exp > 0){
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

long long countFact(long long n, long long p)
{
  long long k=0;
  while (n>=p)
  {
    k+=n/p;
    n/=p;
  }
  return k;
}


/*  Modular Multiplicative Inverse
 *      Using Euler's Theorem
 *          a^(phi(m)) = 1 (mod m)
 *              a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n)
{
  return pow(n,MOD-2);
}

long long C(int n, int r)
{
  if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
    return 0;

  return (fact[n] *
      ((InverseEuler(fact[r]) *
        InverseEuler(fact[n-r])) % MOD) % MOD);
}


int main() {
  fact[0] = 1;
  for(int i = 1; i <= 100000; i++) fact[i] = fact[i - 1] * i;

  int T; cin >> T;

  while(T--) {
    freq.clear();

    int N; cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> A[i];
      freq[A[i]]++;
    }

    long long t = 0;
    int m = freq[1]/2;
    for(int i = 0; i < m; i++) {
      t += C(N - 1 - 2*i, freq[1] - i);
      t %= MOD;
    }

    long long q = fact[N - freq[1]];
    long denom = 1;
    for(auto it: freq) {
      if(it.first == 1) continue;
      denom *= fact[it.second];
      denom %= MOD;
    }
    q = (q * InverseEuler(denom)) % MOD;

    long long ans = (t * q) % MOD;
    cout << ans << endl;
  }
}
