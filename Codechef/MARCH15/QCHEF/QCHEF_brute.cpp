// Chef and Problems

#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int N, M, K; scanf("%d %d %d", &N, &M, &K);
  vector<pair<int, int> > queries[N];
  vector<vector<int> > positions(M + 1);
  int ans[K];
  int A[N];

  for(int i = 0; i < N; i++) scanf("%d", &A[i]);
  for(int i = 0; i < K; i++){
    int L, R; scanf("%d %d", &L, &R);
    queries[R - 1].push_back({L - 1, i});
  }

  for(int i = 0; i < N; i++){
    positions[A[i]].push_back(i);
  }

  for(int i = 0; i < N; i++){
    for(auto q: queries[i]){
      ans[q.second] = 0;
      for(int j = i; j >= q.first; j--){
        ans[q.second] = max(ans[q.second], j - *lower_bound(positions[A[j]].begin(), positions[A[j]].end(), q.first));
      }
    }
  }

  for(int i = 0; i < K; i++) printf("%d\n", ans[i]);
}
