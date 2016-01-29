#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

struct node {
  int l_sum = 0, r_sum = 0, sum = 0, ans = INT_MIN;
  bool empty = false;
};

node segtree[200004];
int P[50001];

node empty_node() {
  node N;
  N.empty = true;
  return N;
}

node merge(node L, node R) {
  if(L.empty) return R;
  if(R.empty) return L;

  node N;
  N.l_sum = L.l_sum; N.r_sum = R.r_sum;

  N.ans = max(L.ans, R.ans);
  N.ans = max(N.ans, L.r_sum + R.l_sum);

  N.l_sum = max(N.l_sum, L.sum + R.l_sum);
  N.r_sum = max(N.r_sum, R.sum + L.r_sum);

  N.sum = L.sum + R.sum;

  N.ans = max(N.ans, max(N.l_sum, N.r_sum));
  return N;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].l_sum = segtree[i].r_sum = segtree[i].sum = P[L];
    segtree[i].ans = P[L];
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);

  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

node query(int L, int R, int A, int B, int i) {
  if(R < A || L > B) return empty_node();

  if(A <= L && R <= B) return segtree[i];

  int mid = (L + R)/2;
  return merge(query(L, mid, A, B, 2*i + 1), query(mid + 1, R, A, B, 2*i + 2));
}

void update(int L, int R, int i, int pos, int val) {
  if(L == R) {
    segtree[i].l_sum = segtree[i].r_sum = segtree[i].sum = segtree[i].ans = val;
    return;
  }

  int mid = (L + R)/2;
  if(pos <= mid) {
    update(L, mid, 2*i + 1, pos, val);
  }
  else {
    update(mid + 1, R, 2*i + 2, pos, val);
  }

  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

int main()
{
  int N, Q; scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%d", &P[i]);

  build_tree(1, N, 0);

  scanf("%d", &Q);

  while(Q--) {
    int t, x, y; scanf("%d %d %d", &t, &x, &y);

    if(t == 0) {
      update(1, N, 0, x, y);
    }
    else {
      printf("%d\n", query(1, N, x, y, 0).ans);
    }
  }

  return 0;
}

