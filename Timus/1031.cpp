#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long A[10001];
long long dp[10001];

int main() {
  long long L1, L2, L3, C1, C2, C3; cin >> L1 >> L2 >> L3 >> C1 >> C2 >> C3;
  int N; cin >> N;
  int x, y; cin >> x >> y;
  if(x > y) swap(x, y);

  A[1] = 0;
  for(int i = 2; i <= N; i++) cin >> A[i];

  dp[y] = 0;
  for(int i = y - 1; i >= x; i--) {
    dp[i] = LLONG_MAX/100;
    for(int j = i + 1; j <= y; j++) {
      long long dist = A[j] - A[i];
      if(0 < dist && dist <= L1) {
        dp[i] = min(dp[i], C1 + dp[j]);
      }
      else if(L1 < dist && dist <= L2) {
        dp[i] = min(dp[i], C2 + dp[j]);
      }
      else if(L2 < dist && dist <= L3) {
        dp[i] = min(dp[i], C3 + dp[j]);
      }
    }
  }

  cout << dp[x] << endl;
}
