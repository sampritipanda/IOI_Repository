#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

struct node {
  long long v;
  int i;

  node() {
    v = LLONG_MAX/2;
    i = -1;
  }

  node(long long _v, int _i) {
    v = _v;
    i = _i;
  }

  bool operator < (const node R) const {
    if(v == R.v) return i < R.i;
    return v < R.v;
  }
};

long long X[200002];
long long P[200002];
// dp[i] = minimum cost to get to ith gas station
long long dp[200002];
vector<pair<long long, long long> > temp;
node segtree[800008];

node query(int L, int R, int i, int qL, int qR) {
  if(L > R || R < qL || L > qR) return node();

  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;

  return min(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

// set A[i] = v
void update(int L, int R, int i, int x, long long v) {
  if(L == R) {
    segtree[i].v = v;
    segtree[i].i = x;
    return;
  }

  int mid = (L + R)/2;
  if(x <= mid) {
    update(L, mid, 2*i + 1, x, v);
  }
  else {
    update(mid + 1, R, 2*i + 2, x, v);
  }
  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  long long D, V; cin >> D >> V;

  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    cin >> X[i] >> P[i];
    temp.push_back({X[i], P[i]});
  }
  sort(temp.begin(), temp.end());

  for(int i = 1; i <= N; i++) {
    X[i] = temp[i - 1].first;
    P[i] = temp[i - 1].second;
  }

  X[0] = 0; P[0] = 0;
  X[N + 1] = D; P[N + 1] = 0;

  for(int i = 0; i <= N + 1; i++) dp[i] = LLONG_MAX/2;

  dp[0] = 0;
  int i;
  for(i = 1; i <= N + 1; i++) {
    if(X[i] > V) break;
    dp[i] = 0;
    long long upd = (X[N + 1] - X[i]) * P[i] - (V - X[i]) * P[i];
    update(1, N + 1, 0, i, upd);
  }

  for(; i <= N + 1; i++) {
    int start = upper_bound(X, X + N + 2, X[i] - V - 1) - X;
    assert(start > 0);

    if(start == i) continue;
    node best = query(1, N + 1, 0, start, i - 1);
    if(best.v > LLONG_MAX/4) continue;

    dp[i] = best.v - (P[best.i] * (X[N + 1] - X[i]));
    if(dp[i] < 0) dp[i] = 0;

    long long upd = dp[i] + (X[N + 1] - X[i]) * P[i];
    update(1, N + 1, 0, i, upd);
  }

  if(dp[N + 1] > LLONG_MAX/4) dp[N + 1] = -1;
  cout << dp[N + 1] << endl;
}
