#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<pair<int, int> > ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  set<int> S;
  int prev = 1;
  for(int i = 1; i <= N; i++) {
    int x; cin >> x;
    if(S.count(x) == 1) {
      ans.push_back({prev, i});
      S.clear();
      prev = i + 1;
    }
    else {
      S.insert(x);
    }
  }

  bool pos = true;
  if(S.size() > 0) {
    if(ans.size() == 0) pos = false;
    else ans[ans.size() - 1].second = N;
  }

  if(pos) {
    cout << ans.size() << endl;
    for(auto it: ans) cout << it.first << " " << it.second << endl;
  }
  else {
    cout << -1 << endl;
  }
}
