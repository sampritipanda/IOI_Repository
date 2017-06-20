#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int A[1001][1001];
int P[1001][1001];
int dp[1001][1001];
int segtree[3501][3501];
int N, M;

int query(int x_l, int x_r, int y_l, int y_r) {
  return P[x_r][y_r] - P[x_l - 1][y_r] - P[x_r][y_l - 1] + P[x_l - 1][y_l - 1];
}

int query_2_y(int L, int R, int i, int j, int y_l, int y_r) {
  if(L > y_r || R < y_l) return INT_MAX/2;
  if(y_l <= L && R <= y_r) return segtree[i][j];

  int mid = (L + R)/2;
  return min(query_2_y(L, mid, i, 2*j + 1, y_l, y_r), query_2_y(mid + 1, R, i, 2*j + 2, y_l, y_r));
}

int query_2(int L, int R, int i, int x_l, int x_r, int y_l, int y_r) {
  if(L > x_r || R < x_l) return INT_MAX/2;
  if(x_l <= L && R <= x_r) return query_2_y(1, M, i, 0, y_l, y_r);

  int mid = (L + R)/2;
  return min(query_2(L, mid, 2*i + 1, x_l, x_r, y_l, y_r), query_2(mid + 1, R, 2*i + 2, x_l, x_r, y_l, y_r));
}

pair<int, pair<int, int> > query_2_brute(int x_l, int x_r, int y_l, int y_r) {
  pair<int, pair<int, int> >  ans = {INT_MAX/2, {-1, -1}};
  for(int i = x_l; i <= x_r; i++) {
    for(int j = y_l; j <= y_r; j++) {
      ans = min(ans, {dp[i][j], {i, j}});
    }
  }
  return ans;
}

void build_tree_y(int L, int R, int i, int j, int x) {
  if(L == R) {
    segtree[i][j] = dp[x][L];
    return;
  }

  int mid = (L + R)/2;
  build_tree_y(L, mid, i, 2*j + 1, x);
  build_tree_y(mid + 1, R, i, 2*j + 2, x);
  segtree[i][j] = min(segtree[i][2*j + 1], segtree[i][2*j + 2]);
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    build_tree_y(1, M, i, 0, L);
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);

  int len = 3501;
  for(int j = 0; j < len; j++) {
    segtree[i][j] = min(segtree[2*i + 1][j], segtree[2*i + 2][j]);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int a, b, c, d; cin >> N >> M >> a >> b >> c >> d;
  swap(N, M); swap(a, b); swap(c, d);

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[i][j];
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      P[i][j] = A[i][j] + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(i >= c && j >= d) {
        dp[i][j] = query(i - c + 1, i, j - d + 1, j);
      }
      else {
        dp[i][j] = INT_MAX/2;
      }
    }
  }

  build_tree(1, N, 0);

  vector<int> ans = {0, -1, -1, -1, -1};
  for(int i = a; i <= N; i++) {
    for(int j = b; j <= M; j++) {
      int curr = query(i - a + 1, i, j - b + 1, j);
      int best = query_2(1, N, 0, i - a + 1 + c, i - 1, j - b + 1 + d, j - 1);
      curr -= best;
      if(curr > ans[0]) {
        ans = {curr, i, j, -1, -1};
      }
    }
  }
  auto best = query_2_brute(ans[1] - a + 1 + c, ans[1] - 1, ans[2] - b + 1 + d, ans[2] - 1);
  ans[3] = best.second.first; ans[4] = best.second.second;
  cout << (ans[2] - b + 1) << " " << (ans[1] - a + 1) << endl;
  cout << (ans[4] - d + 1) << " " << (ans[3] - c + 1) << endl;
}
