#include <iostream>
#include <algorithm>

using namespace std;

// dp[i][j] = Number of BSTs with nodes == bitmask i and root = j
int dp[1 << 20][20];
int sum[1 << 20];
int N;
string ans = "";

void solve(int x, int mask) {
  if(mask == 0) return;

  for(int i = 0; i < N; i++) {
    if(!(mask & (1 << i))) continue;;

    if(x >= dp[mask][i]) x -= dp[mask][i];
    else {
      ans += char('a' + i);

      int left_mask = 0, right_mask = 0;
      for(int j = 0; j < N; j++) {
        if(mask & (1 << j)) {
          if(j < i) left_mask |= (1 << j);
          else if(j > i) right_mask |= (1 << j);
        }
      }

      if(sum[right_mask] == 0) {
        solve(x, left_mask);
      }
      else {
        solve(x/sum[right_mask], left_mask);
        solve(x % sum[right_mask], right_mask);
      }

      return;
    }
  }
}

int main() {
  int K; cin >> N >> K;
  K--;

  sum[0] = 1;

  for(int mask = 1; mask < (1 << N); mask++) {
    for(int i = 0; i < N; i++) {  // i = root
      if(!(mask & (1 << i))) continue;

      int left_mask = 0, right_mask = 0;
      for(int j = 0; j < N; j++) {
        if(mask & (1 << j)) {
          if(j < i) left_mask |= (1 << j);
          else if(j > i) right_mask |= (1 << j);
        }
      }

      dp[mask][i] = sum[left_mask] * sum[right_mask];

      sum[mask] += dp[mask][i];
    }
  }

  sum[0] = 0;

  if(K >= sum[(1 << N) - 1]) cout << -1 << endl;
  else {
    solve(K, (1 << N) - 1);
    cout << ans << endl;
  }
}
