// Almost Sorted Permutation 

#include <stdio.h>

using namespace std;

int A[1000000];

inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
            c=getchar_unlocked();
        }
    while(c>='0'&&c<='9'){
            x=(x<<1)+(x<<3)+c-'0';
            c=getchar_unlocked();
        }
    return x;
}

int main() {
  int T = scan();

  while(T--) {
    int N = scan();

    A[0] = scan();
    for(int i = 1; i < N; i++) {
      A[i] = scan();
      if(A[i] < A[i - 1]) {
        A[i] ^= A[i - 1];
        A[i - 1] ^= A[i];
        A[i] ^= A[i - 1];
      }
    }

    bool pos = true;
    for(int i = 0; i < N - 1; i++) {
      if(A[i] > A[i + 1]) {
        pos = false;
        break;
      }
    }

    if(pos) printf("YES\n");
    else printf("NO\n");
  }
}
