// MasterChef

#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cassert>

using namespace std;

int A[100010];
int min_cost[100010];
int segtree[400100], lazy[400100];
long long dp[100010][501];

void propagate(int i) {
  segtree[i] = min(segtree[i], lazy[i]);
  lazy[2*i + 1] = min(lazy[2*i + 1], lazy[i]);
  lazy[2*i + 2] = min(lazy[2*i + 2], lazy[i]);

  lazy[i] = INT_MAX/2;
}

void update(int seg_start, int seg_end, int i, int L, int R, long long val) {
  if(seg_start > seg_end) return;
  if(L > seg_end || R < seg_start) return;

  if(lazy[i] != INT_MAX/2) propagate(i);

  if(L <= seg_start && seg_end <= R) {
    lazy[i] = val;
    propagate(i);

    return;
  }

  int mid = seg_start + (seg_end - seg_start)/2;
  update(seg_start, mid, 2*i + 1, L, R, val);
  update(mid + 1, seg_end, 2*i + 2, L, R, val);

  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

long long query(int seg_start, int seg_end, int i, int L, int R) {
  if(seg_start > seg_end) return INT_MAX/2;
  if(L > seg_end || R < seg_start) return INT_MAX/2;

  if(lazy[i] != INT_MAX/2) propagate(i);

  if(L <= seg_start && seg_end <= R) return segtree[i];

  int mid = seg_start + (seg_end - seg_start)/2;

  return min(query(seg_start, mid, 2*i + 1, L, R), query(mid + 1, seg_end, 2*i + 2, L, R));
}

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    long long N, K, M; cin >> N >> K >> M;

    for(int i = 0; i <= 4*(N + 1); i++) {
      segtree[i] = INT_MAX/2;
      lazy[i] = INT_MAX/2;
    }

    long long total_sum = 0;
    for(int i = 1; i <= N; i++) {
      cin >> A[i];
      total_sum += A[i];
      A[i] = -A[i];
    }

    for(int i = 0; i < M; i++) {
      int L, R, C; cin >> L >> R >> C;

      update(1, N, 0, L, R, C);
    }

    for(int i = 1; i <= N; i++) {
      min_cost[i] = query(1, N, 0, i, i);
    }

    if(N <= 1000) {
      for(int j = 0; j <= K; j++) dp[0][j] = 0;

      for(int i = 1; i <= N; i++) {
        for(long long j = 0; j <= K; j++) {
          if(min_cost[i] <= j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - min_cost[i]] + A[i]);
          }
          else {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }

      total_sum += dp[N][K];
    }
    else {
      vector<pair<long long, long long> > knapsack;
      knapsack.push_back({0, 0});
      for(int i = 1; i <= N; i++) {
        if(A[i] > 0) knapsack.push_back({A[i], min_cost[i]});
      }

      int K_N = knapsack.size();

      for(int j = 0; j <= K; j++) dp[0][j] = 0;

      for(int i = 1; i <= K_N; i++) {
        for(long long j = 0; j <= K; j++) {
          if(knapsack[i].second <= j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - knapsack[i].second] + knapsack[i].first);
          }
          else {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }

      total_sum += dp[K_N][K];
    }

    cout << total_sum << endl;
  }
}
