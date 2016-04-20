#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int A[100001];
int dp[100001];
pair<int, int> segtree[400001];   // {min, max}
int dp_tree[400005];

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = {A[L], A[L]};
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);

  segtree[i] = {min(segtree[2*i + 1].first, segtree[2*i + 2].first), max(segtree[2*i + 1].second, segtree[2*i + 2].second)};
}

pair<int, int> query(int L, int R, int i, int qL, int qR) {
  if(L > R || L > qR || R < qL) return {INT_MAX/2, INT_MIN/2};

  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  auto left = query(L, mid, 2*i + 1, qL, qR);
  auto right = query(mid + 1, R, 2*i + 2, qL, qR);

  return {min(left.first, right.first), max(left.second, right.second)};
}

int query2(int L, int R, int i, int qL, int qR) {
  if(L > R || L > qR || R < qL) return INT_MAX/2;
  if(qL <= L && R <= qR) return dp_tree[i];

  int mid = (L + R)/2;
  return min(query2(L, mid, 2*i + 1, qL, qR), query2(mid + 1, R, 2*i + 2, qL, qR));
}

void update2(int L, int R, int i, int x, int v) {
  if(L == R) {
    dp_tree[i] = v;
    return;
  }

  int mid = (L + R)/2;
  if(x <= mid) {
    update2(L, mid, 2*i + 1, x, v);
  }
  else {
    update2(mid + 1, R, 2*i + 2, x, v);
  }
  dp_tree[i] = min(dp_tree[2*i + 1], dp_tree[2*i + 2]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, S, L; cin >> N >> S >> L;
  for(int i = 0; i < N; i++) cin >> A[i];

  build_tree(0, N - 1, 0);

  for(int i = 0; i < 4*N; i++) dp_tree[i] = INT_MAX/2;

  dp[N] = 0;
  update2(0, N, 0, N, dp[N]);

  for(int i = N - 1; i >= 0; i--) {
    if(i + L > N) dp[i] = INT_MAX/2;
    else {
      int X = i, Y = N - 1;
      while(X < Y) {
        int mid = (X + Y + 1)/2;
        pair<int, int> ans = query(0, N - 1, 0, i, mid);
        if(ans.second - ans.first <= S) {
          X = mid;
        }
        else {
          Y = mid - 1;
        }
      }

      if(X < i + L - 1) dp[i] = INT_MAX/2;
      else {
        dp[i] = 1 + query2(0, N, 0, i + L, X + 1);
      }
    }
    update2(0, N, 0, i, dp[i]);
  }

  if(dp[0] >= INT_MAX/4) dp[0] = -1;
  cout << dp[0] << endl;
}
