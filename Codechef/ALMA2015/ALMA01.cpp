// Chhota Bheem and the Game of Anagrams

#include <stdio.h>

#define MOD 1000000007

unsigned long long modpow(unsigned long long base, unsigned long long exp){
    base %= MOD;
    unsigned long long result = 1;
    while(exp > 0){
        if(exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}
int main() {
    int T; scanf("%d", &T);

    while(T--){
        int N, K; scanf("%d %d", &N, &K);
        unsigned long long result = 1;
        for(int i = 1; i <= N; i++) {
            result = (result * i) % MOD;
        }

        unsigned long long denominator = 1;
        for(int i = 1; i <= (N - K); i++) {
            denominator = (denominator * i) % MOD;
        }

        result *= modpow(denominator, MOD - 2) % MOD;
        result %= MOD;

        printf("%llu\n", result);
    }
}
