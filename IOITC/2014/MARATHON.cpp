#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define MOD 1000000007
#define INF 2000000000

int N;
vector<pair<int, int> > A;
long long dp[100010];
// start[i]..stop[i] == range of events from which any one event can be selected when the ith event is selected
// start[i] = First event which doesn't coincide with i
// stop[i] = Last event which coincides with start[i]
int start[100010], suff_start[100010], stop[100010];
set<pair<int, int> > temp;
long long bit[100002];

long long query(int i) {
  long long ans = 0;
  while(i > 0) {
    ans = (ans + bit[i]) % MOD;
    i -= i & -i;
  }
  return ans;
}

void update(int i, long long v) {
  if(i == 0) return;

  while(i <= N + 1) {
    bit[i] = (bit[i] + v) % MOD;
    i += i & -i;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  A.push_back({0, 0});

  for(int i = 1; i <= N; i++) {
    int s, e; cin >> s >> e;
    s++; e++;
    A.push_back({s, e});
  }
  A.push_back({INF, INF});
  sort(A.begin(), A.end());

  temp.clear();
  temp.insert({A[N + 1].first, N + 1});
  start[N + 1] = suff_start[N + 1] = INF;

  for(int i = N; i >= 0; i--) {
    start[i] = temp.lower_bound({A[i].second + 1, -1})->second;
    suff_start[i] = min(suff_start[i + 1], start[i]);
    temp.insert({A[i].first, i});
  }

  stop[N + 1] = INF;
  for(int i = N; i >= 0; i--) {
    if(start[i] == INF) stop[i] = INF;
    else stop[i] = suff_start[start[i]];

    if(stop[i] == INF) stop[i] = (N + 1) + 1;
  }

  dp[N + 1] = 1;
  update(N + 1, 1);
  for(int i = N; i >= 0; i--) {
    dp[i] = query(stop[i] - 1) - query(start[i] - 1);
    while(dp[i] < 0) dp[i] += MOD;
    dp[i] %= MOD;

    update(i, dp[i]);
  }
  cout << dp[0] << endl;
}

