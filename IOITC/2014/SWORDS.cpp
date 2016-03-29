#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int T[100000], D[100000];
// dp[i] = answer for i..N
int dp[100001];
int segtree[400004];
int lazy[400004];

void propagate(int L, int R, int i) {
  if(lazy[i] != 0) {
    segtree[i] += lazy[i];

    if(L != R) {
      lazy[2*i + 1] += lazy[i];
      lazy[2*i + 2] += lazy[i];
    }

    lazy[i] = 0;
  }
}

int query(int L, int R, int i, int qL, int qR) {
  propagate(L, R, i);

  if(L > R) return 0;
  if(R < qL || L > qR) return 0;

  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;

  return max(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

void update(int L, int R, int i, int qL, int qR, int v) {
  propagate(L, R, i);

  if(L > R) return;
  if(R < qL || L > qR) return;

  if(qL <= L && R <= qR) {
    lazy[i] += v;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, v);
  update(mid + 1, R, 2*i + 2, qL, qR, v);

  segtree[i] = max(segtree[2*i + 1], segtree[2*i + 2]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> T[i] >> D[i];
  }

  dp[N] = 0;
  for(int i = N - 1; i >= 0; i--) {
    // Dodge
    dp[i] = dp[i + 1];
    // Pick and Hit
    int L = i + T[i] + 1;
    int R = min(i + T[i] + D[i], N - 1);
    dp[i] = max(dp[i], query(0, N - 1, 0, L, R) - (L - i - 1));

    update(0, N - 1, 0, i, i, dp[i + 1]);
    update(0, N - 1, 0, i, N - 1, 1);
  }
  cout << dp[0] << endl;
}
