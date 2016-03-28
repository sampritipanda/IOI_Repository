#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define MOD 1000000007LL

string S;
long long dp[2000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;
  cin >> S;
  int M = S.length();

  vector<int> vis(26, false);
  deque<int> Q;
  for(int i = M - 1; i >= 0; i--) {
    int c = S[i] - 'a';
    if(!vis[c]) {
      Q.push_front(c);
      vis[c] = true;
    }
  }
  for(int i = 0; i < K; i++) {
    if(!vis[i]) {
      Q.push_front(i);
      vis[i] = true;
    }
  }

  for(int i = 0; i < N; i++) {
    S += char(Q.front() + 'a');
    Q.push_back(Q.front());
    Q.pop_front();
  }

  assert(S.length() == N + M);

  dp[0] = 1;
  int last[26];
  for(int i = 0; i < 26; i++) last[i] = -1;

  for(int i = 1; i <= N + M; i++) {
    int c = S[i - 1] - 'a';
    if(last[c] == -1) dp[i] = dp[i - 1];
    else dp[i] = dp[i - 1] - dp[last[c] - 1];

    while(dp[i] < 0) dp[i] += MOD;
    dp[i] %= MOD;

    dp[i] += dp[i - 1];
    dp[i] %= MOD;

    last[c] = i;
  }

  cout << dp[N + M] << endl;
}
