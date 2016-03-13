#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

long long X[200002];
long long P[200002];
long long dp[200002];
vector<pair<long long, long long> > temp;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  long long D, V; cin >> D >> V;

  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    cin >> X[i] >> P[i];
    temp.push_back({X[i], P[i]});
  }
  sort(temp.begin(), temp.end());

  for(int i = 1; i <= N; i++) {
    X[i] = temp[i - 1].first;
    P[i] = temp[i - 1].second;
  }

  X[0] = 0; P[0] = 0;
  X[N + 1] = D; P[N + 1] = 0;

  dp[N + 1] = 0;

  for(int i = N; i >= 1; i--) {
    dp[i] = LLONG_MAX/2;
    int end = upper_bound(X, X + N + 2, X[i] + V) - X - 1;
    for(int j = i + 1; j <= end; j++) {
      dp[i] = min(dp[i], (X[j] - X[i]) * P[i] + dp[j]);
    }
  }

  dp[0] = LLONG_MAX/2;
  for(int i = 1; i <= N + 1; i++) {
    if(X[i] > V) break;

    dp[0] = min(dp[0], max(0LL, dp[i] - (V - X[i]) * P[i]));
  }

  if(dp[0] > LLONG_MAX/1000) dp[0] = -1;
  cout << dp[0] << endl;
}
