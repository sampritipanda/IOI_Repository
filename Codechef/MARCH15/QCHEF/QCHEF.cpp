// Chef and Problems

#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

void insertST(int* segment_tree, int L, int R, int pos, int val, int i){
  if(pos < L || pos > R) return;

  segment_tree[i] = max(segment_tree[i], val);
  if(L == R) return;
  int mid = (L + R)/2;
  if(pos <= mid) insertST(segment_tree, L, mid, pos, val, 2 * i + 1);
  else insertST(segment_tree, mid + 1, R, pos, val, 2 * i + 2);
}

int queryMax(int* segment_tree, int L, int R, int q_L, int q_R, int i){
  if(q_L <= L && q_R >= R) return segment_tree[i];
  if(R < q_L || L > q_R) return -1;

  int mid = (L + R)/2;
  int left = queryMax(segment_tree, L, mid, q_L, q_R, 2 * i + 1);
  int right = queryMax(segment_tree, mid + 1, R, q_L, q_R, 2 * i + 2);

  return max(left, right);
}

int main() {
  int N, M, K; scanf("%d %d %d", &N, &M, &K);
  vector<pair<int, int> > queries[N];
  int ans[K];
  int A[N];
  vector<int> positions[M + 1];
  int size = 2 * int(pow(2, ceil(log2(N)))) - 1;
  int* segment_tree = new int[size];
  for(int i = 0; i < size; i++) segment_tree[i] = -1;

  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    positions[A[i]].push_back(i);
  }
  for(int i = 0; i < K; i++){
    int L, R; scanf("%d %d", &L, &R);
    queries[R - 1].push_back({L - 1, i});
  }

  map<int, int> backlog;
  for(int i = 0; i < N; i++){
    if(queries[i].empty()) backlog[A[i]] = i;
    else {
      backlog[A[i]] = i;
      for(auto jit: backlog) {
        for(auto it: positions[jit.first]) {
          if(it == jit.second) break;
          insertST(segment_tree, 0, N - 1, it, jit.second - it, 0);
        }
      }
      backlog.clear();

      for(auto q: queries[i]){
        int max_dist = queryMax(segment_tree, 0, N - 1, q.first, i, 0);
        if(max_dist == -1) max_dist = 0;
        ans[q.second] = max_dist;
      }
    }
  }

  for(int i = 0; i < K; i++) printf("%d\n", ans[i]);
}
