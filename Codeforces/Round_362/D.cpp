#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct node {
  int val;
  int C[26];

  node() {
    val = 0;
    for(int i = 0; i < 26; i++) C[i] = -1;
  }
};

int A[100];
node trie[5200];
bool G[5200][5200];
int timer = 0;
long long dp[5000][5200];

long long solve(int i, int j) {
  if(i == 0) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  long long ans = 0;
  if(j != 0) ans = solve(i, 0);
  for(int k = 0; k < 26; k++) {
    if(trie[j].C[k] != -1) {
      ans = max(ans, solve(i - 1, trie[j].C[k]) + trie[trie[j].C[k]].val);
    }
  }
  return dp[i][j] = ans;
}

void insert(int root, string S, int v) {
  for(int i = 0; i < S.length(); i++) {
    int nex = S[i] - 'a';
    if(trie[root].C[nex] == -1) {
      trie[root].C[nex] = timer++;
    }
    root = trie[root].C[nex];
  }
  trie[root].val += v;
}

void dfs(int i, int j) {
  G[i][j] = true;
  for(int k = 0; k < 26; k++) {
    if(trie[j].C[k] != -1) dfs(i, trie[j].C[k]);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; long long L; cin >> N >> L;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) {
    string S; cin >> S;
    insert(0, S, A[i]);
  }

  for(int i = 0; i < timer; i++) {
    dfs(i, i);
  }

  for(int i = 0; i <= L; i++) {
    for(int j = 0; j < timer; j++) {
      dp[i][j] = -1;
    }
  }

  cout << solve(L, 0) << endl;
}
