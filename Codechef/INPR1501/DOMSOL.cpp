// Domino Solitaire

#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N; scanf("%d", &N);
    int grid[N][2];
    for(int i = 0; i < N; i++) scanf("%d", &grid[i][0]);
    for(int i = 0; i < N; i++) scanf("%d", &grid[i][1]);

    int dp[N];
    dp[0] = abs(grid[0][0] - grid[0][1]);
    if(N > 1) dp[1] = max(dp[0] + abs(grid[1][0] - grid[1][1]), abs(grid[0][0] - grid[1][0]) + abs(grid[0][1] - grid[1][1]));

    for(int i = 2; i < N; i++){
        dp[i] = max(dp[i - 1] + abs(grid[i][0] - grid[i][1]), dp[i - 2] + abs(grid[i - 1][0] - grid[i][0]) + abs(grid[i - 1][1] - grid[i][1]));
    }
    printf("%d\n", dp[N - 1]);
}
