// Easy Exam

#include <iostream>
#include <algorithm>

#define MOD 2003

using namespace std;

long long dp[500][500];

long long modpow(long long base, long long exp) {
  long long result = 1;

  while(exp > 0) {
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }

  return result;
}

long long partition(int N, int K) {
  if(N < 0 || K < 0) return 0;
  if(K == 1) return 1;
  if(K > N) return 0;
  if(K == N) return 1;

  if(dp[N][K] != 1) return dp[N][K];

  long long ans = partition(N - 1, K - 1) + partition(N - K, K);
  dp[N][K] = ans;
  return ans;
}

int main() {
}
