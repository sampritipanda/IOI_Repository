#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int> > G[105][105];
set<pair<int, int> > A;
bool visited[105][105];

// #define in cin
// #define out cout

int main() {
  ifstream in("lightson.in");
  ofstream out("lightson.out");

  int N, M; in >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      G[i][j].clear();
    }
  }

  while(M--) {
    int x, y, a, b; in >> x >> y >> a >> b;
    G[x][y].push_back({a, b});
  }

  queue<pair<int, int> > Q;
  memset(visited, false, sizeof visited);

  A.insert({1, 1});
  Q.push({1, 1});
  while(!Q.empty()) {
    auto t = Q.front(); Q.pop();
    int x = t.first, y = t.second;

    if(x < 1 || x > N || y < 1 || y > N) continue;
    if(!(visited[x - 1][y] || visited[x + 1][y] || visited[x][y - 1] || visited[x][y + 1] || x == 1 && y == 1)) continue;

    if(A.count({x, y}) == 0) continue;
    if(visited[x][y]) continue;
    visited[x][y] = true;

    for(auto it: G[x][y]) {
      A.insert(it);
      Q.push(it);
    }

    Q.push({x + 1, y});
    Q.push({x - 1, y});
    Q.push({x, y + 1});
    Q.push({x, y - 1});
  }

  out << A.size() << endl;
}

