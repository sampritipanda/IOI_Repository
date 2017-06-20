#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

int M, N, B, P;
int X1[500000];
int Y1[500000];
int X2[500000];
int Y2[500000];
int C[500000];

vector<int> A[1000001][2];

namespace BinarySearch {
  int segtree[4000001];
  int lazy[4000001];

  void propagate(int L, int R, int i) {
    if(lazy[i] == 0) return;

    segtree[i] += lazy[i];

    if(L != R) {
      lazy[2*i + 1] += lazy[i];
      lazy[2*i + 2] += lazy[i];
    }

    lazy[i] = 0;
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

    segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
  }

  bool check(int x) {
    int N_ = N - x + 1;
    memset(segtree, 0, sizeof segtree);
    memset(lazy, 0, sizeof lazy);

    for(int i = 1; i <= M; i++) {
      for(int j: A[i][0]) {
        update(1, N_, 0, max(Y1[j] - x + 1, 1), Y2[j], C[j]);
      }
      if(i < x) continue;

      if(segtree[0] <= B) return true;

      for(int j: A[i - x + 1][1]) {
        update(1, N_, 0, max(Y1[j] - x + 1, 1), Y2[j], -C[j]);
      }
    }

    return false;
  }
}

namespace TwoPointer {
  struct node {
    int len;
    int L_len, L_v;
    int R_len, R_v;
    int ans, ans_v;
    int lazy;
  };

  node segtree[4000001];

  void update_ans(node &N, int ans, int ans_v) {
    if(ans_v < N.ans_v) {
      N.ans = ans;
      N.ans_v = ans_v;
    }
    else if(ans_v == N.ans_v) {
      N.ans = max(N.ans, ans);
    }
  }

  node merge(node left, node right) {
    node N;
    N.len = left.len + right.len;
    N.lazy = 0;

    N.L_len = left.L_len; N.L_v = left.L_v;
    if(left.L_len == left.len && left.L_v == right.L_v) {
      N.L_len = left.L_len + right.L_len;
      N.L_v = left.L_v;
    }
    N.R_len = right.R_len; N.R_v = right.R_v;
    if(right.R_len == right.len && right.R_v == left.R_v) {
      N.R_len = right.R_len + left.R_len;
      N.R_v = right.R_v;
    }

    N.ans = left.ans; N.ans_v = left.ans_v;
    update_ans(N, right.ans, right.ans_v);
    update_ans(N, N.L_len, N.L_v);
    update_ans(N, N.R_len, N.R_v);
    if(left.R_v == right.L_v) {
      update_ans(N, left.R_len + right.L_len, left.R_v);
    }

    return N;
  }

  void build(int L, int R, int i) {
    segtree[i].lazy = 0;
    if(L == R) {
      segtree[i].len = 1;
      segtree[i].L_len = 1; segtree[i].L_v = 0;
      segtree[i].R_len = 1; segtree[i].R_v = 0;
      segtree[i].ans = 1; segtree[i].ans_v = 0;
      return;
    }

    int mid = (L + R)/2;
    build(L, mid, 2*i + 1);
    build(mid + 1, R, 2*i + 2);
    segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
  }

  void propagate(int L, int R, int i) {
    if(segtree[i].lazy == 0) return;

    segtree[i].L_v += segtree[i].lazy;
    segtree[i].R_v += segtree[i].lazy;
    segtree[i].ans_v += segtree[i].lazy;

    if(L != R) {
      segtree[2*i + 1].lazy += segtree[i].lazy;
      segtree[2*i + 2].lazy += segtree[i].lazy;
    }

    segtree[i].lazy = 0;
  }

  void update(int L, int R, int i, int qL, int qR, int v) {
    propagate(L, R, i);
    if(qL > R || qR < L) return;
    if(qL <= L && R <= qR) {
      segtree[i].lazy += v;
      propagate(L, R, i);
      return;
    }

    int mid = (L + R)/2;
    update(L, mid, 2*i + 1, qL, qR, v);
    update(mid + 1, R, 2*i + 2, qL, qR, v);
    segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
  }

  int query() {
    if(segtree[0].ans_v == 0) return segtree[0].ans;
    return 0;
  }

  int solve() {
    build(1, N, 0);

    int L = 1, R = 0;
    int ans = 0;
    while(R < M) {
      if(R - L + 1 <= ans) {
        ++R;
        for(int j: A[R][0]) {
          update(1, N, 0, Y1[j], Y2[j], 1);
        }
        ans = max(ans, min(query(), R - L + 1));
      }
      else {
        for(int j: A[L][1]) {
          update(1, N, 0, Y1[j], Y2[j], -1);
        }
        ans = max(ans, min(query(), R - L + 1));
        ++L;
      }
    }
    return ans;
  }
};

int main() {
  scanf("%d %d", &M, &N);
  scanf("%d", &B);
  scanf("%d", &P);

  for(int i = 0; i < P; i++) {
    scanf("%d %d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i], &C[i]);
    A[X1[i]][0].push_back(i);
    A[X2[i]][1].push_back(i);
  }

  if(B == 0) {
    printf("%d\n", TwoPointer::solve());
  }
  else {
    int L = 0, R = min(M, N);
    while(L < R) {
      int mid = (L + R + 1)/2;

      if(BinarySearch::check(mid)) {
        L = mid;
      }
      else {
        R = mid - 1;
      }
    }
    printf("%d\n", L);
  }
}
