#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
vector<int> P, A, ind;
char dp[50][1 << 15][11][3];
char nxt[50][1 << 15][11][3];

// i = fix ith element, j = used mask, k = i-1 value, l = 1 (i-1 < i-2), 2(i-1 > i-2) 0(neither)
// returns minimum amount of extrema for i..N
int solve(int i, int j, int k, int l) {
  if(i == N) return 0;
  if(dp[i][j][k][l] != -1) return dp[i][j][k][l];

  if(P[i] != -1) {
    int val = P[i];

    bool prev_extrema = false;
    if(l == 1 && val > k) prev_extrema = true;
    if(l == 2 && val < k) prev_extrema = true;

    int new_l_value = 0;
    if(val < k) new_l_value = 1;
    else if(val > k) new_l_value = 2;
    if(i == 0) new_l_value = 0;

    int new_ans = solve(i + 1, j, val, new_l_value);
    if(prev_extrema) new_ans++;

    nxt[i][j][k][l] = val;
    return dp[i][j][k][l] = new_ans;
  }

  int ans = 100000;
  for(int mask_id = 0; mask_id < M; mask_id++) {
    if(j & (1 << mask_id)) continue;

    int val = A[mask_id];
    bool prev_extrema = false;
    if(l == 1 && val > k) prev_extrema = true;
    if(l == 2 && val < k) prev_extrema = true;

    int new_l_value = 0;
    if(val < k) new_l_value = 1;
    else if(val > k) new_l_value = 2;
    if(i == 0) new_l_value = 0;

    int new_ans = solve(i + 1, j | (1 << mask_id), val, new_l_value);
    if(prev_extrema) new_ans++;

    if(new_ans < ans) {
      ans = new_ans;
      nxt[i][j][k][l] = mask_id;
    }
  }

  return dp[i][j][k][l] = ans;
}

int main() {
  cin >> N >> M;
  P.resize(N); A.resize(M);

  for(int i = 0; i < N; i++) cin >> P[i];
  for(int i = 0; i < M; i++) cin >> A[i];

  sort(A.begin(), A.end());

  for(int i = 0; i < 50; i++) {
    for(int j = 0; j < (1 << 15); j++) {
      for(int k = 0; k <= 10; k++) {
        dp[i][j][k][0] = dp[i][j][k][1] = dp[i][j][k][2] = -1;
        nxt[i][j][k][0] = nxt[i][j][k][1] = nxt[i][j][k][2] = -1;
      }
    }
  }

  int min_cnt = solve(0, 0, 0, 0);

  vector<int> ans = P;
  int i = 0, j = 0, k = 0, l = 0;
  while(i < N) {
    if(ans[i] == -1) {
      int mask_id = nxt[i][j][k][l];
      ans[i] = A[mask_id];

      l = 0;
      if(i > 0) {
        if(ans[i] < k) l = 1;
        else if(ans[i] > k) l = 2;
      }
      k = ans[i];
      i++;
      j |= (1 << mask_id);
    }
    else {
      l = 0;
      if(i > 0) {
        if(ans[i] < k) l = 1;
        else if(ans[i] > k) l = 2;

      }
      k = ans[i];
      i++;
    }
  }

  for(int i = 0; i < N; i++) cout << ans[i] << " "; cout << endl;
}
