// Ann and Half-Palindrome

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool dp[5011][5011];
char A[5011];
string ans;

struct trie_node {
  trie_node* children[2] = {NULL, NULL};
  int cnt = 0;
  int subtree_sum = 0;
  int i = -1, j = -1; // Indexes of the Substring represented till this node
};

void insert(trie_node* node, int start, int end) {
  for(int i = start; i <= end; i++) {
    int char_index = A[i] - 'a';
    if(node->children[char_index] == NULL) {
      node->children[char_index] = new trie_node;
      node->i = start, node->j = i;
    }
    if(dp[start][i]) node->children[char_index]->cnt++;
    node = node->children[char_index];
  }
}

int dfs_trie(trie_node* curr) {
  curr->subtree_sum = curr->cnt;
  for(int i = 0; i < 2; i++) {
    if(curr->children[i] != NULL) curr->subtree_sum += dfs_trie(curr->children[i]);
  }
  return curr->subtree_sum;
}

void search(trie_node* curr, int K) {
  if(curr == NULL) return;

  K -= curr->cnt;
  if(K <= 0) return;

  if(curr->children[0] != NULL && curr->children[0]->subtree_sum >= K) {
    ans += 'a';
    search(curr->children[0], K);
  }
  else {
    ans += 'b';
    if(curr->children[0] != NULL) K -= curr->children[0]->subtree_sum;
    search(curr->children[1], K);
  }
}

int main() {
  memset(dp, false, sizeof dp);

  string S; cin >> S;
  int N = S.length();

  // 1 - Based FTW
  for(int i = 1; i <= N; i++) A[i] = S[i - 1];

  for(int i = 1; i <= N; i++) {
    dp[i][i] = true;
    dp[i][i + 1] = (A[i] == A[i + 1]);
  }
  for(int i = 1; i + 2 <= N; i++) {
    dp[i][i + 2] = (A[i] == A[i + 2]);
    dp[i][i + 3] = (A[i] == A[i + 3]);
  }

  for(int len = 4; len <= N; len++) {
    for(int i = 1; i + len <= N; i++) {
      dp[i][i + len] = (A[i] == A[i + len]) && dp[i + 2][i + len - 2];
      dp[i][i + len + 1] = (A[i] == A[i + len + 1]) && dp[i + 2][i + len - 1];
    }
  }

  trie_node* root = new trie_node;
  for(int i = 1; i <= N; i++) {
    insert(root, i, N);
  }

  dfs_trie(root);

  int K; cin >> K;

  ans = "";
  search(root, K);

  cout << ans << endl;
}
