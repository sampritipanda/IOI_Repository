#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

long long A[100000];
long long dp[2][100000];

int main() {
  int N; scanf("%d", &N);

  for(int i = 0; i < N; i++) scanf("%lld", &A[i]);

  for(int i = 0; i < N; i++) {
    dp[0][i] = LLONG_MIN/2;
    dp[1][i] = LLONG_MIN/2;
  }

  dp[0][0] = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < N; j++) {
    }
  }
}
