#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int F[100000][2];
int P[1000001];
int dp[1000001];
map<int, int> M;

int prefix(int i, int j) {
  if(i == 0) return P[j];
  else return P[j] - P[i - 1];
}

int main() {
  int N; cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> F[i][0] >> F[i][1];
    M[F[i][0]] = i;
  }

  P[0] = M.count(0);
  for(int i = 1; i <= 1000000; i++) P[i] = P[i - 1] + M.count(i);

  dp[0] = 0;
  for(int i = 0; i <= 1000000; i++) {
    if(M.count(i) == 0) {
      dp[i] = dp[i - 1];
    }
    else {
      int p = F[M[i]][1];
      int l = max(0, i - p), r = i - 1;
      if(l == 0) dp[i] = prefix(l, r);
      else dp[i] = prefix(l, r) + dp[l - 1];
    }
  }

  int ans = INT_MAX;
  for(int i = 0; i <= 1000000; i++) {
    if(i == 0) ans = min(ans, prefix(i, 1000000));
    else ans = min(ans, prefix(i, 1000000) + dp[i - 1]);
  }
  ans = min(ans, dp[1000000]);
  cout << ans << endl;
}
