#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <climits>

using namespace std;

inline int scan() {
  int N = 0;
  char c = getchar_unlocked();
  while(c < '0' || c > '9') {
      c = getchar_unlocked();
    }

  while(c >= '0' && c <= '9') {
      N = (N<<1) + (N<<3) + c - '0';
      c = getchar_unlocked();
    }

  return N;
}

vector<int> G[500001];  // Out-Graph
vector<int> G2[500001]; // In-Graph
int dp[500001];    // Longest path ending at i
int dp2[500001];   // Longest path starting at i
vector<int> top;  // Topological Order
vector<int> layer[500001];  // Nodes in Layer
int D[500001];
queue<pair<int, int> > Q;
int bit[1000001];
int edge_cnt = 0;

void upd(int x, int v) {
  edge_cnt += v;
  while(x <= 1000000) {
    bit[x] += v;
    x += x & -x;
  }
}

int query(int x) {
  int ans = 0;
  while(x > 0) {
    ans += bit[x];
    x -= x & -x;
  }
  return ans;
}

int find_max() {
  int max_val = query(1000000) - 1;
  int range = 1 << 19;
  int id = 0;

  while(range > 0 && id < 1000000) {
    int test = id + range;
    if(bit[test] <= max_val) {
      id = test;
      max_val -= bit[test];
    }
    range >>= 1;
  }

  return id + 1;
}

int main() {
  int N = scan(), M = scan();

  while(M--) {
    int a = scan(), b = scan();
    G[a].push_back(b);
    G2[b].push_back(a);
  }

  for(int i = 1; i <= N; i++) {
    sort(G[i].begin(), G[i].end());
    G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());

    sort(G2[i].begin(), G2[i].end());
    G2[i].resize(unique(G2[i].begin(), G2[i].end()) - G2[i].begin());

    D[i] = G2[i].size();
  }

  for(int i = 1; i <= N; i++) {
    if(D[i] == 0) {
      Q.push(make_pair(i, 0));
    }
  }

  int K = 0;
  while(!Q.empty()) {
    int u = Q.front().first, t = Q.front().second; Q.pop();
    top.push_back(u);
    layer[t].push_back(u);
    K = max(K, t + 1);
    for(int j = 0; j < G[u].size(); j++) {
      int v = G[u][j];
      D[v]--;
      if(D[v] == 0) Q.push(make_pair(v, t + 1));
    }
  }

  for(int j = 0; j < top.size(); j++) {
    int u = top[j];
    if(G2[u].size() == 0) {
      dp[u] = 0;
    }
    else {
      for(int k = 0; k < G2[u].size(); k++) {
        int p = G2[u][k];
        dp[u] = max(dp[u], dp[p] + 1);
      }
    }
  }

  for(int j = top.size() - 1; j >= 0; j--) {
    int u = top[j];
    if(G[u].size() == 0) {
      dp2[u] = 0;
    }
    else {
      for(int k = 0; k < G[u].size(); k++) {
        int v = G[u][k];
        dp2[u] = max(dp2[u], dp2[v] + 1);
      }
    }
  }

  int ans = INT_MAX/2, ans_node = -1;

  for(int l = 0; l < K; l++) {
    pair<int, int> max1 = make_pair(-1,-1), max2 = make_pair(-1, -1);
    for(int i = 0; i < layer[l].size(); i++) {
      int u = layer[l][i];
      if(dp[u] + dp2[u] > max1.first) {
        if(max1.first != -1) max2 = max1;
        max1 = make_pair(dp[u] + dp2[u], u);
      }
      else if(dp[u] + dp2[u] > max2.first) {
        max2 = make_pair(dp[u] + dp2[u], u);
      }
      for(int j = 0; j < G2[u].size(); j++) {
        int p = G2[u][j];
        upd(dp[p] + 1 + dp2[u], -1);
      }
    }

    for(int i = 0; i < layer[l].size(); i++) {
      int u = layer[l][i];
      int curr = max(dp[u] - 1, dp2[u] - 1);
      if(edge_cnt > 0) curr = max(curr, find_max());
      if(layer[l].size() > 1) {
        if(max1.second != u) curr = max(curr, max1.first);
        else curr = max(curr, max2.first);
      }

      if(curr < ans) {
        ans = curr;
        ans_node = u;
      }
    }

    for(int i = 0; i < layer[l].size(); i++) {
      int u = layer[l][i];
      for(int j = 0; j < G[u].size(); j++) {
        int v = G[u][j];
        upd(dp[u] + 1 + dp2[v], 1);
      }
    }
  }

  printf("%d %d\n", ans_node, ans);
}
