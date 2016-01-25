#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MOD 1000000007

string S;
int N;
long long dp[5001][5001];
int nxt[5001][5001];

bool check(int a, int b, int c, int d) {
  if(S[a] == '0' || S[c] == '0') return false;
  if(a == c && b == d) return false;

  int len_1 = b - a + 1, len_2 = d - c + 1;

  if(len_1 < len_2) return true;
  else if(len_1 > len_2) return false;
  else {
    int l = nxt[a][c];
    if(l >= len_1) return false;
    else if(S[a + l] < S[c + l]) return true;
    else return false;
  }
}

long long solve(int i, int j) {
  if(i > N) return 0;
  if(i == N) return 1;
  if(dp[i][j] != -1) return dp[i][j];

  long long ans = 0;
  ans += solve(i + 1, j);
  ans %= MOD;

  if(N - i >= i - j) {
    if(check(j, i - 1, i, i + (i - j) - 1)) ans += solve(i + (i - j), i);
    else if(check(j, i - 1, i, i + (i - j))) ans += solve(i + (i - j) + 1, i);
  }
  ans %= MOD;

  return dp[i][j] = ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  cin >> S;

  for(int i = 0; i <= 5000; i++) {
    for(int j = 0; j <= 5000; j++) {
      dp[i][j] = -1;
    }
  }

  for(int i = N - 1; i >= 0; i--) {
    for(int j = N - 1; j >= 0; j--) {
      if(S[i] != S[j]) nxt[i][j] = 0;
      else {
        nxt[i][j] = nxt[i + 1][j + 1] + 1;
      }
    }
  }

  cout << solve(1, 0) << endl;
}
