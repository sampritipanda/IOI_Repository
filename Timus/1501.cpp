#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int N;
int A[1001], B[1001];
long long dp[1001][1001][2];

long long find_best(long long a, long long b) {
  if(abs(a) > 1 && abs(b) > 1) return INT_MAX;
  else if(abs(a) > 1) return b;
  else if(abs(b) > 1) return a;
  else {
    if(abs(a) < abs(b)) return a;
    else return b;
  }
}

int main() {
  cin >> N;
  for(int i = 1; i <= N; i++) {
    char c; cin >> c;
    A[i] = c == '1' ? 1 : -1;
  }
  for(int i = 1; i <= N; i++) {
    char c; cin >> c;
    B[i] = c == '1' ? 1 : -1;
  }

  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= N; j++) {
      if(i == 0 && j == 0) dp[i][j][0] = dp[i][j][1] = 0;
      else {
        if(i == 0) dp[i][j][0] = INT_MAX;
        else {
          dp[i][j][0] = find_best(dp[i - 1][j][0] + A[i], dp[i - 1][j][1] + A[i]);
        }

        if(j == 0) dp[i][j][1] = INT_MAX;
        else {
          dp[i][j][1] = find_best(dp[i][j - 1][0] + B[j], dp[i][j - 1][1] + B[j]);
        }
      }
    }
  }

  int i = -1, j = -1, k = -1;
  if(abs(dp[N][N][0]) <= 1) i = N, j = N, k = 0;
  else if(abs(dp[N][N][1]) <= 1) i = N, j = N, k = 1;

  if(i == -1) cout << "Impossible" << endl;
  else {
    vector<int> ans;
    while(i > 0 && j > 0) {
      ans.push_back(k + 1);

      if(k == 0) {
        if(dp[i][j][k] == dp[i - 1][j][0] + A[i]) k = 0;
        else k = 1;

        i--;
      }
      else {
        if(dp[i][j][k] == dp[i][j - 1][0] + B[j]) k = 0;
        else k = 1;

        j--;
      }
    }

    while(i-- > 0) ans.push_back(1);
    while(j-- > 0) ans.push_back(2);

    reverse(ans.begin(), ans.end());

    for(auto it: ans) cout << it; cout << endl;
  }
}
