// Kalila and Dimna in the Logging Industry

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long dp[100001];
long long A[100010];
long long B[100010];

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) cin >> B[i];

  dp[1] = 0;
  cout << 0 << " ";
  for(int i = 2; i <= N; i++) {
    dp[i] = LLONG_MAX/2LL;
    for(int j = 1; j < i; j++) {
      dp[i] = min(dp[i], dp[j] + A[i] * B[j]);
    }
    cout << dp[i] << " ";
  }
  cout << endl;
  cout << dp[N] << endl;
}
