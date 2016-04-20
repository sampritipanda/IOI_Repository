#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int G[1001][1001];
int bit[1001][1001];
int C[1001];
long long dp[1001];

void update(int i, int j, int v) {
  while(i <= 1000) {
    int x = j;
    while(x <= 1000) {
      bit[i][x] += v;
      x += x & -x;
    }
    i += i & -i;
  }
}

int query(int i, int j) {
  int ans = 0;
  while(i > 0) {
    int x = j;
    while(x > 0) {
      ans += bit[i][x];
      x -= x & -x;
    }
    i -= i & -i;
  }
  return ans;
}

bool takes_order(int L1, int R1, int L2, int R2) {
  int x1 = L1, y1 = L2;
  int x2 = R1, y2 = R2;

  int ans = query(x2, y2);
  ans -= query(x1 - 1, y2);
  ans -= query(x2, y1 - 1);
  ans += query(x1 - 1, y1 - 1);

  return ans > 0;
}

long long solve(int i) {
  if(i == N + 1) return 0;
  if(dp[i] != -1) return dp[i];

  long long ans = LLONG_MAX/2;
  for(int g = 1; g <= N && i + g <= N + 1; g++) {
    ans = min(ans, C[g] + solve(i + g));
    for(int j = i + g; j + g <= N + 1; j += g) {
      if(takes_order(i, i + g - 1, j, j + g - 1)) {
        ans = min(ans, C[g] + solve(j + g));
      }
      else break;
    }
  }

  return dp[i] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int M; cin >> N >> M;

  while(M--) {
    int u, v; cin >> u >> v;
    G[u][v] = 1;
    update(u, v, 1);
  }

  for(int i = 1; i <= N; i++) cin >> C[i];
  for(int i = 0; i <= 1000; i++) dp[i] = -1;

  cout << solve(1) << endl;
}
