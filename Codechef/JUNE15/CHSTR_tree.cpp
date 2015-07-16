#include <stdio.h>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

struct trie_node {
  trie_node* children[26] = { NULL };
  int count = 0;
};

int values[5010];
int val_index = 0;
int value_count[5010];
long long C[5001][5001];
long long suffix_sums_for_k[5001];

void add_string(trie_node* root, string S) {
  int N = S.length();
  for(int i = 0; i < N; i++) {
    if(root->children[S[i] - 'a'] == NULL) root->children[S[i] - 'a'] = new trie_node;
    root = root->children[S[i] - 'a'];
    root->count += 1;
  }
}

void dfs(trie_node* curr) {
  if(curr->count == 1) return;

  if(curr->count > 1) {
    if(value_count[curr->count] == 0) values[val_index++] = curr->count;
    value_count[curr->count]++;
  }

  for(int i = 0; i < 26; i++) {
    if(curr->children[i] != NULL) dfs(curr->children[i]);
  }
}

int main() {
  for (int i = 0; i <= 5000; i++) {
    for (int j = 0; j <= i; j++)  {
      if (j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
  }

  int T; scanf(" %d", &T);

  while(T--){
    for(int i = 0; i <= 5000; i++) {
      values[i] = 0;
      value_count[i] = 0;
      suffix_sums_for_k[i] = 0;
    }

    trie_node* trie = new trie_node;

    int N, Q; scanf(" %d %d", &N, &Q);
    char S_cstr[5010]; scanf(" %s", S_cstr);
    string S(S_cstr);

    for(int i = 1; i <= N; i++){
      add_string(trie, S.substr(N - i, i));
    }

    dfs(trie);
    sort(values, values + val_index);

    for(int i = 1; i <= N; i++) {
      long long curr_suff_sum = 0;
      auto start_it = lower_bound(values, values + val_index, i);
      while(start_it != values + val_index) {
        curr_suff_sum = (curr_suff_sum + C[*start_it][i] * value_count[*start_it]) % MOD;
        start_it++;
      }
      suffix_sums_for_k[i] = curr_suff_sum;
    }

    while(Q--) {
      int K; scanf(" %d", &K);
      long long ans = 0;
      if(K == 1) {
        ans = (((N * (N + 1)))/2) % MOD;
      }
      else if (K <= N) {
        ans += suffix_sums_for_k[K];
      }
      printf("%lld\n", ans);
    }
  }
}
