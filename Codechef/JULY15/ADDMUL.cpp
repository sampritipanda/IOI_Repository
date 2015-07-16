// Addition and Multiplication

#include <iostream>
#include <algorithm>
#include <cassert>

#define MOD 1000000007

using namespace std;

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

int A[100010];
long long segtree[400100];
long long lazy_increase[400100][2];  // Lazy for Addition and Multiplication
long long lazy_set[400100];  // Lazy for Set Update

void build_tree(int L, int R, int i) {
  lazy_increase[i][0] = 1; lazy_increase[i][1] = 0;
  lazy_set[i] = -1;

  if(L == R) {
    segtree[i] = A[L];
    return;
  }

  int mid = L + (R - L)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = (segtree[2*i + 1] + segtree[2*i + 2]) % MOD;
}

void propagate(int L, int R, int i) {
  if(lazy_set[i] != -1) {
    segtree[i] = (lazy_set[i] * (R - L + 1)) % MOD;

    if(L < R) {
      lazy_set[2*i + 1] = lazy_set[2*i + 2] = lazy_set[i];
      lazy_increase[2*i + 1][0] = 1; lazy_increase[2*i + 1][1] = 0;
      lazy_increase[2*i + 2][0] = 1; lazy_increase[2*i + 2][1] = 0;
    }
    lazy_set[i] = -1;
  }

  if(lazy_increase[i][0] == 1 && lazy_increase[i][1] == 0) return;

  segtree[i] = (segtree[i] * lazy_increase[i][0]) % MOD;
  segtree[i] = (segtree[i] + ((lazy_increase[i][1] * (R - L + 1)) % MOD));

  if(L < R) {
    lazy_increase[2*i + 1][1] = (lazy_increase[2*i + 1][1] * lazy_increase[i][0]) % MOD;
    lazy_increase[2*i + 1][1] = (lazy_increase[2*i + 1][1] + lazy_increase[i][1]) % MOD;
    lazy_increase[2*i + 1][0] = (lazy_increase[2*i + 1][0] * lazy_increase[i][0]) % MOD;

    lazy_increase[2*i + 2][1] = (lazy_increase[2*i + 2][1] * lazy_increase[i][0]) % MOD;
    lazy_increase[2*i + 2][1] = (lazy_increase[2*i + 2][1] + lazy_increase[i][1]) % MOD;
    lazy_increase[2*i + 2][0] = (lazy_increase[2*i + 2][0] * lazy_increase[i][0]) % MOD;
  }

  lazy_increase[i][0] = 1; lazy_increase[i][1] = 0;
}

void update(int L, int R, int i, int qS, int qE, int val, int type) {
  propagate(L, R, i);

  if(L > R || qE < L || qS > R) return;

  if(qS <= L && R <= qE) {
    if(type == 1) lazy_increase[i][1] = (lazy_increase[i][1] + val) % MOD;
    else if(type == 2) {
      lazy_increase[i][0] = (lazy_increase[i][0] * val) % MOD;
      lazy_increase[i][1] = (lazy_increase[i][1] * val) % MOD;
    }
    else if(type == 3) {
      lazy_set[i] = val;
      lazy_increase[i][0] = 1; lazy_increase[i][1] = 0;
    }

    propagate(L, R, i);
    return;
  }

  int mid = L + (R - L)/2;
  update(L, mid, 2*i + 1, qS, qE, val, type);
  update(mid + 1, R, 2*i + 2, qS, qE, val, type);
  segtree[i] = (segtree[2*i + 1] + segtree[2*i + 2]) % MOD;
}

long long query(int L, int R, int i, int qS, int qE) {
  if(L > R || qE < L || qS > R) return 0;

  propagate(L, R, i);

  if(qS <= L && R <= qE) {
    return segtree[i];
  }

  int mid = L + (R - L)/2;
  long long left = query(L, mid, 2*i + 1, qS, qE),
            right = query(mid + 1, R, 2*i + 2, qS, qE);
  return (left + right) % MOD;
}

void print_array(int N) {
  for(int i = 1; i <= N; i++) {
    cout << query(1, N, 0, i, i) << " ";
  }
  cout << endl;
}

int main() {
  int N = scan(), Q = scan();

  for(int i = 1; i <= N; i++) A[i] = scan();

  build_tree(1, N, 0);

  while(Q--) {
    int type = scan(), a = scan(), b = scan();

    if(type == 4) {
      cout << query(1, N, 0, a, b) << endl;
    }
    else {
      int v = scan();
      update(1, N, 0, a, b, v, type);
    }
  }
}
