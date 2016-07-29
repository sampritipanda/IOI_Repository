#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

struct node {
  int S, E;
  int dp[200][200];  // dp[i][j] = (S, i) -> (E, j)
};

int L[5000][200];
int R[5000][200];
int U[5000][200];
node tree[1500];
int N, M;

void calc(node &N) {
  int S = N.S, E = N.E;
  for(int i = 0; i < M; i++) {
    N.dp[i][i] = U[S][i];
    for(int j = i - 1; j >= 0; j--) {
      N.dp[i][j] = N.dp[i][j + 1] + L[S][j + 1];
    }
    for(int j = i + 1; j < M; j++) {
      N.dp[i][j] = N.dp[i][j - 1] + R[S][j - 1];
    }

    for(int j = S + 1; j <= E; j++) {
      for(int k = 0; k < M; k++) {
        N.dp[i][k] += U[j][k];
      }
      for(int k = 1; k < M; k++) {
        N.dp[i][k] = min(N.dp[i][k], N.dp[i][k - 1] + R[j][k - 1]);
      }
      for(int k = M - 2; k >= 0; k--) {
        N.dp[i][k] = min(N.dp[i][k], N.dp[i][k + 1] + L[j][k + 1]);
      }
    }
  }
}

void solve(int i, node &N, node &upper, node &down, int L, int R, int S_L, int S_R) {
  int j = (L + R)/2;
  int opt = -1; N.dp[i][j] = INT_MAX/2;
  for(int k = S_L; k <= S_R; k++) {
    int curr = upper.dp[i][k] + down.dp[k][j];
    if(curr < N.dp[i][j]) {
      N.dp[i][j] = curr;
      opt = k;
    }
  }

  if(L < R) {
    solve(i, N, upper, down, L, j - 1, S_L, opt);
    solve(i, N, upper, down, j + 1, R, opt, S_R);
  }
}

void merge(node &N, node &up, node &down) {
  memset(N.dp, 0, sizeof N.dp);
  for(int i = 0; i < M; i++) {
    solve(i, N, up, down, 0, M - 1, 0, M - 1);
  }

  int S = N.S, E = N.E;
  for(int i = 0; i < M; i++) {
    for(int k = 1; k < M; k++) {
      N.dp[i][k] = min(N.dp[i][k], N.dp[i][k - 1] + R[E][k - 1]);
    }
    for(int k = M - 2; k >= 0; k--) {
      N.dp[i][k] = min(N.dp[i][k], N.dp[i][k + 1] + L[E][k + 1]);
    }
  }
}

void build_tree(int L, int R, int i) {
  tree[i].S = L, tree[i].E = R;

  if(R - L <= 16) {
    calc(tree[i]);
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);

  merge(tree[i], tree[2*i + 1], tree[2*i + 2]);
}

void update(int L, int R, int i, int ind) {
  if(R - L <= 16) {
    calc(tree[i]);
    return;
  }

  int mid = (L + R)/2;
  if(ind <= mid) {
    update(L, mid, 2*i + 1, ind);
  }
  else {
    update(mid + 1, R, 2*i + 2, ind);
  }
  merge(tree[i], tree[2*i + 1], tree[2*i + 2]);
}

int main() {
  scanf("%d %d", &N, &M);

  for(int i = 0; i < N; i++) {
    L[i][0] = INT_MAX/2;
    for(int j = 0; j < M - 1; j++) {
      int x; scanf("%d", &x);
      R[i][j] = x;
      L[i][j + 1] = x;
    }
    R[i][M - 1] = INT_MAX/2;
  }
  for(int j = 0; j < M; j++) U[0][j] = 0;
  for(int i = 0; i < N - 1; i++) {
    for(int j = 0; j < M; j++) {
      scanf("%d", &U[i + 1][j]);
    }
  }

  build_tree(0, N - 1, 0);

  int E; scanf("%d", &E);

  while(E--) {
    int t; scanf("%d", &t);

    if(t == 1) {
      int P, Q, W; scanf("%d %d %d", &P, &Q, &W);
      R[P][Q] = W;
      L[P][Q + 1] = W;
      update(0, N - 1, 0, P);
    }
    else if(t == 2) {
      int P, Q, W; scanf("%d %d %d", &P, &Q, &W);
      U[P + 1][Q] = W;
      update(0, N - 1, 0, P + 1);
    }
    else {
      int V1, V2; scanf("%d %d", &V1, &V2);
      printf("%d\n", tree[0].dp[V1][V2]);
    }
  }
}
