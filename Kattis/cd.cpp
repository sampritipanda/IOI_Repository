// CD

#include <stdio.h>
#include <map>

using namespace std;

map<int, int> freq;

int main() {
  while(true) {
    freq.clear();
    int N, M; scanf("%d %d", &N, &M);
    if(N == 0 && M == 0) break;

    while(N--){
      int a; scanf("%d", &a); freq[a]++;
    }

    int ans = 0;
    while(M--){
      int a; scanf("%d", &a);
      if(freq.find(a) != freq.end()) ans++;
    }

    printf("%d\n", ans);
  }
}
