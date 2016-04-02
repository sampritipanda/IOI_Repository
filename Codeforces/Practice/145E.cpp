#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

char S[1000001];
int A[1000001];

struct node {
  int inc_4 = 0;  // a_i <= a_i+1   start with 4
  int inc_7 = 0;  // <= start 4,  == count(7)
  int dec_4 = 0;  // a_i >= a_i+1   start with 5,  == count(4)
  int dec_7 = 0;  // >= start 7
};

int lazy[4000004];
node segtree[4000004];

node merge(node L, node R) {
  node N;

  N.inc_4 = max(L.inc_4, R.inc_4);
  N.inc_4 = max(N.inc_4, L.inc_4 + R.inc_7);
  N.inc_4 = max(N.inc_4, L.dec_4 + R.inc_4);

  N.inc_7 = L.inc_7 + R.inc_7;

  N.dec_4 = L.dec_4 + R.dec_4;

  N.dec_7 = max(L.dec_7, R.dec_7);
  N.dec_7 = max(N.dec_7, L.dec_7 + R.dec_4);
  N.dec_7 = max(N.dec_7, L.inc_7 + R.dec_7);

  return N;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    if(A[L] == 4) {
      segtree[i].inc_4 = 1;
      segtree[i].dec_4 = segtree[i].dec_7 = 1;
    }
    else {
      segtree[i].inc_4 = segtree[i].inc_7 = 1;
      segtree[i].dec_7 = 1;
    }
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1); build_tree(mid + 1, R, 2*i + 2);

  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

void propagate(int L, int R, int i) {
  if(lazy[i] % 2 == 1) {
    swap(segtree[i].inc_4, segtree[i].dec_7);
    swap(segtree[i].dec_4, segtree[i].inc_7);
  }

  if(L != R) {
    lazy[2*i + 1] += lazy[i];
    lazy[2*i + 2] += lazy[i];
  }

  lazy[i] = 0;
}

void update(int L, int R, int i, int qL, int qR) {
  propagate(L, R, i);

  if(L > R) return;
  if(L > qR || R < qL) return;

  if(qL <= L && R <= qR) {
    lazy[i] += 1;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR);
  update(mid + 1, R, 2*i + 2, qL, qR);

  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

int main() {
  int N, M; scanf("%d %d", &N, &M);

  scanf(" %s", S);
  for(int i = 1; i <= N; i++) A[i] = S[i - 1] - '0';

  build_tree(1, N, 0);

  char type[100];
  while(M--) {
    scanf(" %s", type);

    if(type[0] == 'c') {
      printf("%d\n", segtree[0].inc_4);
    }
    else {
      int L, R; scanf(" %d %d", &L, &R);
      update(1, N, 0, L, R);
    }
  }
}
