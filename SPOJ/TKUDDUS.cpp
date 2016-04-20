#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cassert>
#include <set>

using namespace std;

char S[1000010];
char P[1000010];
char A[2000020];
int  Z[2000020];
int Z2[1000020];
int nx[1000020];  // first j > i, Z2[j] == M
int pv[1000020];  // last j < i, Z2[j] == M
int dp[1000020];  // number of non-overlap substrings start at i

void reset() {
  memset(Z, 0, sizeof 0);
  memset(Z2, 0, sizeof 0);
  memset(nx, 0, sizeof 0);
  memset(dp, 0, sizeof 0);
}

int main() {
  int T; scanf("%d", &T);

  for(int t = 1; t <= T; t++) {
    reset();

    scanf(" %s", S);
    scanf(" %s", P);

    // 012345678
    // AB$ABCABC
    // M = 2, N = 6
    int N = strlen(S), M = strlen(P);
    for(int i = 0; i < M; i++) A[i] = P[i];
    A[M] = '$';
    for(int j = 0; j < N; j++) A[M + 1 + j] = S[j];
    A[M + 1 + N] = '\0';

    int tot = strlen(A);
    assert(tot == (M + N + 1));

    int L = 0, R = 0;
    for(int i = 1; i < tot; i++) {
      if(i > R) {
        L = R = i;
        while(R < tot && A[R] == A[R-L]) R++;
        Z[i] = R - L; R--;
      }
      else {
        int x = i - L;
        if(Z[x] <= R - i + 1) Z[i] = Z[x];
        else {
          L = i;
          while(R < tot && A[R] == A[R-L]) R++;
          Z[i] = R-L; R--;
        }
      }
    }

    for(int i = 0; i < N; i++) {
      Z2[i] = Z[i + M + 1];
    }

    int next_ans = N;
    for(int i = N - 1; i >= 0; i--) {
      if(Z2[i] == M) next_ans = i;
      nx[i] = next_ans;
    }
    int prev_ans = -1;
    for(int i = 0; i < N; i++) {
      if(Z2[i] == M) prev_ans = i;
      pv[i] = prev_ans;
    }

    for(int i = N - 1; i >= 0; i--) {
      if(Z2[i] == M) {
        dp[i] = 1 + dp[nx[i + 1]];
      }
    }

    printf("Case %d:\n", t);
    int Q; scanf("%d", &Q);
    while(Q--) {
      int i, j; scanf("%d %d", &i, &j);
      int ans = 0;
      if(nx[i] <= pv[j] && nx[i] <= j && pv[i] >= i) {
        ans = max(ans, dp[nx[i]] - dp[pv[j]]);
        if(j - pv[j] + 1 >= M) ans++;
      }

      printf("%d\n", ans);
    }
  }
}
