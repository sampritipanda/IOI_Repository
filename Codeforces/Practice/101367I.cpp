#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int K = 30;
double A[3001];
int N, T;
double dp[3001][31];

double solve(int i, int t) {
  if(i == N + 1) return 0;
  if(t == K) return 0;
  if(dp[i][t] != -1) return dp[i][t];

  double ans = 1e18;
  double p = 1.0, sum = 0.0, sum2 = 0.0;
  // j = char to check after
  for(int j = i; j <= N; j++) {
    sum += p * A[j];
    sum2 += p * A[j] * (solve(j, (j == i) ? (t + 1) : 0) - j);
    double curr = sum * (2 * j - i + T + 2) + sum2;
    p *= (1 - A[j]);
    curr += p * ((j - i + 1) + T + solve(j + 1, 0));
    ans = min(ans, curr);
  }
  return dp[i][t] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> T;
  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 1; i <= N; i++) {
    for(int t = 0; t <= K; t++) {
      dp[i][t] = -1;
    }
  }

  cout << fixed << setprecision(10) << solve(1, 0) << endl;
}

