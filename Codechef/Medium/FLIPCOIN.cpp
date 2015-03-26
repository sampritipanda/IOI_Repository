// Gcd Queries

#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

bool flip[400005];

int* constructST(int N){
  int height = int(ceil(log2(N)));
  int size = 2 * int(pow(2, height)) - 1;

  int* segment_tree = new int[size];
  for(int i = 0; i < size; i++) segment_tree[i] = 0;
  for(int i = 0; i < size; i++) flip[i] = false;

  return segment_tree;
}

void update_ST(int* segment_tree, int seg_start, int seg_end, int L, int R, int i){
  if(flip[i]){
    segment_tree[i] = (seg_end - seg_start + 1) - segment_tree[i];
    if(seg_start != seg_end){
      flip[2*i + 1] = !flip[2*i + 1];
      flip[2*i + 2] = !flip[2*i + 2];
    }

    flip[i] = false;
  }

  if(seg_end < L || seg_start > R){
    return;
  }

  if(seg_start >= L && seg_end <= R){
    segment_tree[i] = (seg_end - seg_start + 1) - segment_tree[i];
    if(seg_start != seg_end) {
      flip[2*i + 1] = !flip[2*i + 1];
      flip[2*i + 2] = !flip[2*i + 2];
    }
    return;
  }

  if(seg_start != seg_end){
    int mid = seg_start + (seg_end - seg_start)/2;
    update_ST(segment_tree, seg_start, mid, L, R, 2*i + 1);
    update_ST(segment_tree, mid + 1, seg_end, L, R, 2*i + 2);
    segment_tree[i] = segment_tree[2*i + 1] + segment_tree[2*i + 2];
  }
}

int get_range_sum(int segment_tree[], int seg_start, int seg_end, int L, int R, int i){
  if(seg_end < L || seg_start > R){
    return 0;
  }

  if(flip[i]){
    segment_tree[i] = (seg_end - seg_start + 1) - segment_tree[i];
    if(seg_start != seg_end) {
      flip[2*i + 1] = !flip[2*i + 1];
      flip[2*i + 2] = !flip[2*i + 2];
    }
    flip[i] = false;
  }

  if(L <= seg_start && seg_end <= R){
    return segment_tree[i];
  }

  int mid = seg_start + (seg_end - seg_start)/2;

  int left = get_range_sum(segment_tree, seg_start, mid, L, R, 2*i + 1);
  int right = get_range_sum(segment_tree, mid + 1, seg_end, L, R, 2*i + 2);
  return left + right;
}

int main() {
  int N, Q; scanf("%d %d", &N, &Q);

  int* segment_tree = constructST(N);

  for(int i = 0; i < Q; i++){
    int type, L, R; scanf("%d %d %d", &type, &L, &R);

    if(type == 0){
      update_ST(segment_tree, 0, N - 1, L, R, 0);
    }
    else {
      printf("%d\n", get_range_sum(segment_tree, 0, N - 1, L, R, 0));
    }
  }
}
