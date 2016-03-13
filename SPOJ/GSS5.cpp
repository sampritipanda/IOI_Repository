#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

struct node {
  int l_sum = 0, r_sum = 0, sum = 0, ans = INT_MIN;
  bool empty = false;
};

node segtree[100004];
int P[10001];

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

node query(int L, int R, int i, int A, int B) {
  if(A > B) return empty_node();
  if(R < A || L > B) return empty_node();

  if(A <= L && R <= B) return segtree[i];

  int mid = (L + R)/2;
  return merge(query(L, mid, 2*i + 1, A, B), query(mid + 1, R, 2*i + 2, A, B));
}

int main()
{
  int T; scanf("%d", &T);

  while(T--) {
    int N, Q; scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &P[i]);

    for(int i = 0; i <= 100000; i++) segtree[i] = node();

    build_tree(1, N, 0);

    scanf("%d", &Q);

    while(Q--) {
      int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

      int ans = 0;
      if(y1 < x2) {
        ans += query(1, N, 0, y1 + 1, x2 - 1).sum;
        ans += query(1, N, 0, x1, y1).r_sum;
        ans += query(1, N, 0, x2, y2).l_sum;
      }
      else {
        ans = query(1, N, 0, x2, y1).ans;
        ans = max(ans, query(1, N, 0, x1, y1).r_sum + query(1, N, 0, y1 + 1, y2).l_sum);
        ans = max(ans, query(1, N, 0, x2, y2).l_sum + query(1, N, 0, x1, x2 - 1).r_sum);
      }
      printf("%d\n", ans);
    }
  }

  return 0;
}

