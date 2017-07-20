#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int Y[2000];
int dp[2000][2000];
int dp_min[2000];

int solve(int i, int j, long long mask) {
  if(i == N) {
    return j == 0;
  }
  if(j == 0) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  dp[i][j] = 0;
  long long sum = 0;
  for(int k = i; k < N; k++) {
    sum += Y[k];
    if((sum | mask) == mask) {
       dp[i][j] |= solve(k + 1, j - 1, mask);
    }
  }
  return dp[i][j];
}

int solve_min(int i, long long mask) {
  if(i == N) return 0;
  if(dp_min[i] != -1) return dp_min[i];

  dp_min[i] = N + 1;
  long long sum = 0;
  for(int k = i; k < N; k++) {
    sum += Y[k];
    if((sum | mask) == mask) {
      dp_min[i] = min(dp_min[i], 1 + solve_min(k + 1, mask));
    }
  }
  return dp_min[i];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int A, B; cin >> N >> A >> B;
  for(int i = 0; i < N; i++) cin >> Y[i];

  long long ans = (1LL << 41) - 1;
  for(int bit = 40; bit >= 0; bit--) {
    long long test = ans ^ (1LL << bit);
    bool pos = false;

    if(A == 1) {
      memset(dp_min, -1, sizeof dp_min);
      if(solve_min(0, test) <= B) {
        pos = true;
      }
    }
    else {
      memset(dp, -1, sizeof dp);
      for(int x = A; x <= B; x++) {
        if(solve(0, x, test)) {
          pos = true;
          break;
        }
      }
    }

    if(pos) {
      ans = test;
    }
  }

  cout << ans << endl;
}
