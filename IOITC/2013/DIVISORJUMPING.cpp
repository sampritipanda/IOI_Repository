#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int A[501][501];
long long dp[501][501];
vector<int> divisors[501];

int gcd(int a, int b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  int Q; cin >> Q;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> A[i][j];
      dp[i][j] = LLONG_MIN/1000;
    }
  }

  for(int i = 1; i <= 500; i++) {
    for(int j = 1; j <= i; j++) {
      if(i % j == 0) divisors[i].push_back(j);
    }
  }

  for(int i = 0; i < N;i++) {
    for(int j = 0; j < M; j++) {
      if(i == 0 && j == 0) dp[0][0] = A[0][0];
      else {
        int g = gcd(i, j);
        for(auto d: divisors[g]) {
          if(i - d >= 0) dp[i][j] = max(dp[i][j], dp[i - d][j] + A[i][j]);
          if(j - d >= 0) dp[i][j] = max(dp[i][j], dp[i][j - d] + A[i][j]);
          if(i - d >= 0 && j - d >= 0) dp[i][j] = max(dp[i][j], dp[i - d][j - d] + A[i][j]);
        }
      }
    }
  }

  while(Q--) {
    int x, y; cin >> x >> y;
    cout << dp[x][y] << endl;
  }
}
