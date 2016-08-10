#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int up[2000005];  // Travel upstream from here
int down[2000005]; // Travel downstream from here
vector<pair<int, int> > A[500002];  // A[T] => {L, M}
int dp[500000];
int dp2[500000];

const int MAX = 500000;

void update(int segtree[], int L, int R, int i, int ind, int v) {
  if(L == R) {
    segtree[i] = v;
    return;
  }

  int mid = (L + R)/2;
  if(ind <= mid) {
    update(segtree, L, mid, 2*i + 1, ind, v);
  }
  else {
    update(segtree, mid + 1, R, 2*i + 2, ind, v);
  }
  segtree[i] = max(segtree[2*i + 1], segtree[2*i + 2]);
}

int query(int segtree[], int L, int R, int i, int qL, int qR) {
  if(L > qR || R < qL) return INT_MIN/2;
  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return max(query(segtree, L, mid, 2*i + 1, qL, qR), query(segtree, mid + 1, R, 2*i + 2, qL, qR));
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, U, D, S; cin >> N >> U >> D >> S;

  for(int i = 0; i < MAX * 4 + 5; i++) up[i] = down[i] = INT_MIN/2;

  for(int i = 0; i < N; i++) {
    int T, L, M; cin >> T >> L >> M;
    A[T].push_back({L, M});
  }

  A[0].push_back({S, 0});
  A[MAX + 1].push_back({S, 0});

  update(up, 1, MAX + 1, 0, S, -U * S);
  update(down, 1, MAX + 1, 0, S, D * S);

  for(int i = 1; i <= MAX + 1; i++) {
    if(A[i].size() == 0) continue;

    sort(A[i].begin(), A[i].end());

    int max_till_now = INT_MIN/2;
    for(int j = 0; j < A[i].size(); j++) {
      dp[j] = max(query(up, 1, MAX + 1, 0, A[i][j].first, MAX + 1) + U * A[i][j].first + A[i][j].second, query(down, 1, MAX + 1, 0, 1, A[i][j].first) - D * A[i][j].first + A[i][j].second);
      dp[j] = max(dp[j], max_till_now - D * A[i][j].first + A[i][j].second);
      max_till_now = max(max_till_now, dp[j] + D * A[i][j].first);
    }
    max_till_now = INT_MIN/2;
    for(int j = A[i].size() - 1; j >= 0; j--) {
      dp2[j] = max(query(up, 1, MAX + 1, 0, A[i][j].first, MAX + 1) + U * A[i][j].first + A[i][j].second, query(down, 1, MAX + 1, 0, 1, A[i][j].first) - D * A[i][j].first + A[i][j].second);
      dp2[j] = max(dp2[j], max_till_now + U * A[i][j].first + A[i][j].second);
      max_till_now = max(max_till_now, dp2[j] - U * A[i][j].first);
    }
    for(int j = 0; j < A[i].size(); j++) {
      dp[j] = max(dp[j], dp2[j]);
      update(up, 1, MAX + 1, 0, A[i][j].first, dp[j] - U * A[i][j].first);
      update(down, 1, MAX + 1, 0, A[i][j].first, dp[j] + D * A[i][j].first);
    }
  }

  cout << dp[0] << endl;
}
