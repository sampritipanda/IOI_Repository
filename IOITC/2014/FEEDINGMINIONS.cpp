// Feeding Minions

#include <stdio.h>
#include <algorithm>

using namespace std;

struct minion {
    int A, B, C;
};

int main() {
    int T; scanf("%d", &T);

    while(T--){
        int N; scanf("%d", &N);
        minion* minions = new minion[N];
        int without_neighbour[N], with_neighbour[N];
        for(int i = 0; i < N; i++) {
            scanf("%d %d %d", &minions[i].A, &minions[i].B, &minions[i].C);
            without_neighbour[i] = with_neighbour[i] = 0;
        }
        without_neighbour[0] = minions[0].A;
        with_neighbour[0] = minions[0].B;

        for(int i = 1; i < N; i++){
            without_neighbour[i] = max(without_neighbour[i - 1] + minions[i].B, with_neighbour[i - 1] + minions[i].A);
            with_neighbour[i] = max(without_neighbour[i - 1] + minions[i].C, with_neighbour[i - 1] + minions[i].B);
        }

        printf("%d\n", without_neighbour[N - 1]);
        delete[] minions;
    }
}
