#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > G[300005];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  while(M--) {
    int x, y, z; cin >> x >> y >> z;
    G[x].push_back({y, z});
    G[y].push_back({x, z});
  }
}
