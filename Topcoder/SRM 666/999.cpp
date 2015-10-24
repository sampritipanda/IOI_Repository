#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> tree[51];
vector<int> tokens;
int dp[51][101];
int subtree_sum[51], edge_sum[51];

void dfs_calc(int i, int parent) {
  subtree_sum[i] += tokens[i];
  for(auto v: tree[i]) {
    if(v == parent) continue;

    dfs_calc(v, i);
    subtree_sum[i] += subtree_sum[v];
    edge_sum[i] += 2 + edge_sum[v];
  }
}

int solve(int i, int parent, int l) {
  if(tree[i].size() == 1 && i != 1) {
    return tokens[i];
  }

  if(dp[i][l] != -1) return dp[i][l];

  vector<int> next_sums;
  for(auto v: tree[i]) {
    if(v != parent) next_sums.push_back(subtree_sum[v]);
  }
  sort(next_sums.begin(), next_sums.end()); reverse(next_sums.begin(), next_sums.end());
  int max_i = 0, l_sum = 0;

  int ans = 0;
  for(int i = 1; i <= l; i++) {
  }
}

class CollectingTokens {
  public:
  int maxTokens(vector <int> A, vector <int> B, vector <int> tokens_t, int L_t) {
    int N = tokens.size(), L = L_t;
    tokens = tokens_t;

    memset(subtree_sum, 0, sizeof subtree_sum);
    memset(edge_sum, 0, sizeof edge_sum);
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < N - 1; i++) {
      tree[A[i]].push_back(B[i]);
      tree[B[i]].push_back(A[i]);
    }

    dfs_calc(1, -1);

    int ans = 0;
    for(int i = 1; i <= L; i++) {
      ans = max(ans, solve(1, -1, i));
    }
    return ans;
  }
};

