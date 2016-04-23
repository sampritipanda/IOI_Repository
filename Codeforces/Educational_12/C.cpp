#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

string S;
int N;
// dp[i][j] = min for i..N if prev char is j
int dp[200000][27];
int nxt[200000][27];

int solve(int i, int j) {
  if(i == N) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  dp[i][j] = INT_MAX/2;
  for(int k = 0; k < 26; k++) {
    if(k == j) continue;
    int add = (k == (S[i] - 'a') ? 0 : 1);
    int curr = add + solve(i + 1, k);

    if(curr < dp[i][j]) {
      dp[i][j] = curr;
      nxt[i][j] = k;
    }
  }

  return dp[i][j];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> S;

  N = S.length();

  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= 26; j++) {
      dp[i][j] = nxt[i][j] = -1;
    }
  }

  solve(0, 26);

  int i = 0, j = 26;
  while(i < N) {
    cout << char('a' + nxt[i][j]);
    j = nxt[i][j];
    i++;
  }
  cout << endl;
}
