#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long phi (long long n) {
    long long result = n;
    for (long long i=2; i*i<=n; ++i)
        if (n % i == 0) {
                    while (n % i == 0)
                        n /= i;
                    result -= result / i;
                }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
  long long N, K; cin >> N >> K;

  long long ans = phi(N);
  for(long long i = 2; i <= K; i++) {
    if(i % 2 == 0) continue;
    ans = phi(ans);
    if(ans == 1) break;
  }

  cout << (ans % MOD) << endl;
}
