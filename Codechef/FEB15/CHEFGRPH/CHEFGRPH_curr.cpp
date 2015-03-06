// Time to Study Graphs with Chef

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

#define MOD 1000000007

using namespace std;

unsigned long long find_hash(pair<int, int> a){
  unsigned long long lx = 1, hash = 0;
  hash += a.first * lx;
  lx *= MOD;
  hash += a.second * lx;
  lx *= MOD;
  return hash;
}

int main() {
  int N, M, K; cin >> N >> M >> K;
  unordered_map<unsigned long long, vector<pair<int, int> > > incoming_edges;
  unordered_map<unsigned long long, bool> outgoing_edges;
  unordered_map<unsigned long long, long long> edge_values;

  for(int i = 0; i < K; i++){
    int e0, e1, e2, e3; cin >> e0 >> e1 >> e2 >> e3;
    incoming_edges[find_hash({e2, e3})].push_back({e0, e1});
    outgoing_edges[find_hash({e0, e1})] = true;
  }

  long long dp_prev[M], dp_curr[M];
  if(outgoing_edges[find_hash({0, 0})]) edge_values[find_hash({0, 0})] = 1;
  dp_prev[0] = 1;

  for(int i = 0; i < M; i++) {
    dp_curr[i] = 1;
    for(auto v: incoming_edges[find_hash({0, i})]) dp_curr[i] = (dp_curr[i] + edge_values[find_hash({v.first, v.second})]) % MOD;
  }
  for(int i = 0; i < M; i++) dp_prev[i] = dp_curr[i];

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
}
