// Swords of Gilgamesh

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// dp[i][j] = max(dp[i + 1][j], dp[i + T[i]][D[i]], 1 + dp[i + 1][j - 1])
// dp[N][j] = 0

int N;
int T[100000], D[100000];
int dp[100005];
int segment_tree[400020];

void update(int L, int R, int i, int pos, int val){
  if(pos < L || pos > R) return;

  segment_tree[i] = max(segment_tree[i], val);

  if(L != R){
    int mid = L + (R - L)/2;
    update(L, mid, 2*i + 1, pos, val);
    update(mid + 1, R, 2*i + 2, pos, val);
  }
}

int query(int seg_start, int seg_end, int L, int R, int i){
  if(seg_start > R || seg_end < L) return 0;

  if(L <= seg_start && seg_end <= R) return segment_tree[i];

  int mid = seg_start + (seg_end - seg_start)/2;
  int left = query(seg_start, mid, L, R, 2*i + 1);
  int right = query(mid + 1, seg_end, L, R, 2*i + 2);
  return max(left, right);
}

int main() {
  for(int i = 0; i < 400020; i++) segment_tree[i] = 0;

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> T[i] >> D[i];
  }

  dp[N - 1] = 0;
  dp[N] = 0;
  update(0, N + 2, 0, N - 1, N - 2);
  update(0, N + 2, 0, N, N - 1);
  for(int i = N - 2; i >= 0; i--){
    dp[i] = dp[i + 1];
    dp[i] = max(dp[i], query(0, N + 2, i + T[i] + 2, min(i + T[i] + D[i] + 1, N), 0) - (i + T[i]));
    update(0, N + 2, 0, i, dp[i] + i - 1);
  }

  cout << dp[0] << endl;
}
