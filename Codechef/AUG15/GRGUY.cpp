#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

string L1, L2;
int N;

bool dp_possible[2][2000001];
int dp_best[2][2000001];

int main() {
  int T; cin >> T;

  while(T--) {
    cin >> L1 >> L2;

    N = L1.length();

    for(int i = 0; i <= N; i++) dp_possible[0][i] = dp_possible[1][i] = false;

    if(L1[N - 1] == '.') dp_possible[0][N - 1] = true;
    if(L2[N - 1] == '.') dp_possible[1][N - 1] = true;
    dp_best[0][N - 1] = dp_best[1][N - 1] = 0;

    for(int i = N - 2; i >= 0; i--) {
      if(L1[i] == '.') {
        if(dp_possible[0][i + 1]) dp_possible[0][i] = true, dp_best[0][i] = dp_best[0][i + 1];
        else if(dp_possible[1][i + 1]) {
          dp_possible[0][i] = true;
          dp_best[0][i] = 1 + dp_best[1][i + 1];
        }
      }

      if(L2[i] == '.') {
        if(dp_possible[1][i + 1]) dp_possible[1][i] = true, dp_best[1][i] = dp_best[1][i + 1];
        else if(dp_possible[0][i + 1]) {
          dp_possible[1][i] = true;
          dp_best[1][i] = 1 + dp_best[0][i + 1];
        }
      }

      if(L1[i] == '.' && !dp_possible[0][i] && dp_possible[1][i]) {
        dp_possible[0][i] = true;
        dp_best[0][i] = 1 + dp_best[1][i];
      }

      if(L2[i] == '.' && !dp_possible[1][i] && dp_possible[0][i]) {
        dp_possible[1][i] = true;
        dp_best[1][i] = 1 + dp_best[0][i];
      }
    }

    if(!dp_possible[0][0]) dp_best[0][0] = INT_MAX;
    if(!dp_possible[1][0]) dp_best[1][0] = INT_MAX;

    if(dp_possible[0][0] || dp_possible[1][0]) cout << "Yes" << endl << min(dp_best[0][0], dp_best[1][0]) << endl;
    else cout << "No" << endl;
  }
}
