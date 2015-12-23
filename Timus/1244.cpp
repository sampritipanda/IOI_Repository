#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char dp[100001][101];
char used[100001][101];
int A[101];

int main() {
  memset(dp, 0, sizeof dp);
  memset(used, 0, sizeof used);

  int S; cin >> S;

  int total = 0;
  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    total += A[i];
  }
  S = total - S;

  for(int i = 0; i <= N; i++) dp[0][i] = 1;

  for(int i = 1; i <= S; i++) {
    for(int j = 1; j <= N; j++) {
      if(i - A[j] >= 0) {
        if(dp[i - A[j]][j - 1] > 0) {
          dp[i][j] += dp[i - A[j]][j - 1];
          used[i][j] = 1;
        }
      }
      dp[i][j] += dp[i][j - 1];

      if(dp[i][j] > 100) dp[i][j] = 2;
    }
  }

  int state = 0;
  for(int i = 1; i <= N; i++) {
    if(dp[S][i] == 1) {
      state = 1;
    }
    if(dp[S][i] > 1) {
      state = -1; break;
    }
  }

  if(state == 0) cout << 0 << endl;
  else if(state == -1) cout << -1 << endl;
  else {
    vector<vector<int> > combs;
    for(int i = 1; i <= 100; i++) {
      if(dp[S][i]) {
        combs.push_back({});
        int curr = S;
        for(int j = i; j >= 1; j--) {
          if(used[curr][j]) {
            combs.back().push_back(j);
            curr -= A[j];
          }
        }
        sort(combs.back().begin(), combs.back().end());
      }
    }
    unique(combs.begin(), combs.end());

    if(combs.size() >= 0) {
      for(int i = 0; i < combs[0].size(); i++) {
        if(i > 0) cout << " ";
        cout << combs[0][i];
      }
      cout << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
}
