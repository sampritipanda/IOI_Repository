#include <iostream>
#include <cstring>

using namespace std;

long long C[100010];
long long segtree[500000];
int lazy[500000];

int K;

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = C[L];
    return;
  }

  int mid = L + (R - L)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
}

void lazy_update(int node, int L, int R) {
  segtree[node] /= lazy[node];
  if(L != R) {
    lazy[node*2 + 1] *= lazy[node];
    lazy[node*2 + 2] *= lazy[node];
  }

  lazy[node] = 1;
}

long long query(int L, int R, int i, int qS, int qE) {
  if(qS > R || qE < L) return 0;

  lazy_update(i, L, R);

  if(qS <= L && R <= qE) return segtree[i];

  int mid = L + (R - L)/2;
  return query(L, mid, 2*i + 1, qS, qE) + query(mid + 1, R, 2*i + 2, qS, qE);
}

void update_point(int L, int R, int i, int value, int index) {
  if(index < L || index > R) return;

  lazy_update(i, L, R);

  if(L == index && R == index) {
    segtree[i] = value;
    return;
  }

  int mid = L + (R - L)/2;
  update_point(L, mid, 2*i + 1, value, index);
  update_point(mid + 1, R, 2*i + 2, value, index);
  segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
}

void update_range(int L, int R, int i, int uS, int uE) {
  if(uS > R || uE < L) return;

  lazy_update(i, L, R);

  if(uS <= L && R <= uE) {
    segtree[i] /= K;
    if(L != R) {
      lazy[2*i + 1] *= K;
      lazy[2*i + 2] *= K;
    }
    return;
  }

  if(L != R) {
    int mid = L + (R - L)/2;
    update_range(L, mid, 2*i + 1, uS, uE);
    update_range(mid + 1, R, 2*i + 2, uS, uE);
    segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
  }
}

int main() {
  ios::sync_with_stdio(0);

  int N, Q; cin >> N >> Q >> K;
  for(int i = 0; i < N; i++) cin >> C[i];
  for(int i = 0; i < 4*N; i++) lazy[i] = 1;

  build_tree(0, N - 1, 0);

  while(Q--) {
    int S, T, U; cin >> S >> T >> U;

    if(S == 1) {
      T--;
      long long original_val = query(0, N, 0, T, T);
      update_point(0, N - 1, 0, U - original_val, T);
      C[T] = U;
    }
    else if(S == 2) {
      T--; U--;
      if(K > 1) {
        update_range(0, N - 1, 0, T, U);
      }
    }
    else {
      T--; U--;
      cout << query(0, N - 1, 0, T, U) << endl;
    }
  }
}
