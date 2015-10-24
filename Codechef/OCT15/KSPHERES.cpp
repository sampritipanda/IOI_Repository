// Spheres

#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define MOD 1000000007

map<int, long long> freq, freq2;
long long dp[1002][1002];
long long P[1002][1002];

int main() {
  memset(dp, 0, sizeof dp);
  memset(P, 0, sizeof P);

  ios::sync_with_stdio(false);

  int N, M, C; cin >> N >> M >> C;
  long long A[C + 1];
  for(int i = 0; i <= C; i++) A[i] = 0;

  while(N--) {
    int a; cin >> a; freq[a]++;
  }
  while(M--) {
    int a; cin >> a; freq2[a]++;
  }

  for(int i = 1; i <= C; i++) {
    A[i] = (freq[i] * freq2[i]) % MOD;
  }

  for(int i = 1; i <= C; i++) {
    dp[i][1] = A[i];
    P[i][1] = (P[i - 1][1] + A[i]) % MOD;
  }

  for(int k = 2; k <= C + 1; k++) {
    for(int i = 1; i <= C; i++) {
      dp[i][k] = (P[i - 1][k - 1] * A[i]) % MOD;
      P[i][k] = (P[i - 1][k] + dp[i][k]) % MOD;
    }
  }

  for(int k = 2; k <= C + 1; k++) {
    cout << P[C][k] << " ";
  }
  cout << endl;
}
