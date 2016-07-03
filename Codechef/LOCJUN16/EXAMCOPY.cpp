#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
  int val, cnt;

  node(int _val = 0, int _cnt = 0) {
    val = _val;
    cnt = _cnt;
  }
};

int K[100001];
node segtree[400001];

node merge(node L, node R) {
  if(L.val == R.val) {
    return node(L.val, L.cnt + R.cnt);
  }
  if(L.val > R.val) return L;
  else return R;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = node(K[L], 1);
    return;
  }

  int mid = (L + R) >> 1;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

node query(int L, int R, int i, int A, int B) {
  if(L > R || R < A || L > B) return node();

  if(A <= L && R <= B) return segtree[i];

  int mid = (L + R) >> 1;
  return merge(query(L, mid, 2*i + 1, A, B), query(mid + 1, R, 2*i + 2, A, B));
}

int prv[100002], nxt[100002];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 1; i <= N; i++) cin >> K[i];

  build_tree(1, N, 0);

  for(int i = 1; i <= N + 1; i++) prv[i] = N + 1;
  for(int i = 0; i <= N; i++) nxt[i] = 0;

  while(M--) {
    int L, R; cin >> L >> R;
    prv[R] = min(prv[R], L);
    nxt[L] = max(nxt[L], R);
  }

  for(int i = N; i >= 1; i--) prv[i] = min(prv[i], prv[i + 1]);
  for(int i = 1; i <= N; i++) nxt[i] = max(nxt[i], nxt[i - 1]);

  int D; cin >> D;

  for(int i = 1; i <= N; i++) {
    int L = min(prv[i], i + 1);
    int R = max(nxt[i], i - 1);

    node X = query(1, N, 0, i - D, L - 1);
    node Y = query(1, N, 0, R + 1, i + D);
    node ans = merge(X, Y);
    if(ans.val <= K[i]) cout << -1 << endl;
    else cout << ans.val << " " << ans.cnt << endl;
  }
}
