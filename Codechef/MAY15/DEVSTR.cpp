// Devu and binary String

#include <iostream>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

int A[100005];
int N, K;

int prefix_0[100005];
int prefix_1[100005];

int dp_0[100005];
int dp_1[100005];

int next_0[100005];
int next_1[100005];

int tree_0[500025];
int tree_1[500025];

void update(int* segment_tree, int L, int R, int i, int pos, int val){
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

int query(int* segment_tree, int seg_start, int seg_end, int L, int R, int i){
  if(seg_start > R || seg_end < L) return INT_MAX;

  if(L <= seg_start && seg_end <= R) return segment_tree[i];

  int mid = seg_start + (seg_end - seg_start)/2;
  int left = query(segment_tree, seg_start, mid, L, R, 2*i + 1);
  int right = query(segment_tree, mid + 1, seg_end, L, R, 2*i + 2);
  return min(left, right);
}

int main() {
  int T; cin >> T;

  while(T--){
    cin >> N >> K;
    K--;

    for(int i = 0; i <= 4 * (N + 5); i++) {
      tree_0[i] = INT_MAX;
      tree_1[i] = INT_MAX;
    }

    string S; cin >> S;
    int A[N]; for(int i = 0; i < N; i++) A[i] = S[i] - '0';

    for(int i = 1; i < N; i++) {
      prefix_0[i] = prefix_0[i - 1] + (A[i] == 1 ? 1 : 0);
      prefix_1[i] = prefix_1[i - 1] + (A[i] == 0 ? 1 : 0);
    }

    dp_0[N] = 0;
    dp_1[N] = 0;
    update(tree_0, 0, N + 2, 0, N, prefix_0[N - 1]);
    update(tree_1, 0, N + 2, 0, N, prefix_1[N - 1]);

    for(int i = N - 1; i >= 0; i--){
      int add_0 = (A[i] == 0 ? 0 : 1);
      int add_1 = (A[i] == 1 ? 0 : 1);

      dp_0[i] = add_0 + min(query(tree_0, 0, N + 2, i + 1, min(i + K, N), 0) - prefix_0[i], dp_1[i + 1]);
      dp_1[i] = add_1 + min(query(tree_1, 0, N + 2, i + 1, min(i + K, N), 0) - prefix_1[i], dp_0[i + 1]);

      if(dp_0[i] == INT_MAX) dp_0[i] = 0;
      if(dp_1[i] == INT_MAX) dp_1[i] = 0;

      next_0[i] = (dp_0[i] == (add_0 + dp_1[i + 1])) ? 1 : 0;
      next_1[i] = (dp_1[i] == (add_1 + dp_0[i + 1])) ? 0 : 1;

      update(tree_0, 0, N + 2, 0, i, dp_1[i + 1] + prefix_0[i]);
      update(tree_1, 0, N + 2, 0, i, dp_0[i + 1] + prefix_1[i]);
    }

    cout << min(dp_0[0], dp_1[0]) << endl;
    int curr = (dp_0[0] <= dp_1[0] ? 0 : 1);
    for(int i = 0; i < N; i++) {
      cout << curr;
      if(curr == 0){
        curr = next_0[i];
      }
      else {
        curr = next_1[i];
      }
    }
    cout << endl;
  }
}
