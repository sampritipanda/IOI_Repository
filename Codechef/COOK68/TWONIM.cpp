#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    map<int, int> M;
    for(int i = 0; i < N; i++) {
      int x; cin >> x;
      M[x]++;
    }

    set<int> A;
    for(auto it: M) {
      int freq = it.second % 2;
      if(freq == 1) {
        A.insert(it.first);
      }
    }

    int player = 1;
    while(true) {
      int curr = 0;
      for(auto x: A) curr ^= x;
      if(curr == 0) break;

      int min_impact = 1000, elem = 0;
      for(auto x: A) {
        int impact = 0;
        for(int i = 8; i >= 0; i--) {
          if((curr & (1 << i)) && (x & (1 << i))) impact++;
        }
        if(impact < min_impact) {
          min_impact = impact;
          elem = x;
        }
      }

      A.erase(elem);
      player = (player == 1 ? 2 : 1);
    }

    cout << (player == 1 ? "First" : "Second") << endl;
  }
}
