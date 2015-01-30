// Vogon Zoo

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, K; scanf("%d %d", &N, &K);
    vector<int> dragons(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &dragons[i]);
    }
    sort(dragons.begin(), dragons.end());

    int curr = dragons[0];
    int num_dragons = 1;
    for(int i = 1; i < N; i++){
        if(dragons[i] - curr >= K){
            curr = dragons[i];
            num_dragons++;
        }
    }
    printf("%d\n", num_dragons);
}
