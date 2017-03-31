// Fighting the Zombie

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

double dp[21][401];

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int H, S; cin >> H >> S;
    double ans = 0.0;

    while(S--) {
      string S; cin >> S;
      string temp = ""; int i = 0;
      int X = 0, Y = 0, Z = 0;
      for(; S[i] != 'd'; i++) {
        temp += S[i];
      }
      X = stoi(temp);
      i++; temp = "";
      for(; S[i] != '+' && S[i] != '-' && i < S.length(); i++) {
        temp += S[i];
      }
      Y = stoi(temp);
      if(i < S.length()) {
        temp = "";
        for(; i < S.length(); i++) {
          temp += S[i];
        }
        Z = stoi(temp);
      }

      dp[0][0] = 1.0;
      for(int i = 1; i <= X; i++) {
        for(int j = 0; j <= X * Y; j++) {
          dp[i][j] = 0.0;
          for(int k = 1; k <= Y; k++) {
            if(j - k >= 0) {
              dp[i][j] += 1/double(Y) * dp[i - 1][j - k];
            }
          }
        }
      }

      H -= Z;

      double curr = 0.0;
      for(int i = 0; i <= X * Y; i++) {
        if(i >= H) curr += dp[X][i];
      }
      ans = max(ans, curr);

      H += Z;
    }

    cout << "Case #" << t << ": ";
    cout << fixed << setprecision(8) << ans << endl;
  }
}
