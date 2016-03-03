#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int A[30001];
int segtree[200001];
int lazy[200001];

void propagate(int L, int R, int i) {
  if(lazy[i] != 0) {
    segtree[i] += lazy[i];
    if(L != R) {
      lazy[2*i + 1] += lazy[i];
      lazy[2*i + 2] += lazy[i];
    }
    lazy[i] = 0;
  }
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = A[L];
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1); build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

void update(int L, int R, int i, int qL, int qR, int val) {
  propagate(L, R, i);

  if(L > qR || R < qL) return;

  if(qL <= L && R <= qR) {
    lazy[i] += val;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, val);
  update(mid + 1, R, 2*i + 2, qL, qR, val);
  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

int query(int L, int R, int i, int qL, int qR) {
  propagate(L, R, i);

  if(L > qR || R < qL) return INT_MAX;
  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return min(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);

  for(int t = 1; t <= 10; t++) {
    memset(A, 0, sizeof A); memset(segtree, 0, sizeof segtree); memset(lazy, 0, sizeof lazy);

    cout << "Test " << t << ":" << endl;
    int N; cin >> N;
    string S; cin >> S;

    A[0] = 0;
    for(int i = 0; i < N; i++) {
      if(S[i] == '(') {
        A[i + 1] = A[i] + 1;
      }
      else {
        A[i + 1] = A[i] - 1;
      }
    }

    build_tree(1, N, 0);

    int M; cin >> M;
    while(M--) {
      int k; cin >> k;
      if(k == 0) {
        int min_all = query(1, N, 0, 1, N);
        int final_sum = query(1, N, 0, N, N);

        if(min_all == 0 && final_sum == 0) {
          cout << "YES" << endl;
        }
        else {
          cout << "NO" << endl;
        }
      }
      else {
        int curr_val = query(1, N, 0, k, k);
        if(k > 1) curr_val -= query(1, N, 0, k - 1, k - 1);

        update(1, N, 0, k, N, -curr_val - curr_val);
      }
    }
  }
}
