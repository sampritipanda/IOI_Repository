// Boredom

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long A[100001];
long long dp[100001];

long long solve(int i) {
  if(i <= 0) return 0;
  if(dp[i] != -1) return dp[i];

  return dp[i] = max(A[i] * i + solve(i - 2), solve(i - 1));
}

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    int a; cin >> a;
    A[a]++;
  }

  memset(dp, -1, sizeof dp);

  cout << solve(100000) << endl;
}
