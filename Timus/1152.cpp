#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long dp[1 << 20];
int A[20];

int N;

void print_mask(int mask) {
  for(int i = 0; i < N; i++) {
    if(mask & (1 << i)) cout << 1;
    else cout << 0;
  }
  cout << endl;
}

long long solve(int mask) {
  if(mask == (1 << N) - 1) return 0;
  if(dp[mask] != -1) return dp[mask];

  long long ans = INT_MAX;
  for(int i = 0; i < N; i++) {
    if(mask & (1 << i)) continue;

    int new_mask = mask;
    new_mask |= (1 << i);
    if(i == 0) new_mask |= (1 << (N - 1));
    else new_mask |= (1 << (i - 1));

    if(i == N - 1) new_mask |= (1 << 0);
    else new_mask |= (1 << (i + 1));

    int dmg = 0;
    for(int j = 0; j < N; j++) {
      if(!(new_mask & (1 << j))) dmg += A[j];
    }
    ans = min(ans, dmg + solve(new_mask));
  }

  return dp[mask] = ans;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int mask = 0; mask < (1 << N); mask++) {
    dp[mask] = -1;
  }

  cout << solve(0) << endl;
}
