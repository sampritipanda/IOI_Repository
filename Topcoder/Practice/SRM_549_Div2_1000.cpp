#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

int N;
int G_mask[20];
int dp[1 << 20];

int solve(int mask) {
  if(mask == (1 << N) - 1) return 0;
  if(dp[mask] != -1) return dp[mask];

  int ans = INT_MAX/2;
  for(int i = 0; i < N; i++) {
    if(mask & (1 << i)) continue;
    int nxt_mask = mask | (1 << i);
    ans = min(ans, __builtin_popcount(nxt_mask & G_mask[i]) + solve(nxt_mask));
  }

  return dp[mask] = ans;
}

class OrderOfTheHats {
  public:
  int minChanged(vector <string> spellChart) {
    memset(G_mask, 0, sizeof G_mask);
    N = spellChart.size();
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if(spellChart[i][j] == 'Y') {
          G_mask[i] |= (1 << j);
        }
      }
    }

    memset(dp, -1, sizeof dp);
    return solve(0);
  }
};

int main() {
  OrderOfTheHats test;
  cout << test.minChanged({"NYN", "NNY", "NNN"}) << endl;
}
