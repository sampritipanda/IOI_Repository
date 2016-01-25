#include <iostream>
#include <algorithm>

using namespace std;

struct node {
  int max;
  int lazy = 0;
};

node segtree[800000];
int A[200000];

void propagate(int L, int R, int i) {
  if(segtree[i].lazy != 0) {
    segtree[i].max += segtree[i].lazy;
    if(L < R) {
      segtree[2*i + 1].lazy += segtree[i].lazy;
      segtree[2*i + 2].lazy += segtree[i].lazy;
    }
    segtree[i].lazy = 0;
  }
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].max = A[L] + L;
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i].max = max(segtree[2*i + 1].max, segtree[2*i + 2].max);
}

void update(int L, int R, int A, int B, int i, int d) {
  propagate(L, R, i);

  if(L > B || R < A) return;

  if(A <= L && R <= B) {
    segtree[i].lazy += d;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, A, B, 2*i + 1, d);
  update(mid + 1, R, A, B, 2*i + 2, d);
  segtree[i].max = max(segtree[2*i + 1].max, segtree[2*i + 2].max);
}

int query(int N) {
  propagate(0, N - 1, 0);
  return segtree[0].max;
}

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  build_tree(0, N - 1, 0);

  for(int i = N - 1; i >= 0; i--) {
    cout << query(N) + 1 << " ";

    update(0, N - 1, 0, N - 1, 0, 1);
    update(0, N - 1, i, i, 0, -N);
  }
  cout << endl;
}
