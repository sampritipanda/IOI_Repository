#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cassert>
#include <climits>

using namespace std;

long long INF = 100000000007LL;

long long X[100010], C[100010];
long long dp[100010];
long long segtree[400100];

void update(int L, int R, int i, int pos, long long val){
  if(L == R){
    segtree[i] = min(segtree[i], val);
    return;
  }

  int mid = L + (R - L)/2;
  if(pos <= mid){
    update(L, mid, 2*i + 1, pos, val);
  }
  else {
    update(mid + 1, R, 2*i + 2, pos, val);
  }

  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

long long query(int seg_start, int seg_end, int L, int R, int i){
  if(seg_start > R || seg_end < L) return LLONG_MAX/2;

  if(L <= seg_start && seg_end <= R) return segtree[i];

  int mid = seg_start + (seg_end - seg_start)/2;
  long long left = query(seg_start, mid, L, R, 2*i + 1);
  long long right = query(mid + 1, seg_end, L, R, 2*i + 2);
  return min(left, right);
}

int main() {
  int T; cin >> T;

  while(T--) {
    int N, L, D; cin >> N >> L >> D;

    for(int i = 0; i < 100010; i++) dp[i] = LLONG_MAX/2;
    for(int i = 0; i < 400100; i++) {
      segtree[i] = LLONG_MAX/2;
    }

    for(int i = 1; i <= N; i++) {
      cin >> X[i] >> C[i];
    }

    X[0] = C[0] = 0;
    dp[N + 1] = 0;
    X[N + 1] = L;
    C[N + 1] = 0;

    update(0, N + 2, 0, N + 1, 0);

    for(int i = N; i >= 0; i--) {
      int end_index = upper_bound(X + i, X + N + 2, X[i] + D) - X;
      bool possible = true;
      if(end_index == N + 2 - i && X[i + 1] - X[i] > D) {
        possible = false;
      }
      else end_index--;

      if(possible) {
        dp[i] = min(query(0, N + 2, i + 1, end_index, 0) + C[i], dp[i]);
      }
      assert(dp[i] >= 0);
      update(0, N + 2, 0, i, dp[i]);
    }

    if(dp[0] >= LLONG_MAX/2) cout << "NO" << endl;
    else cout << "YES" << " " << dp[0] << endl;
  }
}
