#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <cassert>

using namespace std;

vector<int> G[101];

int dist_1[101], dist_n[101];
long long ways_1[101], ways_n[101];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  while(M--) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  for(int i = 0; i <= N; i++) {
    dist_1[i] = dist_n[i] = INT_MAX;
  }

  queue<int> Q;

  dist_1[1] = 0; ways_1[1] = 1;
  Q.push(1);
  while(!Q.empty()) {
    int u = Q.front(); Q.pop();
    int d = dist_1[u];

    for(auto v: G[u]) {
      if(d + 1 < dist_1[v]) {
        dist_1[v] = d + 1;
        ways_1[v] = ways_1[u];
        Q.push(v);
      }
      else if(d + 1 == dist_1[v]) {
        ways_1[v] += ways_1[u];
      }
    }
  }

  dist_n[N] = 0; ways_n[N] = 1;
  Q.push(N);
  while(!Q.empty()) {
    int u = Q.front(); Q.pop();
    int d = dist_n[u];

    for(auto v: G[u]) {
      if(d + 1 < dist_n[v]) {
        dist_n[v] = d + 1;
        ways_n[v] = ways_n[u];
        Q.push(v);
      }
      else if(d + 1 == dist_n[v]) {
        ways_n[v] += ways_n[u];
      }
    }
  }

  double ans = 1.0000;

  for(int i = 2; i <= N - 1; i++) {
    if(dist_1[i] + dist_n[i] > dist_1[N]) continue;

    long long num_paths = ways_1[i] * ways_n[i];
    long long tot_paths = ways_1[N];

    assert(num_paths <= tot_paths);
    ans = max(ans, 2 * double(num_paths)/tot_paths);
  }

  cout << fixed << setprecision(10) << ans << endl;
}
