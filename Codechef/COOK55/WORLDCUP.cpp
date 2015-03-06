// Strategy for the World Cup

#include <stdio.h>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

long long memo[1801][301][10];

long long solve(int R, int B, int L) {
  if(L < 0 || B < 0 || R < 0) return 0;
  if(R == 0 && B == 0) return 1;

  if(memo[R][B][L] != -1) return memo[R][B][L];

  long long num_ways = 0;
  num_ways = (num_ways + solve(R, B - 1, L)) % MOD;
  num_ways = (num_ways + solve(R, B - 1, L - 1)) % MOD;
  num_ways = (num_ways + solve(R - 4, B - 1, L)) % MOD;
  num_ways = (num_ways + solve(R - 6, B - 1, L)) % MOD;

  memo[R][B][L] = num_ways;
  return num_ways;
}

int main() {
  int T; scanf("%d", &T);
  for(int i = 0; i <= 1800; i++) {
    for(int j = 0; j <= 300; j++){
      for(int k = 0; k <= 9; k++){
        memo[i][j][k] = -1;
      }
    }
  }

  while(T--){
    int R, B, L; scanf("%d %d %d", &R, &B, &L);
    if(R > 1800) printf("0\n");
    else {
      printf("%lld\n", solve(R, B, L));
    }
  }
}
