#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dp[51][100001];
int N;
string S; 

// i..N for sum s
int solve(int i, int s) {
  if(i == N + 1) {
    if(s == 0) return -1;
    else return 1000000;
  }
  if(dp[i][s] != -1) return dp[i][s];

  int ans = 1000000;
  int curr_sum = 0;
  for(int j = i; j <= N; j++) {
    curr_sum = curr_sum * 10 + (S[j - 1] - '0');
    if(curr_sum > s) break;
    if(curr_sum <= s) ans = min(ans, 1 + solve(j + 1, s - curr_sum));
  }
  return dp[i][s] = ans;
}

int main(){
  cin >> N;
  cin >> S;

  for(int i = 0; i <= 50; i++) {
    for(int j = 0; j <= 100000; j++) {
      dp[i][j] = -1;
    }
  }

  int T; cin >> T;

  int ans = solve(1, T);
  if(ans == 1000000) ans = -1;

  cout << ans << endl;
}
