#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

struct node {
  int a_0, a_1;
  int r_0, r_1;
  int L, R;

  node() {
    a_0 = a_1 = 0;
    r_0 = r_1 = 0;
    L = R = 0;
  }
};

int X[200001];
int Y[200001];
node segtree[1000001];
int N;

node merge(node L, node R) {
  node N;
  N.L = L.L; N.R = R.R;
  N.r_0 = N.r_1 = INT_MAX;
  if(L.a_0) {
    if(L.r_0 <= X[R.L] && R.a_0) {
      N.a_0 = 1; N.r_0 = min(N.r_0, R.r_0);
    }
    if(L.r_0 <= Y[R.L] && R.a_1) {
      N.a_0 = 1; N.r_0 = min(N.r_0, R.r_1);
    }
  }
  if(L.a_1) {
    if(L.r_1 <= X[R.L] && R.a_0) {
      N.a_1 = 1; N.r_1 = min(N.r_1, R.r_0);
    }
    if(L.r_1 <= Y[R.L] && R.a_1) {
      N.a_1 = 1; N.r_1 = min(N.r_1, R.r_1);
    }
  }
  return N;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].a_0 = segtree[i].a_1 = 1;
    segtree[i].r_0 = X[L]; segtree[i].r_1 = Y[L];
    segtree[i].L = segtree[i].R = L;
    return;
  }

  int mid = (L + R)/2;

  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);

  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

void update(int L, int R, int i, int x) {
  if(L == R) {
    segtree[i].r_0 = X[L];
    segtree[i].r_1 = Y[L];
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
  scanf("%d", &N);

  for(int i = 1; i <= N; i++) scanf("%d %d", &X[i], &Y[i]);

  build_tree(1, N, 0);

  int M; scanf("%d", &M);

  while(M--) {
    int a, b; scanf("%d %d", &a, &b);

    int X_a = X[a], Y_a = Y[a];
    X[a] = X[b]; Y[a] = Y[b];
    update(1, N, 0, a);
    X[b] = X_a; Y[b] = Y_a;
    update(1, N, 0, b);

    if(segtree[0].a_0 || segtree[0].a_1) printf("TAK\n");
    else printf("NIE\n");
  }
}
