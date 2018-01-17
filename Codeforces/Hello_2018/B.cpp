#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[1001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 2; i <= N; i++) {
    int x; cin >> x;
    G[x].push_back(i);
  }

  bool pos = true;
  for(int i = 1; i <= N; i++) {
    if(G[i].size() == 0) continue;

    int cnt = 0;
    for(int x: G[i]) {
      if(G[x].size() == 0) cnt++;
    }

    if(cnt < 3) {
      pos = false;
      break;
    }
  }

  if(pos) cout << "Yes" << endl;
  else cout << "No" << endl;
}
