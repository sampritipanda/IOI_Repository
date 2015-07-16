// New Year Permutation

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool graph[310][310];
int A[310];
bool visited[310];
int N;

void dfs(int curr, vector<int>& indexes, vector<int>& values){
  visited[curr] = true;
  indexes.push_back(curr);
  values.push_back(A[curr]);
  for(int i = 0; i < N; i++){
    if(graph[curr][i] && !visited[i]){
      dfs(i, indexes, values);
    }
  }
}

int main() {
  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    visited[i] = false;
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++){
      char x; scanf(" %c", &x);
      graph[i][j] = (x == '1');
    }
  }

  for(int i = 0; i < N; i++){
    if(!visited[i]){
      vector<int> indexes, values;
      dfs(i, indexes, values);
      sort(indexes.begin(), indexes.end());
      sort(values.begin(), values.end());
      for(int j = 0; j < indexes.size(); j++){
        A[indexes[j]] = values[j];
      }
    }
  }

  for(int i = 0; i < N; i++){
    printf("%d%c", A[i], " \n"[i == N - 1]);
  }
}

