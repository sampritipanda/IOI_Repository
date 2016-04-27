#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[100001];
int label[100001];
int sz[100001];
int currComp;

void dfs(int i, int p) {
  sz[i] = 1;
  currComp++;

  for(int u: G[i]) {
    if(u == p || label[u]) continue;
    dfs(u, i);
    sz[i] += sz[u];
  }
}

int find(int i, int p) {
  for(int u: G[i]) {
    if(u == p || label[u]) continue;
    if(sz[u] >= currComp/2) return find(u, i);
  }
  return i;
}

void decompose(int i, int p, int j) {
  currComp = 0;
  dfs(i, p);

  int root = find(i, p);
  label[root] = j;

  for(int u: G[root]) {
    if(u == p || label[u]) continue;
    decompose(u, root, j + 1);
  }
}

int main() {
  int N; cin >> N;

  for(int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  decompose(1, -1, 1);

  for(int i = 1; i <= N; i++) {
    cout << char('A' + label[i] - 1) << " ";
  }
  cout << endl;
}
