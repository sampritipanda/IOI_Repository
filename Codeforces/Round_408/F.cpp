#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> queries[300001];
int segtree[1200004];
int changed[300001];
int limit[300001];
int ans[300001];
map<int, int> vis;
bool bit[30];

namespace Calculate {
  void update(int L, int R, int i, int qL, int qR, int v) {
    if(R < qL || L > qR) return;
    if(L == R && changed[L]) return;
    if(qL <= L && R <= qR) {
      segtree[i] = min(segtree[i], v);
      return;
    }

    int mid = (L + R)/2;
    update(L, mid, 2*i + 1, qL, qR, v);
    update(mid + 1, R, 2*i + 2, qL, qR, v);
  }

  int query(int L, int R, int i, int x, int lazy = 1000000001) {
    if(L == R) {
      if(changed[x]) return segtree[i];
      return segtree[i] = min(segtree[i], lazy);
    }

    lazy = min(lazy, segtree[i]);
    int mid = (L + R)/2;
    if(x <= mid) {
      return query(L, mid, 2*i + 1, x, lazy);
    }
    else {
      return query(mid + 1, R, 2*i + 2, x, lazy);
    }
  }
}

namespace Check {
  void build(int L, int R, int i) {
    if(L == R) {
      segtree[i] = limit[L];
      return;
    }

    int mid = (L + R)/2;
    build(L, mid, 2*i + 1);
    build(mid + 1, R, 2*i + 2);
    segtree[i] = max(segtree[2*i + 1], segtree[2*i + 2]);
  }

  int query(int L, int R, int i, int qL, int qR) {
    if(L > qR || R < qL) return -1;
    if(qL <= L && R <= qR) return segtree[i];

    int mid = (L + R)/2;
    return max(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
  }

  void update(int L, int R, int i, int x, int v) {
    if(L == R) {
      segtree[i] = v;
      return;
    }

    int mid = (L + R)/2;
    if(x <= mid) {
      update(L, mid, 2*i + 1, x, v);
    }
    else {
      update(mid + 1, R, 2*i + 2, x, v);
    }
    segtree[i] = max(segtree[2*i + 1], segtree[2*i + 2]);
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 0; i < 4 * N; i++) segtree[i] = 1000000001;

  for(int i = 1; i <= M; i++) {
    int t; cin >> t;
    if(t == 1) {
      int l, r, x; cin >> l >> r >> x;
      queries[i] = {t, l, r, x};
      Calculate::update(1, N, 0, l, r, x);
    }
    else {
      int k, d; cin >> k >> d;
      queries[i] = {t, k, d};
      Calculate::query(1, N, 0, k);
      changed[k] = true;
    }
  }

  for(int i = 1; i <= N; i++) {
    limit[i] = Calculate::query(1, N, 0, i);
  }

  Check::build(1, N, 0);

  bool pos = true;
  for(int i = 1; i <= M; i++) {
    if(queries[i][0] == 1) {
      if(Check::query(1, N, 0, queries[i][1], queries[i][2]) != queries[i][3]) {
        pos = false;
        break;
      }
    }
    else {
      Check::update(1, N, 0, queries[i][1], queries[i][2]);
    }
  }

  if(!pos) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  vis[1000000001] = true;
  vector<pair<int, int> > change;
  for(int i = 1; i <= N; i++) {
    if(vis[limit[i]]) {
      change.push_back({limit[i], i});
    }
    else {
      for(int j = 30; j >= 0; j--) {
        if(limit[i] & (1 << j)) bit[j] = true;
      }
      vis[limit[i]] = true;
    }
  }
  sort(change.begin(), change.end());

  for(auto it = change.rbegin(); it != change.rend(); it++) {
    int i = it->second;
    if(limit[i] == 1000000001) limit[i]--;
    int tmp = 0;
    for(int j = 30; j >= 0; j--) {
      if(!bit[j] && (tmp | (1 << j)) <= limit[i]) {
        tmp |= (1 << j);
        bit[j] = true;
      }
    }
    limit[i] = tmp;
  }

  for(int i = 1; i <= N; i++) cout << limit[i] << " ";
  cout << endl;
}
