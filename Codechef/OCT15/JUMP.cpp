// Jump mission 

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
long long P[300001], H[300001], A[300001];
long long dp[300001];

int main() {
  cin >> N;

  for(int i = 1; i <= N; i++) cin >> P[i];
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) cin >> H[i];
  for(int i = 1; i <= N; i++) dp[i] = LLONG_MAX;

  dp[1] = A[1];
  for(int i = 2; i <= N; i++) {
    for(int j = 1; j < i; j++) {
      if(P[j] < P[i]) {
        dp[i] = min(dp[i], A[i] + (H[i] - H[j]) * (H[i] - H[j]) + dp[j]);
      }
    }
  }

  cout << dp[N] << endl;
}
