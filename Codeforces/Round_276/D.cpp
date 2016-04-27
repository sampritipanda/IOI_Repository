#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int A[1000001];
long long dp[1000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  set<long long> minset, maxset;
  dp[N] = 0;
  dp[N - 1] = 0;
  minset.insert(A[N - 1]); maxset.insert(A[N - 1]);

  for(int i = N - 2; i >= 0; i--) {
    dp[i] = max(A[i] - *minset.begin(), *maxset.rbegin() - A[i]);
    dp[i] = max(dp[i], dp[i + 1]);
    minset.insert(A[i] - dp[i + 1]);
    maxset.insert(A[i] + dp[i + 1]);
  }
  cout << dp[0] << endl;
}
