#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, K, A[300000];
pair<int, int> segtree[1200001];
int lazy[1200001];
int bit[300001];

void bit_update(int i, int v) {
  i++;
  while(i <= N) {
    bit[i] += v;
    i += i & -i;
  }
}

int bit_query(int i) {
  i++;
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

int bit_query(int L, int R) {
  if(L == 0) return bit_query(R);
  return bit_query(R) - bit_query(L - 1);
}

pair<int, int> merge(pair<int, int> L, pair<int, int> R) {
  if(L.first >= R.first) return L;
  return R;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = make_pair(A[L], L);
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

void propagate(int L, int R, int i) {
  if(lazy[i] == 0) return;

  segtree[i].first += lazy[i];
  if(L < R) {
    lazy[2*i + 1] += lazy[i];
    lazy[2*i + 2] += lazy[i];
  }
  lazy[i] = 0;
}

void update(int L, int R, int i, int qL, int qR) {
  if(qL <= L && R <= qR) {
    lazy[i] += 1;
    propagate(L, R, i);
    return;
  }

  propagate(L, R, i);
  if(L > qR || R < qL) return;

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR);
  update(mid + 1, R, 2*i + 2, qL, qR);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

void change_update(int L, int R, int i, int x, int v) {
  propagate(L, R, i);
  if(x < L || x > R) return;
  if(L == R) {
    segtree[i] = make_pair(v, x);
    return;
  }

  int mid = (L + R)/2;
  change_update(L, mid, 2*i + 1, x, v);
  change_update(mid + 1, R, 2*i + 2, x, v);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

pair<int, int> query(int L, int R, int i, int qL, int qR) {
  if(L > qR || R < qL) return make_pair(INT_MIN/2, N + 1);
  propagate(L, R, i);
  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return merge(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

void inicjuj(int n, int k, int *D) {
  N = n, K = k;
  for (int i = 0; i < n; ++i) {
    A[i] = D[i];
    if(A[i] >= K) {
      bit_update(i, 1);
      A[i] = INT_MIN/2;
    }
  }
  build_tree(0, N - 1, 0);
}

void podlej(int a, int b) {
  update(0, N - 1, 0, a, b);
  while(true) {
    pair<int, int> curr = query(0, N - 1, 0, a, b);
    if(curr.first < K) break;
    change_update(0, N - 1, 0, curr.second, INT_MIN/2);
    bit_update(curr.second, 1);
  }
}

int dojrzale(int a, int b) {
  return bit_query(a, b);
}
