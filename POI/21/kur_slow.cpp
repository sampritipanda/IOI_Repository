// N lg^2 N solution

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
  int el, cnt;
  int L, R;

  node() {
    el = cnt = L = R = 0;
  }
};

int N;
int A[500001];
node segtree[2000001];
vector<int> ind[500001];

int cnt(int L, int R, int k) {
  return (upper_bound(ind[k].begin(), ind[k].end(), R) - lower_bound(ind[k].begin(), ind[k].end(), L));
}

node merge(node L, node R) {
  if(L.cnt == 0) return R;
  if(R.cnt == 0) return L;

  node N;
  N.L = L.L; N.R = R.R;
  if(L.el == R.el) {
    N.el = L.el;
    N.cnt = L.cnt + R.cnt;
  }
  else {
    int left = L.cnt + cnt(R.L, R.R, L.el);
    int right = cnt(L.L, L.R, R.el) + R.cnt;

    if(left >= right) {
      N.el = L.el;
      N.cnt = left;
    }
    else {
      N.el = R.el;
      N.cnt = right;
    }
  }

  return N;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].el = A[L];
    segtree[i].cnt = 1;
    segtree[i].L = segtree[i].R = L;
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);

  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

node query(int L, int R, int i, int qL, int qR) {
  if(L > qR || R < qL) return node();
  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return merge(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

int main() {
  int M; scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    ind[A[i]].push_back(i);
  }

  build_tree(1, N, 0);

  while(M--) {
    int L, R; scanf("%d %d", &L, &R);

    node ans = query(1, N, 0, L, R);
    if(ans.cnt > (R - L + 1)/2) printf("%d\n", ans.el);
    else printf("0\n");
  }
}

