#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int h;
int dp[32];

int height(int x) {
  for(int i = 0; i < 32; i++) {
    if(x & (1 << i)) return i;
  }
  return 0;
}

int solve(int x) {
  int s = 0;
  int ans = 0;
  for(int i = h - 1; i >= 0; i--) {
    if(x & (1 << i)) {
      ans += height(s) - 1;
      ans += dp[i];
      s += (1 << i);
    }
  }
  return ans;
}

int main() {
  int A, B; cin >> A >> B;

  h = ceil(log2(double(max(A, B)) + 1.0));

  dp[0] = 0;
  for(int i = 1; i < h; i++) dp[i] = dp[i - 1] + (i - 2) + dp[i - 1] + 1;

  if(A > B) swap(A, B);

  cout << solve(B) - solve(A) << endl;
}
