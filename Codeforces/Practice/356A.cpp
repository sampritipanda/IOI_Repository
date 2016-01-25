#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int segtree[2000000];
int lazy[2000000];
int A[300000];

void propagate(int L, int R, int i) {
  if(lazy[i] != INT_MAX) {
    segtree[i] = min(segtree[i], lazy[i]);
    if(L != R) {
      lazy[2*i + 1] = min(lazy[2*i + 1], lazy[i]);
      lazy[2*i + 2] = min(lazy[2*i + 2], lazy[i]);
    }
    lazy[i] = INT_MAX;
  }
}

int query(int L, int R, int A, int B, int i) {
  propagate(L, R, i);

  if(L > R) return INT_MAX;
  if(A > R || B < L) return INT_MAX;

  if(A <= L && R <= B) return segtree[i];

  int mid = (L + R)/2;
  return min(query(L, mid, A, B, 2*i + 1), query(mid + 1, R, A, B, 2*i + 2));
}

void range_update(int L, int R, int A, int B, int i, int val) {
  propagate(L, R, i);

  if(L > R) return;
  if(A > R || B < L) return;

  if(A <= L && R <= B) {
    lazy[i] = val;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  range_update(L, mid, A, B, 2*i + 1, val);
  range_update(mid + 1, R, A, B, 2*i + 2, val);
  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

void set_val(int L, int R, int i, int pos, int val) {
  propagate(L, R, i);

  if(L == R) {
    segtree[i] = val;
    return;
  }

  segtree[i] = min(segtree[i], val);
  int mid = (L + R)/2;
  if(pos <= mid) {
    set_val(L, mid, 2*i + 1, pos, val);
  }
  else {
    set_val(mid + 1, R, 2*i + 2, pos, val);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 0; i <= 4*N; i++) {
    segtree[i] = INT_MAX;
    lazy[i] = INT_MAX;
  }

  for(int t = 0; t < M; t++) {
    int L, R, X; cin >> L >> R >> X;

    A[t] = X;
    range_update(1, N, L, R, 0, t);
    set_val(1, N, 0, X, INT_MAX);
  }

  for(int i = 1; i <= N; i++) {
    int val = query(1, N, i, i, 0);
    int ans = 0;
    if(val != INT_MAX) ans = A[val];

    cout << ans << " ";
  }
  cout << endl;
}

