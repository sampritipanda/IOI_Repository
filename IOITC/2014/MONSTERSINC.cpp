#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<int> factors[1001];
int segtree[1001][4001];
int lazy[1001][4001];

void propagate(int x, int L, int R, int i) {
  if(lazy[x][i] > 0) {
    segtree[x][i] += (1LL * lazy[x][i] * (R - L + 1)) % MOD;
    segtree[x][i] %= MOD;

    if(L != R) {
      lazy[x][2*i + 1] += lazy[x][i]; lazy[x][2*i + 1] %= MOD;
      lazy[x][2*i + 2] += lazy[x][i]; lazy[x][2*i + 2] %= MOD;
    }

    lazy[x][i] = 0;
  }
}

int query(int x, int L, int R, int i, int qL, int qR) {
  propagate(x, L, R, i);

  if(L > R || L > qR || R < qL) return 0;

  if(qL <= L && R <= qR) return segtree[x][i];

  int mid = (L + R)/2;
  int ans = query(x, L, mid, 2*i + 1, qL, qR) + query(x, mid + 1, R, 2*i + 2, qL, qR);
  return ans % MOD;
}

void update(int x, int L, int R, int i, int qL, int qR, int v) {
  propagate(x, L, R, i);

  if(L > R || L > qR || R < qL) return;

  if(qL <= L && R <= qR) {
    lazy[x][i] += v;
    propagate(x, L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(x, L, mid, 2*i + 1, qL, qR, v);
  update(x, mid + 1, R, 2*i + 2, qL, qR, v);

  segtree[x][i] = (segtree[x][2*i + 1] + segtree[x][2*i + 2]) % MOD;
}

int main() {
  for(int i = 1; i <= 1000; i++) {
    for(int j = 1; j <= 1000; j++) {
      if(i % j == 0) {
        factors[i].push_back(j);
      }
    }
  }

  int N, M, O; scanf("%d %d %d", &N, &M, &O);

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      int x; scanf("%d", &x);
      int s = i + j;
      if(s > 1000) continue;
      update(s, 1, N, 0, i, i, x);
    }
  }

  while(O--) {
    int t, x1, y1, x2, y2, k; scanf("%d %d %d %d %d %d", &t, &x1, &y1, &x2, &y2, &k);
    int v; if(t == 0) scanf("%d", &v);
    int ans = 0;

    for(auto x: factors[k]) {
      if(x < x1 + y1 || x > x2 + y2) continue;

      int L = max(x - y2, x1);
      int R = min(x - y1, x2);

      if(t == 0) {
        update(x, 1, N, 0, L, R, v);
      }
      else {
        ans += query(x, 1, N, 0, L, R);
        ans %= MOD;
      }
    }

    if(t == 1) printf("%d\n", ans);
  }
}
