#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

long long C[101][501], dp[101][501];
int best[101][501];
vector<int> steps;

int main() {
  int M, N; cin >> M >> N;

  for(int i = 1; i <= M; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> C[i][j];
    }
  }

  for(int i = 1; i <= N; i++) {
    dp[1][i] = C[1][i];
    best[1][i] = -1;
  }
  for(int i = 2; i <= M; i++) {
    for(int j = 1; j <= N; j++) {
      dp[i][j] = dp[i - 1][j] + C[i][j];
      best[i][j] = j;
    }
    for(int j = 1; j <= N; j++) {
      long long sum = C[i][j];
      for(int k = j + 1; k <= N; k++) {
        sum += C[i][k];
        if(sum + dp[i - 1][k] < dp[i][j]) {
          dp[i][j] = sum + dp[i - 1][k];
          best[i][j] = k;
        }
      }
      sum = C[i][j];
      for(int k = j - 1; k >= 1; k--) {
        sum += C[i][k];
        if(sum + dp[i - 1][k] < dp[i][j]) {
          dp[i][j] = sum + dp[i - 1][k];
          best[i][j] = k;
        }
      }
    }
  }

  long long ans = LLONG_MAX; int x = M, y = -1;
  for(int j = 1; j <= N; j++) {
    if(dp[M][j] < ans) {
      ans = dp[M][j];
      y = j;
    }
  }

  while(true) {
    steps.push_back(y);
    if(best[x][y] == -1) break;
    else if(best[x][y] == y) {
      y = best[x][y];
      x -= 1;
    }
    else {
      int change = (best[x][y] > y ? 1 : -1);
      for(int i = y + change; i != best[x][y]; i += change) steps.push_back(i);
      y = best[x][y];
    }
  }
  reverse(steps.begin(), steps.end());
  for(auto it: steps) cout << it << " ";
  cout << endl;
}
