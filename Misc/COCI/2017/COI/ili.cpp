#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int A[20001];
int C[20001][2];

int main() {
  int N, M; scanf("%d %d", &N, &M);
  getchar();

  for(int i = 1; i <= N; i++) A[i] = -1;
  for(int i = N + 1; i <= N + M; i++) {
    char c; scanf("%c", &c);
    if(c == '?') A[i] = -1;
    else A[i] = c - '0';
  }

  getchar();

  for(int i = N + 1; i <= N + M; i++) {
    char type1, type2; int id1, id2;
    scanf("%c%d %c%d", &type1, &id1, &type2, &id2);
    getchar();

    if(type1 == 'x') C[i][0] = id1;
    else C[i][0] = N + id1;

    if(type2 == 'x') C[i][1] = id2;
    else C[i][1] = N + id2;
  }

  for(int i = N + M; i >= N + 1; i--) {
    if(A[i] == 0) {
      A[C[i][0]] = A[C[i][1]] = 0;
    }
    else {
      if(A[C[i][0]] == 0) A[C[i][1]] = 1;
      else if(A[C[i][1]] == 0) A[C[i][0]] = 1;
    }
  }

  for(int i = N + 1; i <= N + M; i++) {
    if(A[C[i][0]] == 0 && A[C[i][1]] == 0) A[i] = 0;
    else if(A[C[i][0]] == 1 || A[C[i][1]] == 1) A[i] = 1;
  }

  for(int i = N + 1; i <= N + M; i++) {
    if(A[i] == -1) printf("?");
    else printf("%c", '0' + A[i]);
  }
  printf("\n");
}
