#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int segtree[400000];
int lazy[400000];
int A[100000];
int B[100000];

void propagate(int L, int R, int i) {
  if(lazy[i] != INT_MAX) {
    segtree[i] = lazy[i];
    if(L != R) {
      lazy[2*i + 1] = lazy[i];
      lazy[2*i + 2] = lazy[i];
    }
    lazy[i] = INT_MAX;
  }
}

void update(int L, int R, int A, int B, int i, int val) {
  propagate(L, R, i);

  if(L > R || L > B || R < A) return;

  if(A <= L && R <= B) {
    lazy[i] = val;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, A, B, 2*i + 1, val);
  update(mid + 1, R, A, B, 2*i + 2, val);
  segtree[i] = INT_MIN; // Mixed Node
}

int query(int L, int R, int i, int pos) {
  propagate(L, R, i);

  if(segtree[i] != INT_MIN) return segtree[i];

  int mid = (L + R)/2;
  if(pos <= mid) return query(L, mid, 2*i + 1, pos);
  else return query(mid + 1, R, 2*i + 2, pos);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  for(int i = 0; i < 4*N; i++) {
    segtree[i] = INT_MAX;   // Original Data
    lazy[i] = INT_MAX;
  }

  while(M--) {
    int t; cin >> t;

    if(t == 1) {
      int x, y, k; cin >> x >> y >> k; x--; y--;
      update(0, N - 1, y, y + k - 1, 0, -(y - x));
    }
    else {
      int x; cin >> x; x--;

      int change = query(0, N - 1, 0, x);
      if(change == INT_MAX) cout << B[x] << endl;
      else cout << A[x + change] << endl;
    }
  }
}
