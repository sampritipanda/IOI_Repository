// Efficient Delivery 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<pair<int, int> > > graph;

int main() {
  int N, M; cin >> N >> M;

  graph.resize(N + 1);
  while(M--) {
    int x, y, z; cin >> x >> y >> z;
    graph[x].push_back({y, z});
    graph[y].push_back({x, z});
  }
}
