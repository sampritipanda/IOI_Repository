#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N, S;
int T[1000001];
int dp[401][10001];

int solve(int i, int add) {
  if(i == N) return 0;
  if(dp[i][add] != -1) return dp[i][add];

  dp[i][add] = INT_MAX;
  // how many trains you gonna run together - (i..j)
  for(int j = i; j < N; j++) {
    int time_forward = max(j - i, T[j] - (T[i] + add)) + S;
    int tot_time = time_forward + (j - i + S);    // forward + backward
    int wait_time = (T[j + 1] - (T[i] + add)) - tot_time;
    int add_next = 0;
    if(wait_time < 0) {
      add_next = -wait_time;
      wait_time = 0;
    }
    dp[i][add] = min(dp[i][add], tot_time + wait_time + solve(j + 1, add_next));
  }

  return dp[i][add];
}

int main() {
  scanf("%d %d", &N, &S);
  for(int i = 0; i < N; i++) scanf("%d", &T[i]);
  T[N] = T[N - 1];

  memset(dp, -1, sizeof dp);

  printf("%d\n", T[0] + solve(0, 0));
}
