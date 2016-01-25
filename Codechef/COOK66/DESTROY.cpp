#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    map<int, int> M;
    set<pair<int, int> > M2;

    for(int i = 0; i < N; i++) {
      int x; cin >> x;
      M[x]++;
    }

    for(auto it: M) {
      M2.insert({it.second, it.first});
    }

    int ans = 0;
    while(!M2.empty()) {
      if(M2.size() == 1) {
        ans += M2.begin()->first;
        M2.erase(M2.begin());
      }
      else {
        auto it = M2.rbegin();
        pair<int, int> A = *it; pair<int, int> A2 = A;
        it++;
        pair<int, int> B = *it; pair<int, int> B2 = B;

        int curr = 1;
        ans += curr;
        A2.first -= curr;
        B2.first -= curr;

        M2.erase(A); M2.erase(B);
        if(A2.first != 0) M2.insert(A2);
        if(B2.first != 0) M2.insert(B2);
      }
    }

    cout << ans << endl;
  }
}
