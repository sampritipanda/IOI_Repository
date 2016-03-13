#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
vector<int> P, A, ind;
char dp[15][1 << 15][11][3];
char nxt[15][1 << 15][11][3];

// i = fix ind[i]th element, j = used mask, k = i-1 value, l = 1 (i-1 < i-2), 2(i-1 > i-2) 0(neither)
// returns minimum amount of extrema for i..N
int solve(int i, int j, int k, int l) {
  if(i == ind.size()) return 0;
  if(dp[i][j][k][l] != -1) return dp[i][j][k][l];

  int ans = 100000;
  for(int mask_id = 0; mask_id < M; mask_id++) {
    if(j & (1 << mask_id)) continue;

    int val = A[mask_id];
    int prev_extrema = 0;
    if(l == 1 && val > k) prev_extrema = 1;
    if(l == 2 && val < k) prev_extrema = 1;

    if(i == ind.size() - 1) {
      if(ind[i] > 0 && ind[i] < N - 1) {
        int prev_val = k, next_val = P[ind[i] + 1];
        if(val > max(prev_val, next_val) || val < min(prev_val, next_val))
          prev_extrema++;
      }
      if(ind[i] < N - 2) {
        int next_val = P[ind[i] + 1], next_2_val = P[ind[i] + 2];
        if(next_val > max(val, next_2_val) || next_val < min(val, next_2_val))
          prev_extrema++;
      }
    }

    int new_l_value = 0, new_k_value = 0;
    if(i == ind.size() - 1 || ind[i + 1] == ind[i] + 1) {
      new_k_value = val;
      if(ind[i] > 0) {
        if(val < k) new_l_value = 1;
        else if(val > k) new_l_value = 2;
      }
    }
    else if(ind[i + 1] == ind[i] + 2) {
      new_k_value = P[ind[i] + 1];
      if(new_k_value < val) new_l_value = 1;
      else if(new_k_value > val) new_l_value = 2;

      if(ind[i] > 0) {
        if(val > max(P[ind[i] + 1], k) || val < min(P[ind[i] + 1], k)) {
          prev_extrema++;
        }
      }
    }
    else {
      new_k_value = P[ind[i + 1] - 1];
      if(new_k_value < P[ind[i + 1] - 2]) new_l_value = 1;
      if(new_k_value > P[ind[i + 1] - 2]) new_l_value = 2;

      if(ind[i] > 0) {
        if(val > max(P[ind[i] + 1], k) || val < min(P[ind[i] + 1], k)) {
          prev_extrema++;
        }
      }
      int next_val = P[ind[i] + 1], next_2_val = P[ind[i] + 2];
      if(next_val > max(val, next_2_val) || next_val < min(val, next_2_val)) {
        prev_extrema++;
      }
    }

    int new_ans = solve(i + 1, j | (1 << mask_id), new_k_value, new_l_value);
    new_ans += prev_extrema;

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

  for(int i = 0; i < N; i++) {
    if(P[i] == -1) ind.push_back(i);
  }

  sort(A.begin(), A.end());

  for(int i = 0; i < 15; i++) {
    for(int j = 0; j < (1 << 15); j++) {
      for(int k = 0; k <= 10; k++) {
        dp[i][j][k][0] = dp[i][j][k][1] = dp[i][j][k][2] = -1;
        nxt[i][j][k][0] = nxt[i][j][k][1] = nxt[i][j][k][2] = -1;
      }
    }
  }

  int l_value = 0;
  if(!ind.empty() && ind[0] >= 2) {
    if(P[ind[0] - 1] < P[ind[0] - 2]) l_value = 1;
    if(P[ind[0] - 1] > P[ind[0] - 2]) l_value = 2;
  }
  int k_value = 0;
  if(!ind.empty() && ind[0] >= 1) k_value = P[ind[0] - 1];
  int min_cnt = solve(0, 0, k_value, l_value);

  vector<int> ans = P;
  int i = 0, j = 0, k = k_value, l = l_value;
  while(i < ind.size()) {
    int mask_id = nxt[i][j][k][l];
    ans[ind[i]] = A[mask_id];

    int new_l_value = 0, new_k_value = 0;
    int val = ans[ind[i]];
    if(i == ind.size() - 1 || ind[i + 1] == ind[i] + 1) {
      new_k_value = val;
      if(ind[i] > 0) {
        if(val < k) new_l_value = 1;
        else if(val > k) new_l_value = 2;
      }
    }
    else if(ind[i + 1] == ind[i] + 2) {
      new_k_value = P[ind[i] + 1];
      if(new_k_value < val) new_l_value = 1;
      else if(new_k_value > val) new_l_value = 2;
    }
    else {
      new_k_value = P[ind[i + 1] - 1];
      if(new_k_value < P[ind[i + 1] - 2]) new_l_value = 1;
      if(new_k_value > P[ind[i + 1] - 2]) new_l_value = 2;
    }

    k = new_k_value;
    l = new_l_value;

    i++;
    j |= (1 << mask_id);
  }

  for(int i = 0; i < N; i++) cout << ans[i] << " "; cout << endl;
}
