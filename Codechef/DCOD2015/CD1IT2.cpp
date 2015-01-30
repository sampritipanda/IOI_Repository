// Exponential

#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    int T; scanf("%d", &T);

    while(T--){
        int X; scanf("%d", &X);
        if(X == 0) printf("1\n");
        else {
            long long ans = ceil(X/2.3025850929940456840);
            printf("%lld\n", ans);
        }
    }
}
