#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <cassert>

using namespace std;

const int MAX_N = 100000;
int dp[MAX_N + 1];
int nxt[MAX_N + 1];
int cnt[MAX_N + 1];
int F[101];

void solve(vector<int>& ans, int N, int &X) {
  while(true) {
    for(int i = X + nxt[N] - 1; i >= X; i--) {
      ans.push_back(i);
    }
    X += nxt[N];
    if(nxt[N] == N) break;
    N /= nxt[N];
  }
}

int main() {
  dp[0] = cnt[0] = 0;
  for(int i = 1; i <= MAX_N; i++) dp[i] = INT_MAX/2;
  for(int i = 1; i <= MAX_N; i++) {
    if(i <= dp[i]) {
      dp[i] = i; cnt[i] = 1; nxt[i] = i;
    }
    for(int j = i + i; j <= MAX_N; j += i) {
      int new_dp = dp[i] + j/i;
      int new_cnt = cnt[i] + 1;
      if(new_dp < dp[j] || (new_dp == dp[j] && new_cnt < cnt[j])) {
        dp[j] = new_dp;
        cnt[j] = new_cnt;
        nxt[j] = j/i;
      }
    }
  }

  int T; scanf("%d", &T);

  while(T--) {
    int K; scanf("%d", &K);

    int add = 0;
    for(int i = 1; i <= min(K - 1, 300); i++) {
      if(dp[i] + dp[K - i] < dp[add] + dp[K - add]) add = i;
    }

    vector<int> ans;
    if(cnt[add] > cnt[K - add]) {
      int extra = cnt[add] - cnt[K - add];
      int X = dp[add] + 1;
      solve(ans, K - add, X);
      for(int i = X; i <= X + extra - 1; i++) ans.push_back(i);
      X = 1;
      solve(ans, add, X);
    }
    else {
      int extra = (add == 0 ? 0 : cnt[K - add] - cnt[add]);
      int X = dp[add] + extra + 1;
      solve(ans, K - add, X);
      X = 1;
      solve(ans, add, X);
      for(int i = dp[add] + 1; i <= dp[add] + extra; i++) ans.push_back(i);
    }

    for(int i = 0; i <= 100; i++) F[i] = 0;
    for(int i = 0; i < ans.size(); i++) F[ans[i]]++;
    for(int i = 1; i <= ans.size(); i++) assert(F[i] == 1);

    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    printf("\n");
  }
}
