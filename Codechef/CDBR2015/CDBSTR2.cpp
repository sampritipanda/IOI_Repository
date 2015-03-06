// Bob and his girlfriend

#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[2001][2001];

int main() {
  int T; scanf("%d", &T);

  while(T--){
    char X[2001], Y[2001];
    scanf(" %s", X);
    scanf(" %s", Y);
    int M = strlen(X), N = strlen(Y);
    for(int i = 0; i < M; i++) dp[i][0] = i;
    for(int j = 0; j < N; j++) dp[0][j] = j;

    for(int i = 1; i < M; i++){
      for(int j = 1; j < N; j++){
        int left = dp[i][j - 1] + 1;
        int right = dp[i - 1][j] + 1;
        int corner = dp[i - 1][j - 1] + (X[i - 1] != Y[j - 1]);
        dp[i][j] = min(left, min(right, corner));
      }
    }

    printf("%d\n", dp[M - 1][N - 1]);
  }
}
