// Sophie

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> G[1000000];

int degree[1000000];
set<pair<int, int> > PQ;
vector<int> ans;

int main() {
  int N, K; scanf("%d %d", &N, &K);

  int M; scanf("%d", &M);

  while(M--) {
    int a, b; scanf("%d %d", &a, &b); a--; b--;
    G[b].push_back(a);
    degree[b]++;
  }

  if(N <= 25) {
    int ans_mask = -1;
    int min_size = K;

    for(int mask = 0; mask < (1 << N); mask++) {
      if(__builtin_popcount(mask) < min_size) continue;

      bool pos = true;
      for(int i = 0; i < N; i++) {
        if(!(mask & (1 << i))) continue;

        for(vector<int>::iterator it = G[i].begin(); it != G[i].end(); it++) {
          int v = *it;
          if(mask & (1 << v)) {
            pos = false;
            break;
          }
        }
        if(!pos) break;
      }

      if(pos) {
        if(ans_mask == -1) ans_mask = mask;
        else {
          if(__builtin_popcount(mask) > __builtin_popcount(ans_mask))
            ans_mask = mask;
        }
        min_size = __builtin_popcount(ans_mask);
      }
    }

    if(ans_mask == -1) printf("NIE\n");
    else {
      printf("%d\n", __builtin_popcount(ans_mask));
      vector<int> A;
      for(int i = 0; i < N; i++)
        if(ans_mask & (1 << i)) A.push_back(i + 1);

      for(int i = 0; i < A.size(); i++) {
        printf("%d%c", A[i], (i == A.size() - 1 ? '\n' : ' '));
      }
    }
  }
  else {
    for(int i = 0; i < N; i++) {
      PQ.insert(make_pair(degree[i], i));
    }

    while(!PQ.empty()) {
      int u = PQ.begin()->second; PQ.erase(PQ.begin());

      bool pos = true;
      for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); it++) {
        int v = *it;
        if(degree[v] == -1) {
          pos = false;
          break;
        }
      }
      if(!pos) continue;

      ans.push_back(u + 1);
      degree[u] = -1;

      for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); it++) {
        int v = *it;
        if(degree[v] == -1) continue;
        PQ.erase(make_pair(degree[v], v));
        degree[v] = 0;
      }
    }

    if(ans.size() < K) {
      printf("NIE\n");
    }
    else {
      sort(ans.begin(), ans.end());
      printf("%d\n", (int)ans.size());
      for(int i = 0; i < ans.size(); i++) {
        printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
      }
    }
  }
}
