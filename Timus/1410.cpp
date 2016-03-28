#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> A;
int N;
int dp[10001][2];

int solve(int i, int j) {
  if(i == N) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  int ans = 0;

  ans = max(ans, solve(i + 1, 0));
  if(j == 0) ans = max(ans, (int)A[i].size() + solve(i + 1, 1));

  return dp[i][j] = ans;
}

int main() {
  for(int i = 0; i <= 10000; i++) dp[i][0] = dp[i][1] = -1;

  while(!cin.eof()) {
    string S; cin >> S;

    string curr = "";

    for(char c: S) {
      c = tolower(c);
      if(c >= 'a' && c <= 'z') curr += c;
      else {
        if(curr != "") A.push_back(curr);
        curr = "";
      }
    }

    if(curr != "") A.push_back(curr);
  }
  N = A.size();

  cout << solve(0, 0) << endl;
}
