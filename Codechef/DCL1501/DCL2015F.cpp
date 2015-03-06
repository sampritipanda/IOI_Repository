// Restaurant and dishes

#include <iostream>
#include <vector>

using namespace std;

void dfs(int curr, vector<vector<int> >& graph, vector<int>& indegree, vector<int>& outdegree, vector<bool>& visited){
  if(visited[curr]) return;

  visited[curr] = true;
  for(auto v: graph[curr]){
    outdegree[curr]++;
    indegree[v]++;
    dfs(v, graph, indegree, outdegree, visited);
  }
}

int main() {
  int N, D; cin >> N >> D;
  vector<vector<int> > graph(N);

  for(int i = 0; i < N; i++){
    int A, B; cin >> A >> B;
    graph[A].push_back(B);
  }

  vector<int> indegree(N, 0);
  vector<int> outdegree(N, 0);
  vector<bool> visited(N, false);

  for(int i = 0; i < N; i++){
    if(visited[i]) continue;
    dfs(i, graph, indegree, outdegree, visited);
  }

  bool flag = true;
  for(int i = 0; i < N; i++){
    if(indegree[i] > 1 || outdegree[i] > 1) {
      flag = false;
      break;
    }
  }

  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}
