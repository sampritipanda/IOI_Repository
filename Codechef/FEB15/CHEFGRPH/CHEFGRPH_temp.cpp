// Time to Study Graphs with Chef

#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

long long calc(long long curr, long long n, long long m){
  if(n == 0) n = 1;
  // return (curr - (long long)pow(m, n - 1));
  return curr;
}

int main() {
  int N, M, K; cin >> N >> M >> K;
  long long dp[N + 2][M];
  vector<pair<int, int> > incoming_edges[N + 2][M];

  for(int i = 0; i < K; i++){
    int e0, e1, e2, e3; cin >> e0 >> e1 >> e2 >> e3;
    incoming_edges[e2][e3].push_back({e0, e1});
  }

  dp[0][0] = 1;
  for(int i = 0; i < M; i++) dp[1][i] = 1;

  for(int i = 2; i <= N; i++){
    for(int j = 0; j < M; j++){
      dp[i][j] = 0;
      for(int k = 0; k < M; k++) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
      for(auto v: incoming_edges[i][j]) dp[i][j] = (dp[i][j] + dp[v.first][v.second]) % MOD;
    }
  }

  dp[N + 1][0] = 0;
  for(int i = 0; i < M; i++) {
    dp[N + 1][0] = (dp[N + 1][0] + dp[N][i]) % MOD;
  }
  for(auto v: incoming_edges[N + 1][0]) dp[N + 1][0] = (dp[N + 1][0] + dp[v.first][v.second]) % MOD;

  cout << dp[N + 1][0] << endl;
  for(int i = 0; i < N + 2; i++) cout << dp[i][0] << " ";
  cout << endl;
  for(int j = 0; j < M - 1; j++) {
    cout << "  ";
    for(int i = 1; i <= N; i++) cout << dp[i][1] << " ";
    cout << endl;
  }
}
