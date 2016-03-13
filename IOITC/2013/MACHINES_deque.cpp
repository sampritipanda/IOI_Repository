#include <iostream>
#include <algorithm>
#include <climits>
#include <deque>

using namespace std;

long long A[300001][2];
long long dp[300001][2];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;

  for(int i = 1; i <= N; i++) {
    cin >> A[i][0];
    A[i][0] += A[i - 1][0];
  }
  for(int i = 1; i <= N; i++) {
    cin >> A[i][1];
    A[i][1] += A[i - 1][1];
  }

  deque<pair<long long, int> > D[2];   // { dp[i][j] - A[i][1 - j], i }
  D[0].push_back({0, 0}); D[1].push_back({0, 0});

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < 2; j++) {
      dp[i][j] = D[1 - j].front().first + A[i][j];
    }
    for(int j = 0; j < 2; j++) {
      if(D[j].front().second == i - K) D[j].pop_front();

      long long new_add = dp[i][j] - A[i][1 - j];
      while(!D[j].empty() && new_add <= D[j].back().first) D[j].pop_back();
      D[j].push_back({new_add, i});
    }
  }

  cout << min(dp[N][0], dp[N][1]) << endl;
}
