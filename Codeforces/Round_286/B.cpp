// Mr. Kitayuta's Colorful Graph

#include <stdio.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<vector<int> > graph(101);
set<int> colors;
map<pair<int, int>, set<int> > edge_colors;

bool dfs(int start, int end, int color, bool visited[]){
  if(start == end) return true;
  if(visited[start]) return false;

  visited[start] = true;
  for(auto it: graph[start]){
    if(edge_colors[{start, it}].count(color) == 1){
      if(dfs(it, end, color, visited)) return true;
    }
  }

  return false;
}

int main() {
  int N, M; scanf("%d %d", &N, &M);

  for(int i = 0; i < M; i++){
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    graph[a].push_back(b);
    graph[b].push_back(a);
    colors.insert(c);
    edge_colors[{a, b}].insert(c);
    edge_colors[{b, a}].insert(c);
  }

  int Q; scanf("%d", &Q);
  for(int i = 0; i < Q; i++){
    int u, v; scanf("%d %d", &u, &v);
    int count = 0;
    for(auto color: colors){
      bool visited[101] = {false};
      if(dfs(u, v, color, visited)) count++;
    }

    printf("%d\n", count);
  }
}
