#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

int A[100001];
map<int, int> T;
vector<int> I[100001];
long long dp[100001][2];   // dp[i][0] = Min time to water 1..i ending on left, dp[i][1] = ending on right

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    T[A[i]] = 0;
  }

  int M = 0;
  for(auto it: T) T[it.first] = ++M;

  for(int i = 1; i <= N; i++) A[i] = T[A[i]];
  for(int i = 1; i <= N; i++) I[A[i]].push_back(i);

  dp[0][0] = dp[0][1] = 0;
  I[0].push_back(1);

  for(int i = 1; i <= M; i++) {
    int L = *I[i].begin(), R = *I[i].rbegin();
    int pL = *I[i - 1].begin(), pR = *I[i - 1].rbegin();
    int cnt = I[i].size();

    dp[i][0] = min(dp[i - 1][0] + abs(R - pL) + abs(L - R), dp[i - 1][1] + abs(R - pR) + abs(L - R)) + cnt;
    dp[i][1] = min(dp[i - 1][0] + abs(L - pL) + abs(R - L), dp[i - 1][1] + abs(L - pR) + abs(R - L)) + cnt;
  }

  cout << min(dp[M][0], dp[M][1]) << endl;
}
