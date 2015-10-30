// Save the nature

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long A[151][151];

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    memset(A, 0LL, sizeof A);

    int N, M; long long S; scanf("%d %d %lld", &N, &M, &S);

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        scanf("%lld", &A[i][j]);
      }
    }

    for(int i = 2; i <= N; i++) A[i][1] = A[i - 1][1] + A[i][1];
    for(int j = 2; j <= M; j++) A[1][j] = A[1][j - 1] + A[1][j];

    for(int i = 2; i <= N; i++){
      for(int j = 2; j <= M; j++){
        A[i][j] = A[i][j - 1] + A[i - 1][j] + A[i][j] - A[i - 1][j - 1];
      }
    }

    long long cnt = 0;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        for(int k = 1; k <= i; k++) {
          for(int l = 1; l <= j; l++) {
            long long sum = A[i][j] - A[i][l - 1] - A[k - 1][j] + A[k - 1][l - 1];
            if(sum <= S) cnt++;
          }
        }
      }
    }

    printf("%lld\n", cnt);
  }
}
