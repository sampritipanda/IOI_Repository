#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

#define MOD 1000000007

struct node {
  long long ans, prod;
  double ans_log, prod_log;

  node() {
    ans = 0; prod = 1;
    ans_log = -1.0; prod_log = 0.0;
  }
};

long long X[500000], Y[500000];
node segtree[2000000];

node merge(node L, node R) {
  node N = L;
  if(N.ans_log < L.prod_log + R.ans_log) {
    N.ans_log = L.prod_log + R.ans_log;
    N.ans = (L.prod * R.ans) % MOD;
  }
  N.prod_log = L.prod_log + R.prod_log;
  N.prod = (L.prod * R.prod) % MOD;

  return N;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].prod = X[L];
    segtree[i].prod_log = log(X[L]);
    segtree[i].ans = (X[L] * Y[L]) % MOD;
    segtree[i].ans_log = log(X[L]) + log(Y[L]);
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

void update(int L, int R, int i, int x) {
  if(L == R) {
    segtree[i].prod = X[L];
    segtree[i].prod_log = log(X[L]);
    segtree[i].ans = (X[L] * Y[L]) % MOD;
    segtree[i].ans_log = log(X[L]) + log(Y[L]);
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

  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> X[i];
  for(int i = 0; i < N; i++) cin >> Y[i];

  build_tree(0, N - 1, 0);

  cout << segtree[0].ans << endl;

  int M; cin >> M;

  while(M--) {
    int t, p; long long val; cin >> t >> p >> val;
    if(t == 1) {
      X[p] = val;
    }
    else {
      Y[p] = val;
    }
    update(0, N - 1, 0, p);

    cout << segtree[0].ans << endl;
  }
}
