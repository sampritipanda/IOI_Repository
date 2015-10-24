// Xenia and Bit Operations

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

struct node {
  int layer, val;
};

int A[1 << 17];
node segtree[4 * (1 << 17) + 1];

node merge(node left, node right) {
  assert(left.layer == right.layer);

  node n;
  n.layer = left.layer + 1;
  if(n.layer % 2 == 1) {
    n.val = left.val | right.val;
  }
  else {
    n.val = left.val ^ right.val;
  }

  return n;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    node n;
    n.val = A[L];
    n.layer = 0;
    segtree[i] = n;

    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1); build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

void update(int L, int R, int i, int ind, int val) {
  if(L == R) {
    segtree[i].val = val;
    return;
  }

  int mid = (L + R)/2;
  if(ind <= mid) {
    update(L, mid, 2*i + 1, ind, val);
  }
  else {
    update(mid + 1, R, 2*i + 2, ind, val);
  }

  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

int main() {
  int N, M; cin >> N >> M;
  for(int i = 0; i < (1 << N); i++) cin >> A[i];

  build_tree(0, (1 << N) - 1, 0);

  while(M--) {
    int p, b; cin >> p >> b; p--;
    update(0, (1 << N) - 1, 0, p, b);

    cout << segtree[0].val << endl;
  }
}
