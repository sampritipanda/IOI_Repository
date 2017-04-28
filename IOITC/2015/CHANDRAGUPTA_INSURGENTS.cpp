#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

namespace SegmentTree {
  pair<int, int> segtree[400004];
  int lazy[400004];

  pair<int, int> merge(pair<int, int> L, pair<int, int> R) {
    if(L.first == R.first) return {L.first, L.second + R.second};
    if(L.first < R.first) return L;
    return R;
  }

  void propagate(int L, int R, int i) {
    if(lazy[i] == 0) return;

    segtree[i].first += lazy[i];

    if(L != R) {
      lazy[2*i + 1] += lazy[i];
      lazy[2*i + 2] += lazy[i];
    }
    lazy[i] = 0;
  }

  void build(int L, int R, int i) {
    lazy[i] = 0;
    if(L == R) {
      segtree[i] = {0, 1};
      return;
    }

    int mid = (L + R)/2;
    build(L, mid, 2*i + 1);
    build(mid + 1, R, 2*i + 2);
    segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
  }

  void update(int L, int R, int i, int qL, int qR, int v) {
    propagate(L, R, i);
    if(L > qR || R < qL) return;
    if(qL <= L && R <= qR) {
      lazy[i] += v;
      propagate(L, R, i);
      return;
    }

    int mid = (L + R)/2;
    update(L, mid, 2*i + 1, qL, qR, v);
    update(mid + 1, R, 2*i + 2, qL, qR, v);
    segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
  }

  pair<int, int> query(int L, int R, int i, int qL, int qR) {
    propagate(L, R, i);
    if(L > qR || R < qL) return {INT_MAX/2, 0};
    if(qL <= L && R <= qR) return segtree[i];

    int mid = (L + R)/2;
    return merge(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
  }
};


int main() {
  int N, M, Q; scanf("%d %d %d", &N, &M, &Q);

  SegmentTree::build(1, N, 0);

  while(M--) {
    int u, v; scanf("%d %d", &u, &v);
    if(u > v) swap(u, v);
    v--;
    SegmentTree::update(1, N, 0, u, v, 1);
  }

  while(Q--) {
    int t, u, v; scanf("%d %d %d", &t, &u, &v);
    if(u > v) swap(u, v);
    v--;

    if(t == 0) {
      SegmentTree::update(1, N, 0, u, v, 1);
    }
    else if(t == 1) {
      SegmentTree::update(1, N, 0, u, v, -1);
    }
    else {
      pair<int, int> query_ans = SegmentTree::query(1, N, 0, u, v);
      printf("%d\n", (query_ans.first == 0 ? query_ans.second : 0));
    }
  }
}
