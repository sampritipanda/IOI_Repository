#include <iostream>
#include <iomanip>
#include <algorithm>
#include <climits>

using namespace std;

double EPS = 0.0000001;

int E[101], S[101];
long long dp[101][101];
double dp2[101][101];

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int N, Q; cin >> N >> Q;
    for(int i = 1; i <= N; i++) cin >> E[i] >> S[i];
    // cout << "Case #" << t << ": " << fixed << setprecision(8) << ans << endl;

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        cin >> dp[i][j];
        if(dp[i][j] == -1) dp[i][j] = LLONG_MAX/2;
      }
    }

    for(int k = 1; k <= N; k++) {
      for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        dp2[i][j] = 1e15;
        if(dp[i][j] <= E[i]) dp2[i][j] = dp[i][j]/double(S[i]);
      }
    }

    for(int k = 1; k <= N; k++) {
      for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
          dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k][j]);
        }
      }
    }

    cout << fixed << setprecision(8);
    cout << "Case #" << t << ": ";
    while(Q--) {
      int u, v; cin >> u >> v;
      cout << dp2[u][v] << " ";
    }
    cout << endl;
  }
}
