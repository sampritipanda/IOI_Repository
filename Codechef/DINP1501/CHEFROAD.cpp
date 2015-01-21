// Chef and confusing road

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int N, M; scanf("%d %d", &N, &M);
  vector<vector<int> > graph(N + 1);

  for(int i = 0; i < M; i++){
    int A, B; scanf("%d %d", &A, &B);
    graph[A].push_back(B);
  }

  unsigned long long total = 0;
  for(int i = 1; i <= N; i++){
    int count[N + 1];
    for(int j = 1; j <= N; j++) count[j] = 0;

    queue<pair<int, int> > Q;
    Q.push({i,0});
    while(!Q.empty()){
      int v = Q.front().first, len = Q.front().second;
      Q.pop();

      for(auto it: graph[v]){
        if(len + 1 == 2){
          count[it]++;
        }
        else{
          Q.push({it,len+1});
        }
      }
    }

    for(int j = 1; j <= N; j++){
      if(i != j) total += (count[j] * (count[j] - 1))/2;
    }
  }

  printf("%lld\n", total);
}
