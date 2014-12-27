#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class TallShoes {
  public:
  int maxHeight(int, vector <int>, vector <int>, vector <int>, long long);
};

int dfs(int N, vector<vector<int> >& graph, bool* visited, std::vector<int>& height, int v){
  if(v == N - 1) return height[N - 1];
  visited[v] = true;
  int maxHeight = 0;
  for(vector<int>::iterator i = graph[v].begin(); i != graph[v].end(); ++i){
    if(!visited[*i]){
      int minHeight = std::min(height[v], dfs(N, graph, visited, height, *i));
      if(minHeight > maxHeight) maxHeight = minHeight;
    }
  }
  return maxHeight;
}

int TallShoes::maxHeight(int N, vector <int> X, vector <int> Y, vector <int> height, long long B) {
  vector<vector<int> > graph(N);
  bool visited[N];
  for(int i = 0; i < N; i++){
    visited[i] = false;
    graph[X[i]].push_back(Y[i]);
    graph[Y[i]].push_back(X[i]);
  }

  int maxPoss = dfs(N, graph, visited, height, 0);
  int increase = int(sqrt(B));
  return (maxPoss + increase);
}
