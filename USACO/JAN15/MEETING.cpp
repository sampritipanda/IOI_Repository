// Meeting Time

#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  freopen("meeting.in", "r", stdin);
  freopen("meeting.out", "w", stdout);

  int N, M; scanf("%d %d", &N, &M);
  vector<vector<int> > graph(N + 1);
  int edges[N + 1][N + 1][2];

  for(int i = 0; i < M; i++){
    int A, B, C, D; scanf("%d %d %d %d", &A, &B, &C, &D);
    graph[A].push_back(B);
    edges[A][B][0] = C;
    edges[A][B][1] = D;
  }

  set<int> bessie_time, elsie_time;
  queue<pair<int, int> > bessie_Q, elsie_Q;

  bessie_Q.push({1, 0});
  while(!bessie_Q.empty()){
    auto curr = bessie_Q.front();
    int v = curr.first, time = curr.second;
    bessie_Q.pop();

    if(v == N){
      bessie_time.insert(time);
    }
    else {
      for(auto it: graph[v]){
        bessie_Q.push({it, time + edges[v][it][0]});
      }
    }
  }

  elsie_Q.push({1, 0});
  while(!elsie_Q.empty()){
    auto curr = elsie_Q.front();
    int v = curr.first, time = curr.second;
    elsie_Q.pop();

    if(v == N){
      elsie_time.insert(time);
    }
    else {
      for(auto it: graph[v]){
        elsie_Q.push({it, time + edges[v][it][1]});
      }
    }
  }

  vector<int> final_vec(bessie_time.size() + elsie_time.size());
  auto it = set_intersection(bessie_time.begin(), bessie_time.end(), elsie_time.begin(), elsie_time.end(), final_vec.begin());
  final_vec.resize(it - final_vec.begin());

  if(final_vec.size() > 0) printf("%d\n", final_vec[0]);
  else printf("IMPOSSIBLE\n");

  fclose(stdin);
  fclose(stdout);
}
