// Glass Bead Game

#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

long long A, B, C;
long long f(int x, int y){
    return A*x*x +  B*y*y + C*x*y;
}

int main() {
    int M, N; scanf("%d %d %lld %lld %lld", &M, &N, &A, &B, &C);
    long long score = f(M, N);
    while(M > 0 || N > 0){
        if((M + N) % 2 == 1){
            long long score1 = LLONG_MAX, score2 = LLONG_MAX;
            if(M > 0) score1 = f(M - 1, N + 1);
            if(N > 0) score2 = f(M, N - 1);
            if(score1 < score2){
                score += score1;
                M--; N++;
            }
            else {
                score += score2;
                N--;
            }
        }
        else {
            long long score1 = LLONG_MIN, score2 = LLONG_MIN;
            if(M > 0) score1 = f(M - 1, N + 1);
            if(N > 0) score2 = f(M, N - 1);
            if(score1 > score2){
                score += score1;
                M--; N++;
            }
            else {
                score += score2;
                N--;
            }
        }
    }

    printf("%lld\n", score);
}
