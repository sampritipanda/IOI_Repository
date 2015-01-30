// Robot and Paths

#include <stdio.h>
#include <string.h>

int main() {
    int M, N, P; scanf("%d %d %d", &M, &N, &P);
    long long dp[M][N];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = 1;
        }
    }

    for(int k = 0; k < P; k++){
        int i, j; scanf("%d %d", &i, &j);
        i--; j--;
        dp[i][j] = 0;
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(dp[i][j]){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(i == 0){
                    dp[i][j] = dp[i][j - 1];
                }
                else if(j == 0){
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
                }
            }
        }
    }

    printf("%lld\n", dp[M - 1][N - 1]);
}
