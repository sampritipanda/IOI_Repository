#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAGIC = 350;
int A[100001];
int calc[MAGIC + 1][100001];

int main() {
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

  for(int K = 1; K <= MAGIC; K++) {
    for(int i = N; i >= 1; i--) {
      if(i + A[i] + K > N) calc[K][i] = 1;
      else calc[K][i] = 1 + calc[K][i + A[i] + K];
    }
  }

  int Q; scanf("%d", &Q);

  while(Q--) {
    int p, k; scanf("%d %d", &p, &k);

    if(k <= MAGIC) printf("%d\n", calc[k][p]);
    else {
      int cnt = 0;
      while(p <= N) {
        p = p + A[p] + k;
        cnt++;
      }
      printf("%d\n", cnt);
    }
  }
}
