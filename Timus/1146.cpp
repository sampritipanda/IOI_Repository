#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int A[151][151];

int main() {
  memset(A, 0, sizeof A);

  int N; scanf("%d", &N);

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  for(int i = 2; i <= N; i++) A[i][1] = A[i - 1][1] + A[i][1];
  for(int j = 2; j <= N; j++) A[1][j] = A[1][j - 1] + A[1][j];

  for(int i = 2; i <= N; i++){
    for(int j = 2; j <= N; j++){
      A[i][j] = A[i][j - 1] + A[i - 1][j] + A[i][j] - A[i - 1][j - 1];
    }
  }

  int ans = -INT_MIN;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = 1; k <= i; k++) {
        for(int l = 1; l <= j; l++) {
          int sum = A[i][j] - A[i][l - 1] - A[k - 1][j] + A[k - 1][l - 1];
          ans = max(ans, sum);
        }
      }
    }
  }

  printf("%d\n", ans);
}
