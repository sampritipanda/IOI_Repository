#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

long long dp[101][101];
long long cnt[101][101];

int main() {
  int N, M; cin >> N >> M;

  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= N; j++) {
      dp[i][j] = LLONG_MAX/2;
      cnt[i][j] = 0;
    }
  }

  for(int i = 1; i <= N; i++) {
    dp[i][i] = 0;
    cnt[i][i] = 1;
  }

  while(M--) {
    int a, b, c; cin >> a >> b >> c;
    dp[a][b] = c;
    dp[b][a] = c;
    cnt[a][b] = 1;
    cnt[b][a] = 1;
  }

  for(int k = 1; k <= N; k++) {
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        if(i == j) continue;
        if(i == k || j == k) continue;

        if(dp[i][k] + dp[k][j] < dp[i][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
          cnt[i][j] = 0;
        }
        if(dp[i][k] + dp[k][j] == dp[i][j]) {
          cnt[i][j] += cnt[i][k] * cnt[k][j];
        }
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    double ans = 0;
    for(int s = 1; s <= N; s++) {
      for(int v = 1; v <= N; v++) {
        if(s == i || v == i) continue;

        long long cnt1 = 0, cnt2 = cnt[s][v];
        if(dp[s][v] == dp[s][i] + dp[i][v]) {
          cnt1 = cnt[s][i] * cnt[i][v];
        }
        ans += cnt1/double(cnt2);
      }
    }
    printf("%.6f\n", ans);
  }
}
