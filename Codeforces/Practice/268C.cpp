// Beautiful Sets of Points

#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<pair<int, int> > ans;

  int x = 0, y = M;
  while(x <= N && y >= 0) {
    ans.push_back({x, y});
    x++; y--;
  }

  cout << ans.size() << endl;
  for(auto it: ans) {
    cout << it.first << " " << it.second << endl;
  }

}
