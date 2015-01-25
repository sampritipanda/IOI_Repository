// Equilibrium number

#include <stdio.h>

unsigned long long range_sum(unsigned long long A[], int L, int R){
    if(L == 0) return A[R];
    else return A[R] - A[L - 1];
}

int main() {
    int T; scanf("%d", &T);

    while(T--){
        int N; scanf("%d", &N);
        unsigned long long A[N], sum[N];
        for(int i = 0; i < N; i++){
            int a; scanf("%llu", &A[i]);
        }
        sum[0] = A[0];
        for(int i = 1; i < N; i++) sum[i] = sum[i - 1] + A[i];

        bool flag = false;
        for(int i = 0; i < N; i++){
            if(i == 0){
                if(range_sum(sum, i + 1, N - 1) == 0) {
                    printf("%llu\n", A[i]);
                    flag = true;
                    break;
                }
            }
            else if(i == N - 1){
                if(range_sum(sum, 0, i - 1) == 0) {
                    printf("%llu\n", A[i]);
                    flag = true;
                    break;
                }
            }
            else {
                if(range_sum(sum, 0, i - 1) == range_sum(sum, i + 1, N - 1)) {
                    printf("%llu\n", A[i]);
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) printf("NO EQUILIBRIUM\n");
    }
}
