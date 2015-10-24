#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<set<int> > A;

int main() {
  ios::sync_with_stdio(false);

  int N, M; cin >> N >> M;

  A.resize(N, set<int>());

  while(M--) {
    int type; cin >> type;

    if(type == 0) {
      int l, r, x; cin >> l >> r >> x;
      l--; r--;

      for(int i = l; i <= r; i++) {
        A[i].insert(x);
      }
    }
    else {
      int q; cin >> q; q--;
      cout << A[q].size() << endl;
    }
  }
}
