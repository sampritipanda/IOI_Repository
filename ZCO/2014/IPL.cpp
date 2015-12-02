#include <iostream>

using namespace std;

long long A[200001], dp[200001];

int N;

long long solve(int i) {
  if(i > N) return 0;
  if(dp[i] != -1) return dp[i];

  long long ans = max(A[i] + solve(i + 2), A[i] + A[i + 1] + solve(i + 3));
  ans = max(ans, solve(i + 1));
  return dp[i] = ans;
}

int main() {
  cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 0; i <= N; i++) dp[i] = -1;

  cout << solve(1) << endl;
}
