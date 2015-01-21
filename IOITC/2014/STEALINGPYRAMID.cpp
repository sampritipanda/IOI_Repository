// Stealing the pyramid

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int curr, int A[], vector<vector<int> >& graph, vector<int>& indexes, vector<int>& values, bool visited[]){
  visited[curr] = true;
  indexes.push_back(curr);
  values.push_back(A[curr]);
  for(int i = 0; i < graph[curr].size(); i++){
    int v = graph[curr][i];
    if(!visited[v]){
      dfs(v, A, graph, indexes, values, visited);
    }
  }
}

int main() {
  int N; scanf("%d", &N);
  int A[N + 1];
  bool visited[N + 1];
  vector<vector<int> > graph(N + 1);

  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    visited[i] = false;
  }
  for(int i = 1; i <= N; i++) {
    int x; scanf("%d", &x);
    if(i - x > 0){
      graph[i].push_back(i - x);
      graph[i - x].push_back(i);
    }
    if(i + x <= N){
      graph[i].push_back(i + x);
      graph[i + x].push_back(i);
    }
  }

  for(int i = 1; i <= N; i++){
    if(!visited[i]){
      vector<int> indexes, values;
      dfs(i, A, graph, indexes, values, visited);
      sort(indexes.begin(), indexes.end());
      sort(values.begin(), values.end());
      for(int j = 0; j < indexes.size(); j++){
        A[indexes[j]] = values[j];
      }
    }
  }

  bool flag = true;
  for(int i = 1; i <= N; i++){
    if(A[i] != i) {
      flag = false;
      break;
    }
  }

  if(flag) printf("YES\n");
  else printf("NO\n");
}

