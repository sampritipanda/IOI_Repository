#include <stdio.h>
#include <algorithm>

using namespace std;

int freq[1000010];

int main() {
  int T; scanf("%d", &T);

  while(T--){
    for(int i = 0; i <= 1000000; i++) freq[i] = 0;

    int N; scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++) {
      scanf("%d", &A[i]);
      freq[A[i]]++;
    }

    int minimum = 0, maximum = 0;
    for(int i = 0; i <= 1000000; i++) {
      if(freq[i] == 0) continue;

      freq[i] = 0;
      freq[i + 1] = 0;
      maximum++;
    }

    for(int i = 0; i < N; i++) freq[A[i]]++;
    for(int i = 0; i <= 1000000; i++) {
      if(freq[i] == 0) continue;

      if(freq[i + 1] == 1 && freq[i + 2] == 1) {
        freq[i] = 0; freq[i + 1] = 0; freq[i + 2] = 0;
      }
      else {
        freq[i] = 0;
        freq[i + 1] = 0;
      }
      minimum++;
    }

    printf("%d %d\n", minimum, maximum);
  }
}
