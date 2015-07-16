#include <stdio.h>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

struct trie_node {
  trie_node* children[26] = { NULL };
  int count = 0;
  int i = -1, j = -1, length = 0;
};

long long C[5001][5001];
long long suffix_sums_for_k[5001];
vector<int> values;
int value_count[5001];
int sa[5001], pos[5001], tmp[5001], lcp[5001];
pair<int, int> lcp_with_min[5001];
int N, gap;

bool sufCmp(int i, int j) {
  if (pos[i] != pos[j]) return pos[i] < pos[j];
  i += gap;
  j += gap;
  return (i < N && j < N) ? pos[i] < pos[j] : i > j;
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
    int Q; scanf(" %d %d", &N, &Q);
    char S_cstr[5010]; scanf(" %s", S_cstr);
    string S(S_cstr);

    values.clear();
    for(int i = 0; i <= N; i++) {
      sa[i] = tmp[i] = pos[i] = lcp[i] = 0;
      lcp_with_min[i] = {-1,-1};
      value_count[i] = 0;
      suffix_sums_for_k[i] = 0;
    }

    for(int i = 0; i < N; i++) {
      sa[i] = i;
      pos[i] = S[i];
    }
    for(gap = 1;; gap *= 2) {
      sort(sa, sa + N, sufCmp);
      for(int i = 0; i < (N - 1); i++) {
        tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
      }
      for(int i = 0; i < N; i++) {
        pos[sa[i]] = tmp[i];
      }
      if(tmp[N - 1] == N - 1) break;
    }

    for (int i = 0, k = 0; i < N; ++i)  {
      if (pos[i] == N - 1) continue;

      for(int j = sa[pos[i] + 1]; S[i + k] == S[j + k];) {
        ++k;
      }
      lcp[pos[i]] = k;

      if (k) --k;
    }

    stack<int> elements;
    for(int i = 0; i < N; i++) {
      while(!elements.empty() && lcp[i] < lcp[elements.top()]) {
        lcp_with_min[elements.top()] = { lcp[i], i };
        elements.pop();
      }
      elements.push(i);
    }

    for(int i = 0; i < N; i++) {
      if(lcp[i] == 0) continue;

      int val = lcp_with_min[i].second - i + 1;
      if(value_count[val] == 0) values.push_back(val);
      value_count[val]++;
    }
    sort(values.begin(), values.end());

    for(int i = 1; i <= N; i++) {
      long long curr_suff_sum = 0;
      auto start_it = lower_bound(values.begin(), values.end(), i);
      while(start_it != values.end()) {
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
        ans = suffix_sums_for_k[K];
      }
      printf("%lld\n", ans);
    }
  }
}
