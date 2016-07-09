#include <cstdio>
#include <algorithm>
#include <climits>
#include <deque>

using namespace std;

long long A[10000001];
long long dp[10000002];
long long dp2[10000002];
int N, K;
long long M;
deque<pair<long long, int> > Q;

int main() {
  scanf("%d %d %lld", &N, &K, &M);

  for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

  dp[0] = 0;
  Q.push_back({0, 0});

  for(int i = 1; i <= N; i++) {
    while(Q.front().second < (i - K)) Q.pop_front();
    dp[i] = A[i] + min(A[i], M - A[i]) + Q.front().first;
    while(!Q.empty() && Q.back().first >= dp[i]) Q.pop_back();
    Q.push_back({dp[i], i});
  }

  Q.clear();
  dp2[N + 1] = 0;
  Q.push_back({0, N + 1});
  for(int i = N; i >= 1; i--) {
    while(Q.front().second > (i + K)) Q.pop_front();
    dp2[i] = (M - A[i]) + min(A[i], M - A[i]) + Q.front().first;
    while(!Q.empty() && Q.back().first >= dp2[i]) Q.pop_back();
    Q.push_back({dp2[i], i});
  }

  long long ans = LLONG_MAX/2;
  for(int i = 0; i <= N; i++) {
    ans = min(ans, dp[i] + dp2[i + 1]);
  }
  printf("%lld\n", ans);
}
