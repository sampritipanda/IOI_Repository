// Mac vs PC

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;
int M[300005], P[300005];
long long prefix_M[300005], prefix_P[300005];

long long dp_mac[300005];
long long dp_pc[300005];

long long mac_tree[1200025];
long long pc_tree[1200025];

void update(long long* segment_tree, int L, int R, int i, int pos, long long val){
  if(L == R){
    segment_tree[i] = min(segment_tree[i], val);
    return;
  }

  int mid = L + (R - L)/2;
  if(pos <= mid){
    update(segment_tree, L, mid, 2*i + 1, pos, val);
  }
  else {
    update(segment_tree, mid + 1, R, 2*i + 2, pos, val);
  }

  segment_tree[i] = min(segment_tree[2*i + 1], segment_tree[2*i + 2]);
}

long long query(long long* segment_tree, int seg_start, int seg_end, int L, int R, int i){
  if(seg_start > R || seg_end < L) return LLONG_MAX;

  if(L <= seg_start && seg_end <= R) return segment_tree[i];

  int mid = seg_start + (seg_end - seg_start)/2;
  long long left = query(segment_tree, seg_start, mid, L, R, 2*i + 1);
  long long right = query(segment_tree, mid + 1, seg_end, L, R, 2*i + 2);
  return min(left, right);
}

int main() {
  cin >> N >> K;
  K--;

  for(int i = 0; i < N; i++) cin >> M[i];
  for(int i = 0; i < N; i++) cin >> P[i];

  prefix_M[0] = M[0];
  prefix_P[0] = P[0];

  for(int i = 0; i < N; i++) prefix_M[i] = prefix_M[i - 1] + M[i];
  for(int i = 0; i < N; i++) prefix_P[i] = prefix_P[i - 1] + P[i];

  for(int i = 0; i < 1200025; i++) mac_tree[i] = LLONG_MAX;
  for(int i = 0; i < 1200025; i++) pc_tree[i] = LLONG_MAX;

  dp_mac[N] = 0;
  dp_pc[N] = 0;
  update(mac_tree, 0, N + 2, 0, N, prefix_M[N - 1]);
  update(pc_tree, 0, N + 2, 0, N, prefix_P[N - 1]);

  for(int i = N - 1; i >= 0; i--){
    dp_mac[i] = M[i] + min(query(mac_tree, 0, N + 2, i + 1, min(i + K, N), 0) - prefix_M[i], dp_pc[i + 1]);
    dp_pc[i] = P[i] + min(query(pc_tree, 0, N + 2, i + 1, min(i + K, N), 0) - prefix_P[i], dp_mac[i + 1]);
    if(dp_mac[i] == LLONG_MAX) dp_mac[i] = 0;
    if(dp_pc[i] == LLONG_MAX) dp_pc[i] = 0;

    update(mac_tree, 0, N + 2, 0, i, dp_pc[i + 1] + prefix_M[i]);
    update(pc_tree, 0, N + 2, 0, i, dp_mac[i + 1] + prefix_P[i]);
  }

  cout << min(dp_pc[0], dp_mac[0]) << endl;
}
