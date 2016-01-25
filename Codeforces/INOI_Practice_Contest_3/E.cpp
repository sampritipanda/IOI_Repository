#include <iostream>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

map<long long, int> dp;
vector<vector<int> > G;
int ans;
int N;

void solve1(int i, long long mask, int steps) {
  if(i == N/2) {
    if(dp.count(mask) == 0 || steps < dp[mask]) dp[mask] = steps;
    return;
  }

  long long new_mask = mask;
  for(auto v: G[i]) {
    new_mask ^= (1LL << v);
  }
  new_mask ^= (1LL << i);

  solve1(i + 1, new_mask, steps + 1);
  solve1(i + 1, mask, steps);
}

void solve2(int i, long long mask, int steps) {
  if(i == N) {
    long long flip_mask = ((1LL << N) - 1) ^ mask;
    if(dp.count(flip_mask) > 0) ans = min(ans, steps + dp[flip_mask]);
    return;
  }

  long long new_mask = mask;
  for(auto v: G[i]) {
    new_mask ^= (1LL << v);
  }
  new_mask ^= (1LL << i);
  solve2(i + 1, new_mask, steps + 1);
  solve2(i + 1, mask, steps);
}

int main() {
  int M; cin >> N >> M;

  G.resize(N);

  while(M--) {
    int A, B; cin >> A >> B; A--; B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  ans = INT_MAX;

  solve1(0, 0, 0);
  solve2(N/2, 0, 0);

  cout << ans << endl;
}
