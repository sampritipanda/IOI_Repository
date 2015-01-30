// Twin Robots

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int memo[2500][2500];
int grid[2500][2500];
int N;

int rec(int i1, int j1, int i2, int j2){
    if(i1 < 0 || i1 > N - 1 || j1 < 0 || j1 > N - 1 || i2 < 0 || i2 > N - 1 || j2 < 0 || j2 > N - 1) return INT_MIN;
    if(i1 == N - 1 && j1 == N - 1) return grid[N - 1][N - 1] + grid[N - 1][0];
    if(memo[i1][j1] != -1) return memo[i1][j1];

    memo[i1][j1] = max(rec(i1 + 1, j1, i2, j2 - 1), rec(i1, j1 + 1, i2 + 1, j2)) + grid[i1][j1] + grid[i2][j2];
    return memo[i1][j1];
}

int main() {
    scanf("%d", &N);

    memset(memo, -1, sizeof(memo));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    printf("%d\n", rec(0, 0, 0, N - 1));
}
