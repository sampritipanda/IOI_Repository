// Gcd Queries

#include <stdio.h>
#include <cmath>

using namespace std;

int gcd(int a, int b){
  if(b == 0) return a;
  else return gcd(b, a % b);
}

int constructSTRecur(int A[], int L, int R, int* segment_tree, int i){
  if(L == R){
    segment_tree[i] = A[L];
    return A[L];
  }

  int mid = L + (R - L)/2;

  int val1 = constructSTRecur(A, L, mid, segment_tree, i*2 + 1);
  int val2 = constructSTRecur(A, mid+1, R, segment_tree, i*2 + 2);
  segment_tree[i] = gcd(val1, val2);

  return segment_tree[i];
}

int* constructST(int A[], int N){
  int height = int(ceil(log2(N)));
  int size = 2 * int(pow(2, height)) - 1;

  int* segment_tree = new int[size];
  constructSTRecur(A, 0, N - 1, segment_tree, 0);

  return segment_tree;
}

int get_range_gcd(int segment_tree[], int seg_start, int seg_end, int L, int R, int i){
  if(L <= seg_start && seg_end <= R){
    return segment_tree[i];
  }

  if(seg_end < L || seg_start > R){
    return 0;
  }

  int mid = seg_start + (seg_end - seg_start)/2;

  return gcd(get_range_gcd(segment_tree, seg_start, mid, L, R, 2*i + 1), get_range_gcd(segment_tree, mid + 1, seg_end, L, R, 2*i + 2));
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N, Q; scanf("%d %d", &N, &Q);
    int A[N];

    for(int i = 0; i < N; i++) scanf("%d", &A[i]);

    int* segment_tree = constructST(A, N);

    for(int i = 0; i < Q; i++){
      int L, R; scanf("%d %d", &L, &R);
      L--; R--;

      int gcd_result = 0;
      if(L == 1) gcd_result = A[0];
      else if(L > 1) gcd_result = get_range_gcd(segment_tree, 0, N - 1, 0, L - 1, 0);

      if(R == N - 2) gcd_result = gcd(A[N - 1], gcd_result);
      else if(R < N - 2) gcd_result = gcd(get_range_gcd(segment_tree, 0, N - 1, R + 1, N - 1, 0), gcd_result);

      printf("%d\n", gcd_result);
    }
  }
}
