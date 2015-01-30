// Here there be Dragons

#include <stdio.h>
#include <cmath>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

long long find_distance(pair<long long, long long>& source, pair<long long, long long>& dest){
  return (abs(dest.first - source.first) + abs(dest.second - source.second));
}

int main() {
  int R, C, K, D; scanf("%d %d %d %d", &R, &C, &K, &D);
  vector<pair<long long, long long> > dragons;
  dragons.push_back(make_pair(0, 0));
  for(int i = 0; i < D; i++){
    long long r, c; scanf("%lld %lld", &r, &c);
    dragons.push_back(make_pair(r, c));
  }
  sort(dragons.begin(), dragons.end());

  long long dp[D + 1][K + 1];
  for(int i = 0; i <= D; i++){
    for(int k = 0; k <= K; k++){
      dp[i][k] = LLONG_MAX/2;
    }
  }
  for(int i = 0; i <= D; i++) dp[i][0] = 0;

  for(int i = D - 1; i >= 0; i--){
    for(int k = 1; k <= K; k++){
      for(int j = i + 1; j <= D; j++){
        dp[i][k] = min(dp[i][k], dp[j][k - 1] + find_distance(dragons[i], dragons[j]));
      }
    }
  }

  printf("%lld\n", dp[0][K]);
}
