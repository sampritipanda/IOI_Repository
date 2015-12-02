#include <cstdio>
#include <algorithm>

using namespace std;

int A[500001];
int segtree[2000001];

inline int gcd(int a, int b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

int build_tree(int L, int R, int i) {
  if(L == R) {
    return segtree[i] = A[L];
  }

  int mid = (L + R) >> 1;
  return segtree[i] = gcd(build_tree(L, mid, 2*i + 1), build_tree(mid + 1, R, 2*i + 2));
}

int query(int L, int R, int qS, int qE, int i) {
  if(qS > R || qE < L) return 0;
  if(qS <= L && R <= qE) return segtree[i];

  int mid = (L + R) >> 1;
  return gcd(query(L, mid, qS, qE, 2*i + 1), query(mid + 1, R, qS, qE, 2 * i + 2));
}

int main() {
  int N, K; scanf("%d %d", &N, &K);

  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

  build_tree(1, N, 0);

  int i = 1, j = 1;
  int ans = 0;

  while(i < N && j < N) {
    if(query(1, N, i, j, 0) >= K) ans = max(ans, j - i + 1);

    if(i == j) j++;
    else {
      if(A[j + 1] >= K && query(1, N, i, j + 1, 0) >= K) j++;
      else i++;
    }
  }

  while(i <= N) {
    if(query(1, N, i, j, 0) >= K) ans = max(ans, j - i + 1);
    i++;
  }

  printf("%d\n", ans);
}
