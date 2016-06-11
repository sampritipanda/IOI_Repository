#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

const int MAX_N = 200000;
int prv[MAX_N + 2];
int prv2[MAX_N + 2];
int nxt[MAX_N + 2];
int dp[MAX_N + 2];
bool start[MAX_N + 1];

long long criminalEstimate(int N, int M, int* A, int* B) {
  for(int i = 0; i <= N + 1; i++) {
    prv[i] = INT_MAX/2;
    prv2[i] = 0;
    nxt[i] = INT_MAX/2;
    dp[i] = 0;
  }

  for(int i = 0; i < M; i++) {
    prv[B[i]] = min(prv[B[i]], A[i]);
  }
  for(int i = N; i >= 1; i--) {
    prv[i] = min(prv[i], prv[i + 1]);
  }

  for(int i = 0; i < M; i++) {
    prv2[B[i]] = max(prv2[B[i]], A[i]);
  }
  for(int i = 1; i <= N; i++) {
    prv2[i] = max(prv2[i], prv2[i - 1]);
  }

  for(int i = 0; i < M; i++) {
    nxt[A[i]] = min(nxt[A[i]], B[i]);
    start[A[i]] = true;
  }
  for(int i = N; i >= 1; i--) {
    nxt[i] = min(nxt[i], nxt[i + 1]);
  }

  dp[0] = 0;

  for(int i = 1; i <= N; i++) {
    dp[i] = -1;
    prv[i] = min(prv[i], i);
    for(int j = prv2[prv[i] - 1]; j < prv[i]; j++) {
      if(dp[j] != -1 && 1 + dp[j] > dp[i] && nxt[j + 1] >= i) {
        dp[i] = 1 + dp[j];
      }
    }
  }

  int ans = -1;
  for(int i = N; i >= 1; i--) {
    ans = max(ans, dp[i]);
    if(start[i]) break;
  }
  return ans;
}
