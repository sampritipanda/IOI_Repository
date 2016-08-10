#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

vector<int> A;
int dp[10001][3];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    bool found_0 = false;
    A.clear();

    for(int i = 0; i < N; i++) {
      int x; cin >> x;
      if(x == 0) found_0 = true;
      A.push_back(x);
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    if(!found_0) {
      cout << -1 << endl;
      continue;
    }

    dp[N][0] = 0;
    dp[N][1] = dp[N][2] = INT_MIN/2;

    for(int i = N - 1; i >= 0; i--) {
      for(int j = 0; j < 3; j++) {
        dp[i][j] = max(dp[i + 1][j], 1 + dp[i + 1][(j - A[i] + 9) % 3]);
      }
    }

    vector<int> ans;

    int j = 0;
    for(int i = 0; i < N; i++) {
      if(dp[i][j] == (1 + dp[i + 1][(j - A[i] + 9) % 3])) {
        ans.push_back(A[i]);
        j = (j - A[i] + 9) % 3;
      }
    }

    if(ans[0] == 0) {
      cout << 0 << endl;
    }
    else {
      for(auto x: ans) cout << x;
      cout << endl;
    }
  }
}
