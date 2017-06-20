#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 200000;
const int BLOCK_SIZE = 500;
int H[200001];
int P[200001];
vector<int> G[200001];
vector<int> regions[25001];
vector<int> regions_time[25001];
vector<int> large_regions;
int large_id[25001];
int timer = 0;
int S[200001], rev_S[200001], E[200001];
int sz[200001];
int S2L[25001][MAX_N/BLOCK_SIZE];
int L2A[MAX_N/BLOCK_SIZE][25001];
int cnt[25001];

void dfs(int u) {
  S[u] = ++timer;
  rev_S[S[u]] = u;
  sz[u] = 1;
  regions_time[H[u]].push_back(S[u]);

  for(int v: G[u]) {
    dfs(v);
    sz[u] += sz[v];
  }

  E[u] = timer;
}

void dfs_large(int i, int r, int cnt = 0) {
  L2A[large_id[r]][H[i]] += cnt;
  if(H[i] == r) cnt++;

  for(int u: G[i]) {
    dfs_large(u, r, cnt);
  }
}

void dfs_small(int i, int keep) {
  int heavy_child = -1, max_size = -1;
  for(int u: G[i]) {
    if(sz[u] > max_size) {
      max_size = sz[u];
      heavy_child = u;
    }
  }

  for(int u: G[i]) {
    if(u != heavy_child) dfs_small(u, 0);
  }
  if(heavy_child != -1) dfs_small(heavy_child, 1);

  for(int u: G[i]) {
    if(u == heavy_child) continue;
    for(int j = S[u]; j <= E[u]; j++) {
      cnt[H[rev_S[j]]]++;
    }
  }
  cnt[H[i]]++;

  for(int x: large_regions) {
    S2L[H[i]][large_id[x]] += cnt[x];
  }

  if(!keep) {
    for(int j = S[i]; j <= E[i]; j++) {
      cnt[H[rev_S[j]]]--;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, R, Q; cin >> N >> R >> Q;

  cin >> H[1];
  regions[H[1]].push_back(1);
  for(int i = 2; i <= N; i++) {
    cin >> P[i] >> H[i];
    G[P[i]].push_back(i);
    regions[H[i]].push_back(i);
  }

  for(int i = 1; i <= R; i++) {
    large_id[i] = -1;
    if(regions[i].size() >= BLOCK_SIZE) {
      large_regions.push_back(i);
      large_id[i] = large_regions.size() - 1;
    }
  }

  dfs(1);

  for(int x: large_regions) {
    dfs_large(1, x);
  }

  dfs_small(1, 1);

  while(Q--) {
    int r1, r2; cin >> r1 >> r2;

    if(large_id[r1] != -1) {
      cout << L2A[large_id[r1]][r2] << endl;
    }
    else if(large_id[r2] != -1) {
      cout << S2L[r1][large_id[r2]] << endl;
    }
    else {
      int ans = 0;
      for(int x: regions[r1]) {
        ans += upper_bound(regions_time[r2].begin(), regions_time[r2].end(), E[x]) - lower_bound(regions_time[r2].begin(), regions_time[r2].end(), S[x]);
      }
      cout << ans << endl;
    }
  }
}

