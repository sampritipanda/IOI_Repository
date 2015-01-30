// Chhota Bheem and Kirmada

#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    int T; scanf("%d", &T);

    while(T--){
        long long N, K; scanf("%lld %lld", &N, &K);

        int power = 0;
        while(K > 0){
            power++;
            K -= 9 * pow(10, power - 1) * power;
        }
        K += 9 * pow(10, power - 1) * power;
        if(K % power == 0){
            long long num = pow(10, power - 1) + K/power - 1;
            printf("%lld\n", num % 10);
        }
        else {
            long long num = pow(10, power - 1) + K/power;
            long long num2 = num/pow(10, power - (K % power));
            printf("%lld\n", num2 % 10);
        }
    }
}
