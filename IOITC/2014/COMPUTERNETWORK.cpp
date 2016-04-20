#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > G[10001];  // {node, edge_id}
int dfs_num[10001], dfs_low[10001];
int timer = 0;

pair<int, int> dp[10001];  // num bridges, node
pair<int, pair<int, int> > ans; // number of bridges removed, {nodes connected}

bool compare(pair<int, int> A, pair<int, int> B) {
  if(A.first == B.first) return A.second < B.second;
  return A.first > B.first;
}

pair<int, int> min_dp_pair(pair<int, int> A, pair<int, int> B) {
  return compare(A, B) ? A : B;
}

pair<int, pair<int, int> > min_ans_pair(pair<int, pair<int, int> > A, pair<int, pair<int, int> > B) {
  if(A.first == B.first) return (A.second < B.second) ? A : B;
  return (A.first > B.first) ? A : B;
}

void dfs(int i, int p_eid) {
  dfs_num[i] = dfs_low[i] = ++timer;

  vector<pair<int, int> > entries;
  dp[i] = {0, i};
  entries.push_back(dp[i]);

  for(auto it: G[i]) {
    int u = it.first, eid = it.second;
    if(eid == p_eid) continue;

    if(dfs_num[u] == 0) {
      dfs(u, eid);

      if(dfs_low[u] > dfs_num[i]) {
        dp[i] = min_dp_pair(dp[i], {1 + dp[u].first, dp[u].second});
        entries.push_back({1 + dp[u].first, dp[u].second});
      }
      else {
        dp[i] = min_dp_pair(dp[i], dp[u]);
        entries.push_back(dp[u]);
      }

      dfs_low[i] = min(dfs_low[i], dfs_low[u]);
    }
    else {
      dfs_low[i] = min(dfs_low[i], dfs_num[u]);
    }
  }
  sort(entries.begin(), entries.end(), compare);

  if(entries.size() > 1) {
    pair<int, pair<int, int> > trial = {entries[0].first + entries[1].first, {min(entries[0].second, entries[1].second), max(entries[0].second, entries[1].second)}};
    ans = min_ans_pair(ans, trial);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 0; i < M; i++) {
    int x, y; cin >> x >> y;
    G[x].push_back({y, i});
    G[y].push_back({x, i});
  }

  ans = {0, {1, 1}};
  dfs(1, -1);

  cout << ans.second.first << " " << ans.second.second << endl;
}
