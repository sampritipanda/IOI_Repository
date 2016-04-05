#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, bool> has;
vector<int> ans;

int main() {
  int N, M; cin >> N >> M;

  while(N--) {
    int x; cin >> x;
    has[x] = true;
  }

  int i = 1;
  while(i <= M) {
    if(!has[i]) {
      M -= i;
      ans.push_back(i);
    }
    i++;
  }
  cout << ans.size() << endl;
  for(auto it: ans) cout << it << " ";
  cout << endl;
}
