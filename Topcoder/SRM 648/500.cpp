// Fragile

#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool visited[21];

void dfs(int curr, vector<string>& graph) {
  visited[curr] = true;
  for(int i = 0; i < graph.size(); i++){
    if(graph[curr][i] == 'Y' && !visited[i]) dfs(i, graph);
  }
}

int countConnectedComponents(vector<string>& graph, int v1, int v2){
  int N = graph.size();
  for(int i = 0; i < N; i++) visited[i] = false;
  int count = 0;
  for(int i = 0; i < N; i++){
    if(visited[i] || i == v1 || i == v2) continue;
    count++;
    dfs(i, graph);
  }
  return count;
}

class Fragile2 {
  public:
  int countPairs(vector <string> graph) {
    int N = graph.size();
    int orig_count = countConnectedComponents(graph, -1, -1);
    int num = 0;
    for(int i = 0; i < N; i++){
      for(int j = i + 1; j < N; j++){
        vector<string> graph2(graph);
        for(int p = 0; p < N; p++) graph2[i][p] = 'N';
        for(int p = 0; p < N; p++) graph2[p][i] = 'N';
        for(int p = 0; p < N; p++) graph2[j][p] = 'N';
        for(int p = 0; p < N; p++) graph2[p][j] = 'N';
        int newCount = countConnectedComponents(graph2, i, j);
        if(newCount > orig_count) {
          num++;
        }
      }
    }

    return num;
  }
};

int main(){
  Fragile2 test;
  cout << test.countPairs({"NYNNNN", "YNYNNN", "NYNNNN", "NNNNYN", "NNNYNY", "NNNNYN"}) << endl;
}
