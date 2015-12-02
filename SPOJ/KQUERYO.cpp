// K-Query Online

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int A[30001];
vector<int> segtree[4 * 30001 + 10];

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].push_back(A[L]);
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i].clear();
  merge(segtree[2*i + 1].begin(), segtree[2*i + 1].end(), segtree[2*i + 2].begin(), segtree[2*i + 2].end(), back_inserter(segtree[i]));
}

int query(int L, int R, int qS, int qE, int k, int i) {
  if(qS > R || qE < L) return 0;
  if(qS <= L && R <= qE) {
    return (segtree[i].end() - upper_bound(segtree[i].begin(), segtree[i].end(), k));
  }

  int mid = (L + R)/2;
  return query(L, mid, qS, qE, k, 2*i + 1) + query(mid + 1, R, qS, qE, k, 2*i + 2);
}

int main() {
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

  build_tree(1, N, 0);

  int Q; scanf("%d", &Q);

  int ans = 0;
  while(Q--) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    int i = a ^ ans, j = b ^ ans, k = c ^ ans;

    ans = query(1, N, i, j, k, 0);
    printf("%d\n", ans);
  }
}
