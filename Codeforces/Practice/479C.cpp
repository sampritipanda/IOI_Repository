// Exams

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

vector<pair<int, int> > A;
int N;
int dp[5000][2];

int solve(int i, int day) {
  int prev_d = (day == 0 ? A[i].first : A[i].second);

  if(i == N - 1) return prev_d;
  if(dp[i][day] != -1) return dp[i][day];

  int ans = INT_MAX;
  if(A[i + 1].first >= prev_d) ans = min(ans, solve(i + 1, 0));
  if(A[i + 1].second >= prev_d) ans = min(ans, solve(i + 1, 1));

  return dp[i][day] = ans;
}

int main() {
  cin >> N;
  A.resize(N);

  for(int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    A[i] = {a, b};
  }

  memset(dp, -1, sizeof dp);

  sort(A.begin(), A.end());

  cout << min(solve(0, 0), solve(0, 1)) << endl;
}
