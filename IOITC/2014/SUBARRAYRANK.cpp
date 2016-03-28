#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[10001];
int segtree[40004][1001];

inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
                c=getchar_unlocked();
            }
    while(c>='0'&&c<='9'){
                x=(x<<1)+(x<<3)+c-'0';
                c=getchar_unlocked();
            }
    return x;
}

inline int query(int x, int i) {
  int ans = 0;
  while(i > 0) {
    ans += segtree[x][i];
    i -= i & -i;
  }
  return ans;
}

inline void update(int x, int i, int v) {
  while(i <= 1000) {
    segtree[x][i] += v;
    i += i & -i;
  }
}

void build_tree(int L, int R, int i) {
  for(int j = L; j <= R; j++) {
    update(i, A[j], 1);
  }

  if(L != R) {
    int mid = (L + R)/2;
    build_tree(L, mid, 2*i + 1);
    build_tree(mid + 1, R, 2*i + 2);
  }
}

void update(int L, int R, int i, int pos, int val) {
  update(i, A[pos], -1);
  update(i, val, 1);

  if(L == R) {
    return;
  }
  int mid = (L + R)/2;
  if(pos <= mid) {
    update(L, mid, 2*i + 1, pos, val);
  }
  else {
    update(mid + 1, R, 2*i + 2, pos, val);
  }
}

int tree_query(int L, int R, int i, int qL, int qR, int K) {
  if(L > R || L > qR || R < qL) return 0;

  if(qL <= L && R <= qR) return query(i, K);

  int mid = (L + R)/2;
  return tree_query(L, mid, 2*i + 1, qL, qR, K) + tree_query(mid + 1, R, 2*i + 2, qL, qR, K);
}

int main() {
  int T = scan();

  while(T--) {
    int N = scan();
    for(int i = 1; i <= N; i++) A[i] = scan();

    memset(segtree, 0, sizeof segtree);

    build_tree(1, N, 0);

    int Q = scan();

    while(Q--) {
      int t = scan();

      if(t == 0) {
        int x = scan(), y = scan(), k = scan();

        int L = 1, R = 1000;
        while(L < R) {
          int mid = (L + R)/2;
          int cnt = tree_query(1, N, 0, x, y, mid);  // number of elements <= mid

          // answer is <= mid
          if(k <= cnt) {
            R = mid;
          }
          else {
            L = mid + 1;
          }
        }

        printf("%d\n", L);
      }
      else {
        int x = scan(), k = scan();
        update(1, N, 0, x, k);
        A[x] = k;
      }
    }
  }
}
