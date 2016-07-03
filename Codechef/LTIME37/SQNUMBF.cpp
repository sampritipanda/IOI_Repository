#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1000000;
int sieve[MAX + 1];
vector<long long> primes;
long long A[101];
bool pres[MAX + 1];

long long gcd(long long a, long long b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  for(int i = 2; i <= MAX; i++) sieve[i] = true;

  for(int i = 2; i <= MAX; i++) {
    if(!sieve[i]) continue;
    primes.push_back(i);
    for(int j = i + i; j <= MAX; j += i) {
      sieve[j] = false;
    }
  }

  int T; scanf("%d", &T);

  while(T--) {
    int N; scanf("%d", &N);

    for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
    for(int i = 0; i < MAX; i++) pres[i] = false;

    long long ans = -1;

    for(int i = 1; i <= N; i++) {
      for(long long x: primes) {
        if(x > A[i]) break;
        if(A[i] % x == 0) {
          if(A[i] % (x * x) == 0) {
            ans = x;
            break;
          }
          if(pres[x]) {
            ans = x;
            break;
          }
          pres[x] = true;
          while(A[i] % x == 0) A[i] /= x;

        }
      }
      if(A[i] > 1) {
        long long root = (long long)sqrt(A[i]);
        if(root * root == A[i]) {
          ans = root;
        }
      }
      if(ans != -1) break;
    }

    if(ans == -1) {
      for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
          long long g = gcd(A[i], A[j]);
          if(g > 1) {
            ans = g;
            break;
          }
        }
        if(ans != -1) break;
      }
    }

    printf("%lld\n", ans);
  }
}

