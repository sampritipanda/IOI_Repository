#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[10001];
bool visited[10001];

int diameter;
int node;

void dfs(int i, int dist) {
  if(visited[i]) return;
  visited[i] = true;

  if(dist > diameter) {
    diameter = dist;
    node = i;
  }

  for(auto v: tree[i]) dfs(v, dist + 1);
}

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    for(int i = 0; i <= N; i++) tree[i].clear();

    for(int i = 0; i < N - 1; i++) {
      int A, B; cin >> A >> B;
      tree[A].push_back(B);
      tree[B].push_back(A);
    }

    for(int i = 0; i <= N; i++) visited[i] = false;
    diameter = 0; node = 1;
    dfs(1, 0);
    for(int i = 0; i <= N; i++) visited[i] = false;
    diameter = 0;
    dfs(node, 0);
  }
}
