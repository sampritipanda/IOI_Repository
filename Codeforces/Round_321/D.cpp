#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> A;
vector<pair<pair<int, int>, int> > rules;
int C[19][19];
long long dp[19][1 << 18];
int N, M, K;

long long solve(int last, int mask) {
  if(__builtin_popcount(mask) == M) return 0;
  if(dp[last][mask] != -1) return dp[last][mask];

  long long ans = 0;
  for(int i = 0; i < N; i++) {
    if(mask & (1 << i)) continue;
    ans = max(ans, solve(i, mask | (1 << i)) + A[i] + C[last][i]);
  }
  return dp[last][mask] = ans;
}

int main() {
  cin >> N >> M >> K;

  A.resize(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  memset(C, 0, sizeof C);
  memset(dp, -1, sizeof dp);

  for(int i = 0; i < K; i++) {
    int x, y, c; cin >> x >> y >> c;
    x--; y--;
    C[x][y] = c;
  }

  cout << solve(18, 0) << endl;
}
