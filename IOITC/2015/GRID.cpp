#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

struct query {
  int x1, y1, x2, y2;
  int type, i;
};

bool operator<(const query& A, const query& B) {
  return A.i < B.i;
}

set<pair<int, pair<query, int> > > coords;  // {x_coord, {query obj, (0=start, 1=end)
int ans[100000];

namespace SegmentTree {
  pair<int, int> segtree[800008];
  int lazy[800008];

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
    if(L > qR || R < qL) return {INT_MAX/2, 0};
    propagate(L, R, i);
    if(qL <= L && R <= qR) return segtree[i];

    int mid = (L + R)/2;
    return merge(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, U, Q; cin >> N >> U >> Q;

  for(int i = 0; i < U; i++) {
    query curr;
    cin >> curr.x1 >> curr.y1 >> curr.x2 >> curr.y2;
    curr.type = 0; curr.i = i;

    coords.insert({curr.x1, {curr, 0}});
    coords.insert({curr.x2, {curr, 1}});
  }

  for(int i = 0; i < Q; i++) {
    query curr;
    cin >> curr.x1 >> curr.y1 >> curr.x2 >> curr.y2;
    curr.type = 1; curr.i = i;

    coords.insert({curr.x1, {curr, 0}});
  }

  SegmentTree::build(1, N, 0);

  for(auto it: coords) {
    query curr = it.second.first; int coord_type = it.second.second;

    if(curr.type == 0) {
      SegmentTree::update(1, N, 0, curr.y1, curr.y2, (coord_type == 0) ? 1 : -1);
    }
    else {
      pair<int, int> query_ans = SegmentTree::query(1, N, 0, curr.y1, curr.y2);
      ans[curr.i] = (curr.y2 - curr.y1 + 1) - (query_ans.first == 0 ? query_ans.second : 0);
    }
  }

  for(int i = 0; i < Q; i++) cout << ans[i] << endl;
}
