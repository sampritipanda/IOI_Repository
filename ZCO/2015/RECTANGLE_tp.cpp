// Rectangle

#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100000, M = 500;

int P[100001];
int segtree[400001];

int build_tree(int L, int R, int i) {
  if(L == R) {
    return segtree[i] = P[L];
  }

  int mid = (L + R)/2;
  return segtree[i] = min(build_tree(L, mid, 2*i + 1), build_tree(mid + 1, R, 2*i + 2));
}

int query(int L, int R, int qS, int qE, int i) {
  if(L > qE || R < qS) return 999999;
  if(qS <= L && R <= qE) return segtree[i];

  int mid = (L + R)/2;
  return min(query(L, mid, qS, qE, 2*i + 1), query(mid + 1, R, qS, qE, 2*i + 2));
}

int findmin(int L, int R) {
  if(L > R) return M;
  else return query(0, N, L, R, 0);
}

int main() {
  int Q; scanf("%d", &Q);

  for(int i = 0; i <= N; i++) P[i] = M;

  for(int i = 0; i < Q; i++){
    int x, y; scanf("%d %d", &x, &y);
    P[x] = min(P[x], y);
  }

  build_tree(0, N, 0);

  int i = 0, j = 1;
  int best = 0;
  while(i < N && j <= N) {
    int curr_area = findmin(i + 1, j - 1) * (j - i);
    best = max(best, curr_area);
    if(i + 1 == j) {
      j++;
    }
    else if(j == N) {
      i++;
    }
    else {
      int decrease = findmin(i + 1 + 1, j - 1) * (j - i - 1);
      int increase = findmin(i + 1, j + 1 - 1) * (j - i + 1);

      if(decrease >= increase) {
        i++;
      }
      else {
        j++;
      }
    }

    best = max(best, findmin(i + 1, j - 1) * (j - i));
  }

  printf("%d\n", best);
}
