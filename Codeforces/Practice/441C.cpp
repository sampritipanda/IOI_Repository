// Valera and Tubes

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<pair<int, int> > > ans;

int main() {
  int N, M, K; cin >> N >> M >> K;
  int cells = N * M;
  int each = cells/K;

  ans.resize(K);

  int i = 1, j = 1, dir = 1;
  for(int k = 0; k < K - 1; k++) {
    for(int step = 1; step <= each; step++) {
      ans[k].push_back({i, j});
      i += dir;
      if(i == N + 1) i = N, j += 1, dir = -dir;
      else if(i == 0) i = 1, j += 1, dir = -dir;
    }
  }

  for(int step = 1; step <= cells - each * (K - 1); step++) {
    ans[K - 1].push_back({i, j});
    i += dir;
    if(i == N + 1) i = N, j += 1, dir = -dir;
    else if(i == 0) i = 1, j += 1, dir = -dir;
  }

  for(auto it: ans) {
    cout << it.size() << " ";
    for(auto it2: it) cout << it2.first << " " << it2.second << " ";
    cout << endl;
  }
}
