#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MOD 10007

struct node {
  // ways for L..R and i color paintings required
  long long ans[21];
  int L, R;
};

long long A[100001], B[100001];
node segtree[400001];
int C;

node merge(node L, node R) {
  node N;
  N.L = L.L, N.R = R.R;

  for(int i = 0; i <= 20; i++) N.ans[i] = 0;

  N.ans[0] = L.ans[0] * R.ans[0];
  for(int i = 1; i <= C; i++) {
  }

  return N;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].ans[0] = (A[L] + B[L]) % MOD;
    segtree[i].ans[1] = A[L] % MOD;
    segtree[i].L = L, segtree[i].R = R;

    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);

  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

void update(int L, int R, int i, int x) {
  if(L == R) {
    segtree[i].ans[0] = (A[L] + B[L]) % MOD;
    segtree[i].ans[1] = A[L] % MOD;
    segtree[i].L = L, segtree[i].R = R;

    return;
  }

  int mid = (L + R)/2;
  if(x <= mid) {
    update(L, mid, 2*i + 1, x);
  }
  else {
    update(mid + 1, R, 2*i + 2, x);
  }

  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N >> C;
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) cin >> B[i];

  build_tree(1, N, 0);

  int Q; cin >> Q;
  while(Q--) {
    int P, a, b; cin >> P >> a >> b;

    // A[P] = a;
    // B[P] = b;
    //
    // update(1, N, 0, P);

    cout << segtree[0].ans[C] << endl;
  }
}
