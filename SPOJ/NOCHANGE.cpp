#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];
int V[5];
int K;

int solve(int i) {
  if(i == 0) return 1;
  if(i < 0) return 0;

  if(dp[i] != -1) return dp[i];

  int s = 0;
  int ans = 0;
  for(int j = 0; j < K; j++) {
    s += V[j];
    if(solve(i - s)) {
      ans = 1; break;
    }
  }
  return dp[i] = ans;
}

int main() {
  int X; cin >> X;
  cin >> K;
  for(int i = 0; i < K; i++) cin >> V[i];

  for(int i = 0; i <= 100000; i++) dp[i] = -1;

  cout << (solve(X) ? "YES" : "NO") << endl;
}
