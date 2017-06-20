#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

namespace Dim1 {
  int N, D, M;
  int A[100001];

  void solve() {
    scanf("%d %d %d", &N, &D, &M);
    for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
    sort(A + 1, A + 1 + N);

    long long ans = 0;
    int L = 1;
    for(int i = 1; i <= N; i++) {
      while(A[i] - A[L] > D) L++;
      ans += i - L;
    }
    printf("%lld\n", ans);
  }
};

namespace Dim2 {
  int N, D, M;
  int X[100001], Y[100001];
  int bit[150001];
  vector<int> by_x[150001];

  int query(int x) {
    int ans = 0;
    while(x > 0) {
      ans += bit[x];
      x -= x & -x;
    }
    return ans;
  }

  int query(int L, int R) {
    if(L == 0) return query(R);
    return query(R) - query(L - 1);
  }

  void update(int x, int v) {
    if(x == 0) return;
    while(x <= 2 * M) {
      bit[x] += v;
      x += x & -x;
    }
  }

  void solve() {
    scanf("%d %d %d", &N, &D, &M);
    for(int i = 1; i <= N; i++) {
      scanf("%d %d", &X[i], &Y[i]);
      int x_ = X[i] + Y[i] - 1;
      int y_ = Y[i] - X[i] + M;
      X[i] = x_, Y[i] = y_;
      by_x[X[i]].push_back(Y[i]);
    }

    long long ans = 0;
    for(int x = 1; x <= 2 * M; x++) {
      sort(by_x[x].begin(), by_x[x].end());
      for(int y: by_x[x]) {
        ans += query(max(y - D, 1), min(y + D, 2 * M));
        update(y, 1);
      }
      if(x - D >= 1) {
        for(int y: by_x[x - D]) {
          update(y, -1);
        }
      }
    }
    printf("%lld\n", ans);
  }
};

namespace Dim3 {
  int P[75 + 1][150 + 1][150 + 1];
  int X[100001], Y[100001], Z[100001];
  int N, M, D;

  inline int find_sum(int z, int x_l, int x_r, int y_l, int y_r) {
    x_l = max(x_l, 1); x_r = min(x_r, 2 * M);
    y_l = max(y_l, 1); y_r = min(y_r, 2 * M);
    return P[z][x_r][y_r] - P[z][x_l - 1][y_r] - P[z][x_r][y_l - 1] + P[z][x_l - 1][y_l - 1];
  }

  void solve() {
    scanf("%d %d %d", &N, &D, &M);
    for(int i = 1; i <= N; i++) {
      scanf("%d %d %d", &X[i], &Y[i], &Z[i]);
      int x_ = X[i] + Y[i] - 1;
      int y_ = Y[i] - X[i] + M;;
      X[i] = x_, Y[i] = y_;
      P[Z[i]][X[i]][Y[i]]++;
    }

    for(int z = 1; z <= M; z++) {
      for(int x = 1; x <= 2 * M; x++) {
        for(int y = 1; y <= 2 * M; y++) {
          P[z][x][y] = P[z][x][y] + P[z][x - 1][y] + P[z][x][y - 1] - P[z][x - 1][y - 1];
        }
      }
    }

    long long ans = 0, ans2 = 0;
    for(int i = 1; i <= N; i++) {
      int x = X[i], y = Y[i], z = Z[i];
      ans2 += find_sum(z, x - D, x + D, y - D, y + D) - 1;
      for(int d_z = 1; d_z <= min(D, z - 1); d_z++) {
        int rem = D - d_z;
        ans += find_sum(z - d_z, x - rem, x + rem, y - rem, y + rem);
      }
    }
    ans2 /= 2;
    printf("%lld\n", ans + ans2);
  }
};

int main() {
  int B; scanf("%d", &B);

  if(B == 1) {
    Dim1::solve();
  }
  else if(B == 2) {
    Dim2::solve();
  }
  else {
    Dim3::solve();
  }
}

