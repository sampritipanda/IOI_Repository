// Suraj goes shopping

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N; scanf("%d", &N);
    vector<int> items(N);
    for(int i = 0; i < N; i++) scanf("%d", &items[i]);

    sort(items.begin(), items.end(), greater<int>());

    long long sum = 0;
    int i = 0;
    while(i < N){
      sum += items[i];
      if(i + 1 < N) sum += items[i + 1];
      i += 4;
    }
    printf("%lld\n", sum);
  }
}
