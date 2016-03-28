// Feeding Minions

#include <stdio.h>
#include <algorithm>

using namespace std;

int A[1000];
int B[1000];
int C[1000];
int N;
int dp[1001][2];

// j = 0 = previous not done, 1 = previous done
int solve(int i, int j) {
  if(i == N) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  int ans = 0, type1 = 0, type2 = 0;
  if(j == 0) {
    type1 = solve(i + 1, 1) + A[i];

    if(i < N - 1) type2 = solve(i + 1, 0) + B[i];
  }
  else {
    if(i < N - 1) {
      type1 = solve(i + 1, 0);
      type1 += C[i];
    }

    type2 = solve(i + 1, 1) + B[i];
  }

  ans = max(type1, type2);

  return dp[i][j] = ans;
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    for(int i = 0; i <= 1000; i++) {
      dp[i][0] = dp[i][1] = -1;
    }

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d %d %d", &A[i], &B[i], &C[i]);
    }
    C[0] = 0;
    C[N - 1] = 0;

    printf("%d\n", solve(0, 0));
  }
}
