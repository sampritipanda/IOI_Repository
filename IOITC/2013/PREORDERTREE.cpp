#include <iostream>
#include <algorithm>

using namespace std;

// dp[i][j] = Number of BSTs with nodes == bitmask i and root = j
long long dp[1 << 20][20];
long long sum[1 << 20];
int N;
string ans = "";

void solve(long long x, int mask) {
  if(mask == 0) return;

  for(int i = 0; i < N; i++) {
    if(!(mask & (1 << i))) continue;;

    if(x > dp[mask][i]) x -= dp[mask][i];
    else {
      ans += char('a' + i);

      int left_mask = 0, right_mask = 0;
      for(int j = 0; j < N; j++) {
        if(mask & (1 << j)) {
          if(j < i) left_mask |= (1 << j);
          else if(j > i) right_mask |= (1 << j);
        }
      }

      if(x < sum[left_mask]) {
        solve(x, left_mask);
      }
      else {
        solve(sum[left_mask], left_mask);
        solve(x - sum[left_mask], right_mask);
      }

      return;
    }
  }
}

int main() {
  long long K; cin >> N >> K;

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

  solve(K, (1 << N) - 1);
  cout << ans << endl;
}
