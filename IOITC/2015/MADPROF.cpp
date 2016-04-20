#include <cstdio>
#include <algorithm>

using namespace std;

long long segtree[4000000];
long long lazy[4000000];

inline int scan() {
  char c = getchar_unlocked();
  int x = 0;

  while(c < '0' && c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9') {
    x = (x<<1)+(x<<3)+c-'0';
    c = getchar_unlocked();
  }

  return x;
}

inline void propagate(int L, int R, int i) {
  if(lazy[i] != 0) {
    segtree[i] += (R - L + 1) * lazy[i];
    if(L != R) {
      lazy[2*i + 1] += lazy[i];
      lazy[2*i + 2] += lazy[i];
    }
    lazy[i] = 0;
  }
}

long long query(int L, int R, int i, int qL, int qR) {
  if(L > qR || R < qL) return 0;

  propagate(L, R, i);

  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return query(L, mid, 2*i + 1, qL, qR) + query(mid + 1, R, 2*i + 2, qL, qR);
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
  segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
}

int main() {
  int N = scan(), Q = scan();

  while(Q--) {
    int t = scan();

    if(t == 0) {
      int p = scan(), q = scan(), v = scan();
      update(1, N, 0, p, q, v);
    }
    else {
      int p = scan(), q = scan();
      printf("%lld\n", query(1, N, 0, p, q));
    }
  }
}
