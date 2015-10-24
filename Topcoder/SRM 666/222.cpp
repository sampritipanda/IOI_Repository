#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> graph;
vector<bool> visited;

bool solve(int i) {
  if(i == -1) return true;

  if(visited[i]) return false;
  visited[i] = true;

  return solve(graph[i]);
}

class DevuAndGame {
  public:
  string canWin(vector <int> nextLevel) {
    graph = nextLevel;
    int N = graph.size();
    visited.resize(N, false);

    return solve(0) ? "Win" : "Lose";
  }
};

