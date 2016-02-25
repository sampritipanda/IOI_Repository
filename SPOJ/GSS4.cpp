#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
  long long sum = 0;
  int one_count = 0;
};

long long A[100001];
node segtree[400004];

node merge(node L, node R) {
  node N;
  N.sum = L.sum + R.sum;
  N.one_count = L.one_count + R.one_count;
  return N;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].sum = A[L];
    segtree[i].one_count = (A[L] == 1);
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1); build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

void update(int L, int R, int i, int qL, int qR) {
  if(R < qL || L > qR) return;
  if(segtree[i].one_count == R - L + 1) return;

  if(L == R) {
    segtree[i].sum = floor(sqrt(segtree[i].sum));
    if(segtree[i].sum == 1) segtree[i].one_count = 1;
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR); update(mid + 1, R, 2*i + 2, qL, qR);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

node query(int L, int R, int i, int qL, int qR) {
  if(R < qL || L > qR) return node();

  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return merge(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

int main() {
  int N;
  int case_id = 1;

  while(scanf("%d", &N) != EOF) {
    printf("Case #%d:\n", case_id++);
    for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

    build_tree(1, N, 0);

    int M; scanf("%d", &M);
    while(M--) {
      int t, x, y; scanf("%d %d %d", &t, &x, &y);
      if(x > y) swap(x, y);

      if(t == 0) { // Update
        update(1, N, 0, x, y);
      }
      else { // Query
        printf("%lld\n", query(1, N, 0, x, y).sum);
      }
    }
    printf("\n");
  }
}
