#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

#define MOD 1000000009

vector<int> primes;
map<int, vector<int> > M;
long long dp[10001][100];

// dp[i][j] = Number of i + 2 numbers with the first 2 digits j

inline bool check(int i) {
  if(i == 0) return true;
  if(i % 10 == 0) return false;
  else return check(i/10);
}

inline bool prime(int i) {
  if(i == 1) return false;

  for(int j = 2; j*j <= i; j++) {
    if(i % j == 0) return false;
  }
  return true;
}

int main() {
  memset(dp, 0, sizeof dp);

  int N; cin >> N;

  if(N == 3) {
    cout << 143 << endl;
    return 0;
  }

  for(int i = 100; i <= 999; i++) {
    if(check(i) && prime(i)) {
      primes.push_back(i);
      M[i/10].push_back(i % 10);
    }
  }

  for(auto it: M) {
    dp[1][it.first] = it.second.size();
  }

  for(int i = 2; i <= N - 2; i++) {
    for(auto it: M) {
      for(auto j: it.second) {
        dp[i][it.first] += dp[i - 1][(it.first % 10) * 10 + j];
        dp[i][it.first] %= MOD;
      }
    }
  }

  long long ans = 0;
  for(auto it: M) {
    ans += dp[N - 2][it.first];
    ans %= MOD;
  }
  cout << ans << endl;
}

