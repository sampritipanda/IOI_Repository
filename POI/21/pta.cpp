#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int D[1000001];
int dp[1000001];
deque<int> DQ;

int main() {
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%d", &D[i]);

  int Q; scanf("%d", &Q);

  while(Q--) {
    int K; scanf("%d", &K);

    DQ.clear();
    dp[N] = 0;
    DQ.push_back(N);

    for(int i = N - 1; i >= 1; i--) {
      while(DQ.front() > i + K) DQ.pop_front();
      int mn = DQ.front();

      if(D[mn] < D[i]) dp[i] = dp[mn];
      else dp[i] = 1 + dp[mn];

      while(!DQ.empty() && dp[i] < dp[DQ.back()]) DQ.pop_back();
      while(!DQ.empty() && dp[i] == dp[DQ.back()] && D[i] <= D[DQ.back()]) DQ.pop_back();
      DQ.push_back(i);
    }

    printf("%d\n", dp[1]);
  }
}
