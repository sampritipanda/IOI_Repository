// Colorful Graph

#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

map<int, set<int> > Q;
vector<int> C;
vector<vector<int> > G;

int main() {
  int N, M; cin >> N >> M;
  G.resize(N + 1);
  C.resize(N + 1);

  for(int i = 1; i <= N; i++) cin >> C[i];

  while(M--) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(int i = 1; i <= N; i++) Q[C[i]].clear();

  for(int i = 1; i <= N; i++) {
    for(auto v: G[i]) {
      if(C[i] != C[v]) Q[C[i]].insert(C[v]);
    }
  }

  int min_color = -1, min_count = -1;
  for(auto it: Q) {
    if(int(it.second.size()) > min_count) {
      min_color = it.first;
      min_count = it.second.size();
    }
  }

  cout << min_color << endl;
}
