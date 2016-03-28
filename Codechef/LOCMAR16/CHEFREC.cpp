#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int> > X;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;
  while(T--) {
    X.clear();

    int N, M; cin >> N >> M;

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        int x; cin >> x;
        X[i + j].push_back(x);
      }
    }

    for(auto it: X) {
      for(auto it2: it.second) {
        cout << it2 << " ";
      }
    }
    cout << endl;
  }
}
