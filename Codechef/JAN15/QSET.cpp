// Queries on the String

#include <stdio.h>
#include <cmath>

struct node {
  int count[3] = {0};
  int digit_sum = 0;
};

node merge_nodes(node left, node right){
  node parent;
  parent.digit_sum = (left.digit_sum + right.digit_sum) % 3;

  for(int i = 0; i < 3; i++){
    parent.count[i] += left.count[i];
    parent.count[(i + left.digit_sum) % 3] += right.count[i];
  }

  return parent;
}

unsigned long long queryUtilST(node curr){
  unsigned long long total_count = 0, count_0 = 1, count_1 = 0, count_2 = 0;

  count_0 += curr.count[0];
  count_1 += curr.count[1];
  count_2 += curr.count[2];

  total_count += (count_0 * (count_0 - 1))/2;
  total_count += (count_1 * (count_1 - 1))/2;
  total_count += (count_2 * (count_2 - 1))/2;

  return total_count;
}

node queryST(node* segment_tree, int seg_start, int seg_end, int L, int R, int i){
  if(L <= seg_start && seg_end <= R){
    return segment_tree[i];
  }

  if(seg_end < L || seg_start > R){
    node def;
    return def;
  }

  int mid = (seg_start + seg_end)/2;
  return merge_nodes(queryST(segment_tree, seg_start, mid, L, R, 2*i + 1), queryST(segment_tree, mid + 1, seg_end, L, R, 2*i + 2));
}

void updateST(int A[], node* segment_tree, int seg_start, int seg_end, int i, int change_index){
  if(seg_start == seg_end){
    node curr;
    curr.digit_sum = A[change_index] % 3;
    curr.count[curr.digit_sum] = 1;

    segment_tree[i] = curr;
  }
  else {
    int mid = (seg_start + seg_end)/2;
    if(change_index <= mid){
      updateST(A, segment_tree, seg_start, mid, 2*i + 1, change_index);
    }
    else{
      updateST(A, segment_tree, mid + 1, seg_end, 2*i + 2, change_index);
    }
    segment_tree[i] = merge_nodes(segment_tree[2*i + 1], segment_tree[2*i + 2]);
  }
}

node constructSTRecur(int A[], node* segment_tree, int L, int R, int i){
  if(L == R){
    node curr;
    curr.digit_sum = A[L] % 3;
    curr.count[curr.digit_sum] = 1;

    segment_tree[i] = curr;
    return segment_tree[i];
  }

  int mid = (L + R)/2;
  segment_tree[i] = merge_nodes(constructSTRecur(A, segment_tree, L, mid, 2*i + 1), constructSTRecur(A, segment_tree, mid + 1, R, 2*i + 2));

  return segment_tree[i];
}

node* constructST(int A[], int N){
  int height = int(ceil(log2(N)));
  int max_size = 2 * int(pow(2, height)) - 1;

  node* segment_tree = new node[max_size];
  constructSTRecur(A, segment_tree, 0, N - 1, 0);

  return segment_tree;
}

int main() {
  int N, M; scanf("%d %d", &N, &M);
  int A[N];

  for(int i = 0; i < N; i++){
    char a; scanf(" %c", &a);
    A[i] = a - '0';
  }

  node* segment_tree = constructST(A, N);

  getchar();

  for(int i = 0; i < M; i++){
    int type; scanf("%d", &type);

    if(type == 1) {
      int X, Y; scanf("%d %d", &X, &Y);
      X--;
      A[X] = Y;
      updateST(A, segment_tree, 0, N - 1, 0, X);
    }
    else {
      int C, D; scanf("%d %d", &C, &D);
      C--; D--;

      unsigned long long count = queryUtilST(queryST(segment_tree, 0, N - 1, C, D, 0));
      printf("%llu\n", count);
    }
  }
}
