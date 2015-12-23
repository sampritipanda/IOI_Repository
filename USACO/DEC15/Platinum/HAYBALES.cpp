#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

#define in cin
#define out cout

struct node {
  long long sum = 0, min = LLONG_MAX/10, lazy = 0;
} segtree[800001];
long long A[200001];

node merge(node L, node R) {
  node N;
  N.sum = L.sum + R.sum;
  N.min = min(L.min, R.min);
  N.lazy = 0;

  return N;
}

void propagate(int L, int R, int i) {
  long long lazy = segtree[i].lazy;
  if(lazy == 0) return;

  segtree[i].sum += lazy * (R - L + 1);
  segtree[i].min += lazy;

  if(L != R) {
    segtree[2*i + 1].lazy += lazy;
    segtree[2*i + 2].lazy += lazy;
  }

  segtree[i].lazy = 0;
}

void build(int L, int R, int i) {
  if(L == R) {
    segtree[i].sum = A[L];
    segtree[i].min = A[L];
    segtree[i].lazy = 0;

    return;
  }

  int mid = (L + R) >> 1;
  build(L, mid, 2*i + 1);
  build(mid + 1, R, 2*i + 2);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

node query(int L, int R, int i, int A, int B) {
  propagate(L, R, i);

  if(L > B || R < A) return node();

  if(A <= L && R <= B) {
    return segtree[i];
  }

  int mid = (L + R) >> 1;
  return merge(query(L, mid, 2*i + 1, A, B), query(mid + 1, R, 2*i + 2, A, B));
}

void update(int L, int R, int i, int A, int B, int C) {
  propagate(L, R, i);

  if(L > B || R < A) return;

  if(A <= L && R <= B) {
    segtree[i].lazy += C;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R) >> 1;
  update(L, mid, 2*i + 1, A, B, C);
  update(mid + 1, R, 2*i + 2, A, B, C);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

int main() {
  ifstream in("haybales.in");
  ofstream out("haybales.out");

  int N, Q; in >> N >> Q;
  for(int i = 1; i <= N; i++) in >> A[i];

  build(1, N, 0);

  while(Q--) {
    char type; in >> type;
    int A, B; in >> A >> B;

    if(type == 'M') {
      out << query(1, N, 0, A, B).min << endl;
    }
    else if(type == 'S') {
      out << query(1, N, 0, A, B).sum << endl;
    }
    else {
      int C; in >> C;
      update(1, N, 0, A, B, C);
    }
  }
}
