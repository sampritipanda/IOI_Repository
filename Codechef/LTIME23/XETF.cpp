// Euler Totient Function Extended

#include <iostream>
#include <cmath>
#include <climits>
#include <vector>

#define MOD 1000000007LL

using namespace std;

long long gcd(long long a, long long b){
  if(b == 0) return a;
  else return gcd(b, a % b);
}

long long int phi(long long x)
{
  long long int ret = 1,i,pow;
  for (i = 2; x != 1; i++) 
  {
    pow = 1;
    if(i>sqrt(x))break;
    while (!(x%i)) 
    {
      x /= i;
      pow *= i;
    }
    ret *= (pow - (pow/i));
  }
  if(x!=1)ret*=(x-1);
  return ret;
}

long long mul(long long  a, long long  b, long long c) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    } 

    // Returns: (a * b/2) mod c
    long long a2 = mul(a, b / 2, c);

    // Even factor
    if ((b & 1) == 0) {
        // [((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return (a2 + a2) % c;
    } else {
        // Odd exponent
        // [(a mod c) + ((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return ((a % c) + (a2 + a2)) % c;
    }
}

long long pow(long long b, long long e, long long m)
{
   long long r = 1;
   for(; e; e >>= 1) {
      if(e & 1)
         r = mul(r, b, m);
      b = mul(b, b, m);
   }
   return r;
}

bool MillerRabin(long long n, long long k)
{
   // Factor n-1 as d*2^s
   long long s = 0;
   long long d = n - 1;
   for(; !(d & 1); s++)
      d >>= 1;
 
   // Verify x = k^(d 2^i) mod n != 1
   long long x = pow(k % n, d, n);
   if(x == 1 || x == n-1)
      return true;
   while(s-- > 1) {
      // x = x^2 mod n
      x = mul(x, x, n);
      if(x == 1)
         return false;
      if(x == n-1)
         return true;
   }
   return false;
}

int arr[7] = {2, 3, 5, 7, 11, 13, 17};
bool is_prime(long long n)
{
   // Handle small primes fast
   for(int i = 2; i < 10000; i++) {
     if(n % i == 0)
         return false;
   }

   // Do a few Miller-Rabin rounds
   for(int i = 0; i < 7; i++)
      if(!MillerRabin(n, arr[i]))
         return false;
 
   // Assume prime
   return true;
}

long long brent_pollard_factor(long long n)
{
   const long long m = 1000;
   long long a, x, y, ys, r, q, g;
   do
      a = random() % n;
   while(a==0||a==n-2);
   y = random() % n;
   r = 1;
   q = 1;
 
   do {
      x = y;
      for(long long i=0; i < r; i++) {
         // y = y² + a mod n
         y = mul(y, y, n);
         y += a;
         if(y < a)
            y += (LLONG_MAX - n) + 1;
         y %= n;
      }
 
      long long k =0;
      do {
         for(long long i=0; i < m && i < r-k; i++) {
            ys = y;
 
            // y = y² + a mod n
            y = mul(y, y, n);
            y += a;
            if(y < a)
               y += (LLONG_MAX - n) + 1;
            y %= n;
 
            // q = q |x-y| mod n
            q = mul(max(q, abs(x - y)), min(q, abs(x - y)), n);
         }
         g = gcd(q, n);
         k += m;
      } while(k < r && g == 1);
 
      r <<= 1;
   } while(g == 1);
 
   if(g == n) {
      do {
         // ys = ys² + a mod n
         ys = mul(ys, ys, n);
         ys += a;
         if(ys < a)
            ys += (LLONG_MAX - n) + 1;
         ys %= n;
 
         g = gcd((x>ys)?x-ys:ys-x, n);
      } while(g == 1);
   }
 
   return g;
}

int small_factor(int a){
  for(int i = 2; i < a; i++){
    if(a % i == 0) return i;
  }
  return -1;
}

vector<long long> prime_factors(long long n)
{
  vector<long long> factors;
  vector<long long> primes;

  long long factor = brent_pollard_factor(n);
  factors.push_back(n / factor);
  factors.push_back(factor);

  do {
    long long m = factors[factors.size() - 1];
    factors.pop_back();

    if(m == 1)
      continue;

    if(is_prime(m)) {
      primes.push_back(m);

      // Remove the prime from the other factors
      for(int i=0; i < factors.size(); i++) {
        long long k = factors[i];
        if(k % m == 0) {
          do
            k /= m;
          while(k % m == 0);
          factors[i] = k;
        }
      }
    } else {
      factor = (m < 100) ? small_factor(m) : brent_pollard_factor(m);
      factors.push_back(m / factor);
      factors.push_back(factor);
    }
  } while(factors.size());

  return primes;
}

int main() {
  int T; cin >> T;

  while(T--){
    long long N, K; cin >> N >> K;
    if(N <= 10000){
      long long ans = 0;
      for(int i = 1; i <= N; i++){
        if(gcd(i, N) != 1) continue;
        ans += pow(i, K, MOD);
        ans %= MOD;
      }
      cout << ans << endl;
    }
    else {
      if(K == 0){
        cout << phi(N) % MOD << endl;
      }
      else if(K == 1){
        vector<long long> primes = prime_factors(N);
        double ans = N;
        ans *= N/2.0;
        for(auto p: primes){
          ans *= (1.0 - 1.0/p);
        }
        cout << (long long)(floor(ans)) << endl;
      }
    }
  }
}
