#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

long long dp[100001];
long long segtree[400001];
int A[100001];

void update(int L, int R, int i, int ind, long long v) {
  if(L == R) {
    segtree[i] = v;
    return;
  }

  int mid = (L + R)/2;

  if(ind <= mid) {
    update(L, mid, 2*i + 1, ind, v);
  }
  else {
    update(mid + 1, R, 2*i + 2, ind, v);
  }
  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

long long query(int L, int R, int i, int qL, int qR) {
  if(L > qR || R < qL) return LLONG_MAX/2;

  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;

  return min(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 1; i < N; i++) cin >> A[i];

  // dp[i] = min(dp[i], (j - i - 1) + dp[j] + (N - j + 1) - (A[i] - j));

  for(int i = 0; i <= 4 * N; i++) segtree[i] = LLONG_MAX/2;

  dp[N] = 0;
  update(1, N, 0, N, dp[N] + N);
  for(int i = N - 1; i >= 1; i--) {
    dp[i] = (N - A[i] - i) + query(1, N, 0, i + 1, A[i]);
    update(1, N, 0, i, dp[i] + i);
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) ans += dp[i];
  cout << ans << endl;
}
