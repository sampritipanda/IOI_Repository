#include <cstdio>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

struct node {
  int add;  // Add update
  int rem;  // Remove update

  node() {
    add = 0;
    rem = INT_MAX/2;
  }
};

node segtree[1 << 22];

void _propagate(node N, int j) {
  if(N.add == 0 && N.rem == INT_MAX/2) return;

  node ans = node();
  node L = segtree[j], R = N;

  if(R.rem == INT_MAX/2) {
    ans.rem = L.rem;
    ans.add = max(L.add, R.add);
  }
  else {
    ans.rem = min(L.rem, R.rem);
    ans.add = max(R.add, min(R.rem, L.add));
  }

  segtree[j] = ans;
}

void propagate(int L, int R, int i) {
  if(L < R) {
    _propagate(segtree[i], 2 * i + 1);
    _propagate(segtree[i], 2 * i + 2);

    segtree[i].add = 0;
    segtree[i].rem = INT_MAX/2;
  }
}

void update(int L, int R, int i, int qL, int qR, int t, int v) {
  propagate(L, R, i);

  if(qL <= L && R <= qR) {
    if(L == R) {
      node temp;
      if(t == 1) temp.add = v;
      else temp.rem = v;
      _propagate(temp, i);
    }
    else {
      if(t == 1) segtree[i].add = v;
      else segtree[i].rem = v;
      propagate(L, R, i);
    }
    return;
  }
  if(L > qR || R < qL) return;

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, t, v);
  update(mid + 1, R, 2*i + 2, qL, qR, t, v);
}

void find_ans(int L, int R, int i) {
  propagate(L, R, i);
  if(L == R) {
    printf("%d\n", segtree[i].add);
    return;
  }

  int mid = (L + R)/2;
  find_ans(L, mid, 2*i + 1);
  find_ans(mid + 1, R, 2*i + 2);
}

int main() {
  int N, K; scanf("%d %d", &N, &K);

  while(K--) {
    int t, L, R, h; scanf("%d %d %d %d", &t, &L, &R, &h);
    update(0, N - 1, 0, L, R, t, h);
  }

  find_ans(0, N - 1, 0);
}
