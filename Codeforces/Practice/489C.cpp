// Given Length and Sum of Digits

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int dp_1[101][901], dp_2[101][901];
int total_digits;

bool solve_min(int m, int s) {
  if(m == 0 && s == 0) return true;
  else if(m == 0 && s > 0) return false;

  if(dp_1[m][s] != -1) return dp_1[m][s];

  bool ans = false;
  for(int i = (m == total_digits ? 1 : 0); i <= 9; i++) {
    if(s - i < 0) continue;
    if(solve_min(m - 1, s - i)) {
      ans = true;
      break;
    }
  }

  dp_1[m][s] = ans;
  return ans;
}

bool solve_max(int m, int s) {
  if(m == 0 && s == 0) return true;
  else if(m == 0 && s > 0) return false;

  if(dp_2[m][s] != -1) return dp_2[m][s];

  bool ans = false;
  for(int i = 9; i >= (m == total_digits ? 1 : 0); i--) {
    if(s - i < 0) continue;

    if(solve_max(m - 1, s - i)) {
      ans = true;
      break;
    }
  }

  dp_2[m][s] = ans;
  return ans;
}

int main() {
  int m, s; cin >> m >> s;
  total_digits = m;

  memset(dp_1, -1, sizeof dp_1);
  memset(dp_2, -1, sizeof dp_2);

  if(s == 0) {
    if(m == 1) cout << 0 << " " << 0 << endl;
    else cout << -1 << " " << -1 << endl;
  }
  else {
    if(solve_min(m, s)) {
      string ans = "";
      int sum = 0;
      for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= 9; j++) {
          if(dp_1[i][sum + j] == 1) {
            ans += char('0' + j);
            sum += j;
            break;
          }
        }
      }
      reverse(ans.begin(), ans.end());
      cout << ans;
    }
    else cout << -1;

    cout << " ";

    if(solve_max(m, s)) {
      string ans = "";
      int sum = 0;
      for(int i = 1; i <= m; i++) {
        for(int j = 9; j >= 0; j--) {
          if(dp_2[i][sum + j] == 1) {
            ans += char('0' + j);
            sum += j;
            break;
          }
        }
      }
      reverse(ans.begin(), ans.end());
      cout << ans;
    }
    else cout << -1;

    cout << endl;
  }
}
