#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int A[301][301];
int dp[301][301];
vector<pair<int, int> > P_M[90001];
int S[4];   // Top-left, Top-right, Bottom-right, Bottom-left;
int N, M, P; 

void update(int i, int j) {
  S[0] = min(S[0], -dp[i][j] + i - 1 + j - 1);
  S[1] = min(S[1], -dp[i][j] + abs(i - 1) + abs(j - M));
  S[2] = min(S[2], -dp[i][j] + abs(i - N) + abs(j - M));
  S[3] = min(S[3], -dp[i][j] + abs(i - N) + abs(j - 1));
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M >> P;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[i][j];
      P_M[A[i][j]].push_back({i, j});
    }
  }

  for(int i = 0; i < 4; i++) S[i] = INT_MAX/2;

  for(auto it: P_M[1]) {
    int i = it.first, j = it.second;
    dp[i][j] = i - 1 + j - 1;

    update(i, j);
  }

  for(int p = 2; p <= P; p++) {
    for(auto it: P_M[p]) {
      int i = it.first, j = it.second;

      dp[i][j] = INT_MAX/2;
      dp[i][j] = min(dp[i][j], -S[0] + (abs(i - 1) + abs(j - 1)));
      dp[i][j] = min(dp[i][j], -S[1] + (abs(i - 1) + abs(j - M)));
      dp[i][j] = min(dp[i][j], -S[2] + (abs(i - N) + abs(j - M)));
      dp[i][j] = min(dp[i][j], -S[2] + (abs(i - N) + abs(j - 1)));
    }

    for(int i = 0; i < 4; i++) S[i] = INT_MAX;
    for(auto it: P_M[p]) {
      int i = it.first, j = it.second;
      update(i, j);
    }
  }

  cout << dp[P_M[P][0].first][P_M[P][0].second] << endl;
}
