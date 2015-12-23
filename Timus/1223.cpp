#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

long long dp[1001][1001]; // dp[i][j] = Min Experiments for i floors and j eggs

long long solve(int i, int j) {
  if(i == 0) return 0;
  if(j == 1) return i;
  if(j == 0) return INT_MAX;

  if(j >= int(ceil(log2(i + 1)))) return int(ceil(log2(i + 1)));

  if(dp[i][j] != -1) return dp[i][j];

  long long ans = i;
  for(int k = 2; k < i; k++) {
    long long curr = 0;
    curr = max(curr, 1 + solve(k - 1, j - 1));
    curr = max(curr, 1 + solve(i - k, j));
    ans = min(ans, curr);
  }

  return dp[i][j] = ans;
}

int main() {
  for(int i = 0; i <= 1000; i++) {
    for(int j = 0; j <= 1000; j++) {
      dp[i][j] = -1;
    }
  }

  while(true) {
    int N, M; cin >> N >> M;

    if(N == 0 && M == 0) break;

    cout << solve(M, N) << endl;
  }
}
