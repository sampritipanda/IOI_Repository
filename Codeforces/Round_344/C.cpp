#include <iostream>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

int A[200001];
int res[200001];
int segtree[800001];
int lazy[800001];
multiset<int> S;

void propagate(int L, int R, int i) {
  if(lazy[i] != -1) {
    segtree[i] = (R - L + 1) * lazy[i];
    if(L != R) {
      lazy[2*i + 1] = lazy[i];
      lazy[2*i + 2] = lazy[i];
    }
    lazy[i] = -1;
  }
}

void update(int L, int R, int i, int qL, int qR, int val) {
  propagate(L, R, i);

  if(L > qR || R < qL) return;
  if(qL <= L && R <= qR) {
    lazy[i] = val;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, val);
  update(mid + 1, R, 2*i + 2, qL, qR, val);

  segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
}

int query(int L, int R, int i, int qL, int qR) {
  propagate(L, R, i);

  if(L > qR || R < qL) return 0;
  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return query(L, mid, 2*i + 1, qL, qR) + query(mid + 1, R, 2*i + 2, qL, qR);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  for(int i = 0; i <= 800000; i++) {
    segtree[i] = 0;
    lazy[i] = -1;
  }

  int N, M; cin >> N >> M;
  for(int i = 1; i <= N; i++) cin >> A[i];

  while(M--) {
    int t, r; cin >> t >> r;

    update(1, N, 0, 1, r, t);
  }

  for(int i = 1; i <= N; i++) res[i] = query(1, N, 0, i, i);

  for(int i = 1; i <= N; i++) S.insert(A[i]);

  for(int i = N; i >= 1; i--) {
    if(res[i] == 0) {
      S.erase(S.find(A[i]));
      continue;
    }
    else if(res[i] == 1) {
      A[i] = *S.rbegin();
      S.erase(S.find(*S.rbegin()));
    }
    else if(res[i] == 2) {
      A[i] = *S.begin();
      S.erase(S.begin());
    }
    else {
      assert(false);
    }
  }

  for(int i = 1; i <= N; i++) cout << A[i] << " "; cout << endl;
}
