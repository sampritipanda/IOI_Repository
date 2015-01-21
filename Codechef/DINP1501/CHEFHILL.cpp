// Chef and mountains

#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int queryST(int* segment_tree, int seg_start, int seg_end, int L, int R, int i){
  if(seg_start >= L && seg_end <= R){
    return segment_tree[i];
  }
  if(seg_end < L || seg_start > R){
    return 0;
  }

  int mid = (seg_start + seg_end)/2;
  return max(queryST(segment_tree, seg_start, mid, L, R, 2*i + 1), queryST(segment_tree, mid + 1, seg_end, L, R, 2*i + 2));
}

int constructSTRecur(int A[], int* segment_tree, int L, int R, int i){
  if(L == R){
    segment_tree[i] = A[L];
    return segment_tree[i];
  }

  int mid = (L + R)/2;
  segment_tree[i] = max(constructSTRecur(A, segment_tree, L, mid, 2*i + 1), constructSTRecur(A, segment_tree, mid + 1, R, 2*i + 2));
}

int* contructST(int A[], int N){
  int height = int(ceil(log2(N)));
  int max_size = 2 * int(pow(2, height)) - 1;

  int* segment_tree = new int[max_size];
  constructSTRecur(A, segment_tree, 0, N - 1, 0);

  return segment_tree;
}

int main() {
  int N; scanf("%d", &N);
  int A[N];

  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  int* segment_tree = contructST(A, N);

  int Q; scanf("%d", &Q);
  for(int i = 0; i < Q; i++){
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;

    if(queryST(segment_tree, 0, N - 1, a, b - 1, 0) > A[a]) printf("NO\n");
    else printf("YES\n");
  }
}
