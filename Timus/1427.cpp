#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int A, B;
int N;
string S;
int dp[100001];
int nex[100001];

int solve(int i) {
  if(i == N) return 0;
  if(dp[i] != -1) return dp[i];

  int ans = 100000000;
  if(nex[i] != -1) ans = min(ans, 1 + solve(min(nex[i] + 1, i + B)));
  ans = min(ans, 1 + solve(min(i + A, N)));

  return dp[i] = ans;
}

int main() {
  cin >> A >> B;
  getchar();
  getline(cin, S);
  N = S.length();

  int last = -1;
  for(int i = N - 1; i >= 0; i--) {
    if(!isalpha(S[i]) && S[i] != ' ') {
      last = -1;
    }
    else {
      if(last == -1) last = i;
    }

    nex[i] = last;
  }

  for(int i = 0; i <= N; i++) dp[i] = -1;

  cout << solve(0) << endl;
}
