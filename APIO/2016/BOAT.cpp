#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>

#define MOD 1000000007LL

using namespace std;

int A[500], B[500];
vector<int> T;
int start_i[500], end_i[500];
long long dp[501][1000 + 10];
long long pre_inv[501];

long long modpow(long long base, long long exp) {
  long long res = 1;

  while(exp) {
    if(exp & 1) res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    T.push_back(A[i]);
    T.push_back(B[i] + 1);
  }

  for(int i = 1; i <= N; i++) {
    pre_inv[i] = modpow(i, MOD - 2);
  }

  sort(T.begin(), T.end());
  T.resize(unique(T.begin(), T.end()) - T.begin());

  int M = T.size();

  for(int i = 0; i < N; i++) {
    start_i[i] = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
    end_i[i] = upper_bound(T.begin(), T.end(), B[i]) - T.begin();
  }

  for(int j = 0; j < M; j++) dp[N][j] = 1;

  for(int i = N - 1; i >= 0; i--) {
    for(int j = start_i[i]; j < end_i[i]; j++) {
      int len = T[j + 1] - T[j];

      dp[i][j] += len * dp[i + 1][j + 1];
      dp[i][j] %= MOD;

      int cnt = 1;
      long long curr = len - 1;
      for(int k = i + 1; k < N; k++) {
        if(start_i[k] <= j && j < end_i[k]) {
          cnt++;
          curr = (curr * (len + cnt - 2)) % MOD;
          curr = (curr * pre_inv[cnt]) % MOD;
          dp[i][j] += curr * dp[k + 1][j + 1];
          dp[i][j] %= MOD;
        }
      }
    }

    for(int j = M - 1; j >= 0; j--) {
      dp[i][j] += dp[i][j + 1];
      dp[i][j] %= MOD;
    }
    for(int j = M - 1; j >= 0; j--) {
      dp[i][j] += dp[i + 1][j];
      dp[i][j] %= MOD;
    }
  }

  cout << (dp[0][0] - 1 + MOD) % MOD << endl;

  // for(int j = 0; j < M; j++) cout << setw(5) << T[j];
  // cout << endl << endl;
  // for(int i = 0; i < N; i++) {
  //   for(int j = 0; j < M; j++) {
  //     cout << setw(5) << dp[i][j];
  //   }
  //   cout << endl;
  // }
}
