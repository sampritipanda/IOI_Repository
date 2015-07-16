// Document Ranking

#include <stdio.h>
#include <string>
#include <set>
#include <functional>

using namespace std;

set<pair<long long, int>, greater<pair<long long, int> > > relevance;

int main() {
  int N; scanf("%d", &N);
  long long A[N + 1]; for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
  int D; scanf("%d", &D);
  long long documents[D + 1][N + 1];

  for(int i = 1; i <= D; i++){
    long long sum = 0;
    for(int j = 1; j <= N; j++){
      scanf("%lld", &documents[i][j]);
      sum += documents[i][j] * A[j];
    }
    relevance.insert({sum, i});
  }

  int Q; scanf("%d", &Q);
  while(Q--){
    int type; scanf("%d", &type);

    if(type == 1){
      int K; scanf("%d", &K);
      int i = 0;
      for(auto it: relevance){
        if(i == K) break;
        printf("%d%c", it.second, (i == K - 1 ? '\n' : ' '));
        i++;
      }
    }
    else {
      int d, j, v; scanf("%d %d %d", &d, &j, &v);

      long long old_sum = 0;
      for(int i = 1; i <= N; i++) old_sum += documents[d][i] * A[i];
      relevance.erase(relevance.find({old_sum, d}));

      documents[d][j] = v;
      long long sum = 0;
      for(int i = 1; i <= N; i++) sum += documents[d][i] * A[i];
      relevance.insert({sum, d});
    }
  }
}
