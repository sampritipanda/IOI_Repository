// Major Number

#include <stdio.h>
#include <map>

using namespace std;

int main() {
    int T; scanf("%d", &T);
    map<int, int> frequencies;

    while(T--){
        int N; scanf("%d", &N);
        for(int i = 0; i < N; i++){
            int a; scanf("%d", &a);
            frequencies[a]++;
        }
        for(map<int, int>::iterator it = frequencies.begin(); it != frequencies.end(); it++){
            if(it->second > N/2) {
                printf("%d\n", it->first);
                break;
            }
        }
        frequencies.clear();
    }
}
