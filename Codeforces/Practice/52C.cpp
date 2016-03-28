#include <cstdio>
#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;

long long A[200001];
long long segtree[800001];
long long lazy[800001];

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = A[L];
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1); build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

void propagate(int L, int R, int i) {
  if(lazy[i] != 0) {
    segtree[i] += lazy[i];
    if(L != R) {
      lazy[2*i + 1] += lazy[i];
      lazy[2*i + 2] += lazy[i];
    }
    lazy[i] = 0;
  }
}

long long query(int L, int R, int i, int qL, int qR) {
  propagate(L, R, i);
  if(R < qL || L > qR) return LLONG_MAX;

  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return min(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

void update(int L, int R, int i, int qL, int qR, long long v) {
  propagate(L, R, i);
  if(R < qL || L > qR) return;

  if(qL <= L && R <= qR) {
    lazy[i] += v;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, v);
  update(mid + 1, R, 2*i + 2, qL, qR, v);
  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

int main() {
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%I64d", &A[i]);

  build_tree(1, N, 0);

  int M; scanf("%d", &M);

  char S[100];
  while(M--) {
    scanf(" %[^\n]", S);
    stringstream ss(S);

    int L, R; ss >> L >> R; L++; R++;
    long long v;

    if(ss >> v) {
      if(L <= R) {
        update(1, N, 0, L, R, v);
      }
      else {
        update(1, N, 0, L, N, v);
        update(1, N, 0, 1, R, v);
      }
    }
    else {
      if(L <= R) {
        printf("%I64d\n", query(1, N, 0, L, R));
      }
      else {
        printf("%I64d\n", min(query(1, N, 0, L, N), query(1, N, 0, 1, R)));
      }
    }
  }
}
