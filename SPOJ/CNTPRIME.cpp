// Counting Primes

#include <stdio.h>
#include <cmath>

using namespace std;

bool sieve[1000005];
int segment_tree[400001];
int flip[400001];

void refresh(int i, int L, int R){
  if(flip[i] != 0){
    if(sieve[flip[i]]){
      segment_tree[i] = R - L + 1;
    }
    else {
      segment_tree[i] = 0;
    }

    if(L != R) {
      flip[2*i + 1] = flip[i];
      flip[2*i + 2] = flip[i];
    }

    flip[i] = 0;
  }
}

int constructST(int A[], int L, int R, int i){
  if(L == R){
    segment_tree[i] = sieve[A[L]];
    return segment_tree[i];
  }

  int mid = L + (R - L)/2;
  segment_tree[i] = constructST(A, L, mid, 2*i + 1) + constructST(A, mid + 1, R, 2*i + 2);
  return segment_tree[i];
}

void updateST(int seg_start, int seg_end, int L, int R, int v, int i){
  refresh(i, seg_start, seg_end);

  if(seg_end < L || seg_start > R){
    return;
  }

  if(seg_start >= L && seg_end <= R){
    flip[i] = v;
    refresh(i, seg_start, seg_end);
    return;
  }

  if(seg_start != seg_end) {
    int mid = seg_start + (seg_end - seg_start)/2;
    updateST(seg_start, mid, L, R, v, 2*i + 1);
    updateST(mid + 1, seg_end, L, R, v, 2*i + 2);
    segment_tree[i] = segment_tree[2*i + 1] + segment_tree[2*i + 2];
  }
}

int queryST(int seg_start, int seg_end, int L, int R, int i){
  if(seg_end < L || seg_start > R) return 0;

  refresh(i, seg_start, seg_end);
  if(L <= seg_start && seg_end <= R) {
    return segment_tree[i];
  }

  int mid = seg_start + (seg_end - seg_start)/2;
  return queryST(seg_start, mid, L, R, 2*i + 1) + queryST(mid + 1, seg_end, L, R, 2*i + 2);
}

int main() {
  for(int i = 0; i <= 1000000; i++) sieve[i] = true;
  sieve[0] = sieve[1] = false;
  for(int i = 2; i <= 1000000; i++){
    if(!sieve[i]) continue;
    for(int j = i*2; j <= 1000000; j += i) sieve[j] = false;
  }

  int T; scanf("%d", &T);

  for(int i = 1; i <= T; i++) {
    printf("Case %d:\n", i);
    int N, Q; scanf("%d %d", &N, &Q);
    int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);

    for(int i = 0; i <= 400000; i++) flip[i] = 0;
    for(int i = 0; i <= 400000; i++) segment_tree[i] = 0;
    constructST(A, 0, N - 1, 0);

    while(Q--){
      int type, x, y; scanf("%d %d %d", &type, &x, &y);
      x--; y--;

      if(type == 0){
        int v; scanf("%d", &v);
        updateST(0, N - 1, x, y, v, 0);
      }
      else {
        printf("%d\n", queryST(0, N - 1, x, y, 0));
      }
    }
  }
}
