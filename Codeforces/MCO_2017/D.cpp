#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string S, T, A;
int N, M;
int Z[600000];
int dp[300000];  // dp[i] = max index such that i..dp[i] is good
int segtree[1200004];

void update(int L, int R, int i, int x, int v) {
  segtree[i] = max(segtree[i], v);

  if(L == R) {
    return;
  }

  int mid = (L + R)/2;
  if(x <= mid) {
    update(L, mid, 2*i + 1, x, v);
  }
  else {
    update(mid + 1, R, 2*i + 2, x, v);
  }
}

int query(int L, int R, int i, int qL, int qR) {
  if(L > qR || R < qL) return 0;
  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return max(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

int main() {
  cin >> S >> T;
  A = S + T;
  N = S.length(); M = T.length();

  int L = 0, R = 0;
  for(int i = 1; i < (N + M); i++) {
    if(i > R) {
      L = R = i;
      while(R < (N + M) && A[R - L] == A[R]) R++;
      R--;
      Z[i] = R - L + 1;
    }
    else {
      if(Z[i - L] < R - i + 1) {
        Z[i] = Z[i - L];
      }
      else {
        L = i;
        while(R < (N + M) && A[R - L] == A[R]) R++;
        R--;
        Z[i] = R - L + 1;
      }
    }
  }

  for(int i = M - 1; i >= 0; i--) {
    dp[i] = i + Z[i + N] - 1;
    if(Z[i + N] > 0) {
      dp[i] = max(dp[i], query(0, M - 1, 0, i + 1, i + Z[i + N]));
      update(0, M - 1, 0, i, dp[i]);
    }
  }

  int Q; cin >> Q;

  while(Q--) {
    int L, R; cin >> L >> R; L--; R--;
    if(dp[L] >= R) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
