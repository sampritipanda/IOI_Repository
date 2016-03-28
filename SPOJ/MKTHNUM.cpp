#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[100001];
vector<int> segtree[400004];

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].push_back(A[L]);
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);

  merge(segtree[2*i + 1].begin(), segtree[2*i + 1].end(), segtree[2*i + 2].begin(), segtree[2*i + 2].end(), back_inserter(segtree[i]));
}

int query(int L, int R, int i, int qL, int qR, int K) {
  if(L > R || L > qR || R < qL) return 0;

  if(qL <= L && R <= qR) {
    return upper_bound(segtree[i].begin(), segtree[i].end(), K) - segtree[i].begin();
  }

  int mid = (L + R)/2;
  return query(L, mid, 2*i + 1, qL, qR, K) + query(mid + 1, R, 2*i + 2, qL, qR, K);
}

int main() {
  int N, Q; scanf("%d %d", &N, &Q);
  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

  build_tree(1, N, 0);

  while(Q--) {
    int x, y, k; scanf("%d %d %d", &x, &y, &k);

    int L = 0, R = 2000000000;
    while(L < R) {
      int mid = L + (R - L)/2;
      int cnt = query(1, N, 0, x, y, mid - 1000000000);  // number of elements <= mid

      // answer is <= mid
      if(k <= cnt) {
        R = mid;
      }
      else {
        L = mid + 1;
      }
    }

    printf("%d\n", L - 1000000000);
  }
}
