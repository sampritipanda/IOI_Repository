#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[10001];
int tree[10004][1001];

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

inline int query(int i, int j) {
  int ans = 0;
  while(i > 0) {
    int x = j;
    while(x > 0) {
      ans += tree[i][x];
      x -= x & -x;
    }
    i -= i & -i;
  }
  return ans;
}

inline void update(int i, int j, int v) {
  while(i <= 10000) {
    int x = j;
    while(x <= 1000) {
      tree[i][x] += v;
      x += x & -x;
    }
    i += i & -i;
  }
}

int main() {
  int T = scan();

  while(T--) {
    int N = scan();
    for(int i = 1; i <= N; i++) A[i] = scan();

    memset(tree, 0, sizeof tree);

    for(int i = 1; i <= N; i++) update(i, A[i], 1);

    int Q = scan();

    while(Q--) {
      int t = scan();

      if(t == 0) {
        int x = scan(), y = scan(), k = scan();

        int L = 1, R = 1000;
        while(L < R) {
          int mid = (L + R)/2;
          int cnt = query(y, mid) - query(x - 1, mid);  // number of elements <= mid

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
        update(x, A[x], -1);
        A[x] = k;
        update(x, A[x], 1);
      }
    }
  }
}
