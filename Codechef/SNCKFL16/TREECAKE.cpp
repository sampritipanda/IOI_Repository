#include <iostream>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;
long long int a,b,c,d;

void fast_fib(long long int n,long long int ans[], long long mod)
{
  if(n == 0)
  {
    ans[0] = 0;
    ans[1] = 1;
    return;
  }
  fast_fib((n/2),ans, mod);
  a = ans[0];             /* F(n) */
  b = ans[1];             /* F(n+1) */
  c = 2*b - a;
  if(c < 0)
    c += mod;
  c = (a * c) % mod;      /* F(2n) */
  d = (a*a + b*b) % mod;  /* F(2n + 1) */
  if(n%2 == 0)
  {
    ans[0] = c;
    ans[1] = d;
  }
  else
  {
    ans[0] = d;
    ans[1] = c+d;
  }
}

long long fib(long long N, long long mod) {
  long long ans[2] = {0, 0};
  fast_fib(N, ans, mod);
  return ans[0];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long H; cin >> H;
    bool odd = fib(H, 2) == 1;
    long long ans = fib(H, MOD);
    if(odd) ans = (ans + 1) % MOD;
    ans *= 500000004;
    ans %= MOD;
    cout << ans << endl;
  }
}
