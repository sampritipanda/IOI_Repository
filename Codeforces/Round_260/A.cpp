#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long A[100001];
long long dp[100001];

long long solve(int i) {
  if(i > 100000) return 0;
  if(dp[i] != -1) return dp[i];

  return dp[i] = max(solve(i + 1), i * A[i] + solve(i + 2));
}

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    A[x]++;
  }

  memset(dp, -1, sizeof dp);

  cout << solve(0) << endl;
}
