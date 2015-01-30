// Cultural Programme

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; scanf("%d", &N);
    vector<int> enter(N), exit(N);

    for(int i = 0; i < N; i++) scanf("%d %d", &enter[i], &exit[i]);

    sort(enter.begin(), enter.end());
    sort(exit.begin(), exit.end());

    int maxNum = 0;
    for(int i = 0; i < N; i++){
        int num = lower_bound(enter.begin(), enter.end(), exit[i]) - enter.begin() - i;
        maxNum = max(maxNum, num);
    }

    printf("%d\n", maxNum);
}
