#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int dp[901][8101];
int dig[901][8101];

int main() {
  ios::sync_with_stdio(false);

  dp[0][0] = 1;
  dig[0][0] = 0;

  for(int s1 = 1; s1 <= 900; s1++) {    // s1 = Sum of digits
    for(int s2 = 1; s2 <= 8100; s2++) {  // s2 = Sum of squares of digits
      for(int d = 1; d <= 9; d++) {
        if(s1 - d >= 0 && s2 - d*d >= 0 && dp[s1 - d][s2 - d*d]) {
          if(dp[s1][s2] == 0 || dp[s1][s2] > 1 + dp[s1 - d][s2 - d*d]) {
            dp[s1][s2] = 1 + dp[s1 - d][s2 - d*d];
            dig[s1][s2] = d;
          }
        }
      }
    }
  }

  int T; cin >> T;

  while(T--) {
    int s1, s2; cin >> s1 >> s2;

    if(!dp[s1][s2] || s1 > 900 || s2 > 8100) {
      cout << "No solution" << endl;
    }
    else {
      vector<int> ans;
      while(s1 != 0 && s2 != 0) {
        int d = dig[s1][s2];
        ans.push_back(d);
        s1 -= d; s2 -= d*d;
      }
      sort(ans.begin(), ans.end());

      if(ans.size() > 100) cout << "No solution" << endl;
      else {
        for(auto d: ans) cout << d; cout << endl;
      }
    }
  }
}
