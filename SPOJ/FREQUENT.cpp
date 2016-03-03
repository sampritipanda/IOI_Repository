#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

struct node {
  int lval = INT_MAX, rval = INT_MAX, lmax = 0, rmax = 0, ans = 0, sz = 0;
  bool empty = false;
};

int A[100001];
node segtree[400004];

node empty_node() {
  node N;
  N.empty = true;
  return N;
}

node merge(node L, node R) {
  if(R.empty) return L;
  if(L.empty) return R;

  node N;
  N.ans = max(L.ans, R.ans); N.lval = L.lval; N.rval = R.rval; N.sz = L.sz + R.sz;
  N.lmax = L.lmax; N.rmax = R.rmax;

  if(L.lmax == L.sz && L.rval == R.lval) {
    N.lmax = L.sz + R.lmax;
  }
  if(R.rmax == R.sz && R.lval == L.rval) {
    N.rmax = R.sz + L.rmax;
  }
  N.ans = max(N.ans, max(N.lmax, N.rmax));

  if(L.rval == R.lval) {
    N.ans = max(N.ans, L.rmax + R.lmax);
  }

  return N;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].lval = segtree[i].rval = A[L];
    segtree[i].lmax = segtree[i].rmax = segtree[i].ans = segtree[i].sz = 1;
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1); build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

node query(int L, int R, int i, int qL, int qR) {
  if(L > qR || R < qL) return empty_node();

  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return merge(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

int main() {
  while(true) {
    int N, Q;
    scanf("%d", &N); if(N == 0) break;
    scanf("%d", &Q);

    for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

    build_tree(1, N, 0);

    while(Q--) {
      int i, j; scanf("%d %d", &i, &j);

      printf("%d\n", query(1, N, 0, i, j).ans);
    }
  }
}
