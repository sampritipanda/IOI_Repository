// Submatrix containing ones

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int T; scanf("%d", &T);

    while(T--){
        int N, M; scanf("%d %d", &M, &N);
        int A[M][N], dp[M][N];
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &A[i][j]);
            }
        }

        for(int i = 0; i < M; i++) dp[i][0] = A[i][0];
        for(int j = 0; j < N; j++) dp[0][j] = A[0][j];

        for(int i = 1; i < M; i++){
            for(int j = 1; j < N; j++){
                if(A[i][j]){
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        int max_size = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(dp[i][j] > max_size) max_size = dp[i][j];
            }
        }

        printf("%d\n", max_size);
    }
}
