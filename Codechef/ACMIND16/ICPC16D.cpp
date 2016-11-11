#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MOD 1000000007

vector<int> divisors[750001];
long long dp[750001];
int A[750000];

int main() {
  for(int i = 2; i <= 750000; i++) {
    for(int j = i + i; j <= 750000; j += i) {
      divisors[j].push_back(i);
    }
  }

  int T; scanf("%d", &T);

  while(T--) {
    for(int i = 0; i <= 750000; i++) dp[i] = 0;

    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    sort(A, A + N);

    long long ans = 0;
    for(int i = 0; i < N; i++) {
      long long curr = 1;
      curr = (curr + dp[1]) % MOD;
      for(int x: divisors[A[i]]) curr = (curr + dp[x]) % MOD;
      ans = (ans + curr) % MOD;
      dp[A[i]] = (dp[A[i]] + curr) % MOD;
    }

    printf("%lld\n", ans);
  }
}
