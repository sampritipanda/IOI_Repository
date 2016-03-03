#include <iostream>
#include <algorithm>

using namespace std;

int A[5000];
int dp[5000]; // dp[i] = Maximum sum increasing subsequence ending i

int main() {
  int N; cin >> N;

  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i < N; i++) {
    dp[i] = A[i];
    for(int j = 0; j < i; j++) {
      if(A[j] <= A[i]) {
        dp[i] = max(dp[i], A[i] + dp[j]);
      }
    }
  }

  int max_sum = 0;
  for(int i = 0; i < N; i++) max_sum = max(max_sum, dp[i]);

  int total = 0;
  for(int i = 0; i < N; i++) total += A[i];

  cout << total - max_sum << endl;
}
