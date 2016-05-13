#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double T[200001];
double dp[51][200001];
double P[200001];
double I_P[200001];
int opt[51][200001];

inline double get_cost(int i, int j) {
  return dp[1][j] - dp[1][i - 1] - P[i - 1] * (I_P[j] - I_P[i - 1]);
}

void solve(int j, int L, int R, int search_start, int search_end) {
  if(j == 2 && (L + R)/2 >= 6) {
    int debug = 0;
  }
  if(L > R) return;

  int mid = (L + R)/2;
  dp[j][mid] = 1e15;

  int best_point = -1;
  for(int i = max(search_start, 1); i <= min(mid - 1, search_end); i++) {
    double curr = dp[j - 1][i] + get_cost(i + 1, mid);
    if(curr - dp[j][mid] <= 0.00001) {
      dp[j][mid] = curr;
      best_point = i;
    }
  }
  opt[j][mid] = best_point;

  solve(j, L, mid - 1, search_start, best_point);
  solve(j, mid + 1, R, best_point, search_end);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;
  for(int i = 1; i <= N; i++) cin >> T[i];

  for(int i = 1; i <= N; i++) {
    P[i] = P[i - 1] + T[i];
    I_P[i] = I_P[i - 1] + 1/T[i];
    dp[1][i] = dp[1][i - 1] + P[i]/T[i];
  }

  for(int j = 2; j <= K; j++) {
    solve(j, 1, N, 1, N);
  }

  cout << fixed << setprecision(10) << dp[K][N] << endl;
}
