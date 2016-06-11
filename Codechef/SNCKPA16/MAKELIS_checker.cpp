#include <iostream>
#include <algorithm>

using namespace std;

int dp[101];
int dp2[101];

int main() {
  int K; cin >> K;
  int N; cin >> N;

  if(N > 100) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int j = 0; j < N; j++) A.push_back(j);

  // do {
    int cnt = 0;
    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
      dp[i] = 1;
      for(int j = i + 1; j < N; j++) {
        if(A[i] < A[j]) dp[i] = max(dp[i], 1 + dp[j]);
      }
      ans = max(ans, dp[i]);
    }
    for(int i = N - 1; i >= 0; i--) {
      dp2[i] = 0;
      if(dp[i] == 1) {
        dp2[i] = 1;
        continue;
      }
      for(int j = i + 1; j < N; j++) {
        if(A[i] < A[j] && dp[i] == 1 + dp[j]) {
          dp2[i] += dp2[j];
        }
      }
    }
    for(int i = 0; i < N; i++) {
      if(dp[i] == ans) cnt += dp2[i];
    }
    // cout << cnt << endl;

    if(cnt == K) cout << 1 << endl;
    else cout << 0 << endl;
  //   if(cnt == K) {
  //     for(auto it: A) cout << (it + 1) << " "; cout << endl;
  //   }
  // } while(next_permutation(A.begin(), A.end()));
}

