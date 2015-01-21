// Chef and moon

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

int main() {
  int N, M, K; scanf("%d %d %d", &N, &M, &K);
  unsigned long long dist[N + 1][N + 1];
  vector<vector<int> > graph(N + 1);

  for(int i = 0; i < M; i++){
    int A, B, C; scanf("%d %d %d", &A, &B, &C);
    graph[A].push_back(B);
    graph[B].push_back(A);
    dist[A][B] = C;
    dist[B][A] = C;
  }

  int Q; scanf("%d", &Q);

  for(int i = 0; i < Q; i++){
    int U, V; scanf("%d %d", &U, &V);
    vector<unsigned long long> cost(N + 1, -1);
    cost[U] = 0;
    set<pair<unsigned long long, int> > Q;

    Q.insert({0, U});
    while(!Q.empty()){
      pair<int, int> node = *Q.begin();
      Q.erase(Q.begin());

      int v = node.second, d = node.first;
      for(auto it: graph[v]){
        if(cost[it] > cost[v] + dist[v][it]){
          if(cost[it] != -1ULL){
            Q.erase({cost[it], it});
          }
          cost[it] = cost[v] + dist[v][it];
          Q.insert({cost[it], it});
        }
      }
    }

    if(cost[V] <= K) printf("YES\n");
    else printf("NO\n");
  }
}
