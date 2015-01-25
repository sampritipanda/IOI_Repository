// Next Big number

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T; scanf("%d", &T);

    while(T--){
        int N; scanf("%d", &N);
        vector<int> number(N);
        for(int i = 0; i < N; i++) scanf("%d", &number[i]);

        for(int i = 0; i < N; i++) printf("%d", number[i]);
        printf("\n");

        if(next_permutation(number.begin(), number.end())){
            for(int i = 0; i < N; i++) printf("%d", number[i]);
        }
        else {
            printf("NO NXTBIG");
        }

        printf("\n");
    }
}
