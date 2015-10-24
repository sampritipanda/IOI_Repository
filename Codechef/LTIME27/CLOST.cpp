#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;

    vector<char> str(N, '-');
    map<pair<int, int>, bool> queries;

    while(K--) {
      int L, R; cin >> L >> R;
      queries[{L, R}] = false;
    }

    for(int len = 2; len <= N; len += 2) {
      for(auto q: queries) {
        int L = q.first.first, R = q.first.second;
        if(R - L + 1 != len) continue;
        bool open = true;
        for(int i = L; i <= R; i++) {
          if(str[i] == '-') {
            str[i] = (open ? '(' : ')');
            open = !open;
          }
        }
      }
    }

    bool open = true;
    for(int i = 0; i < N; i++) {
      if(str[i] == '-') {
        str[i] = (open ? '(' : ')');
        open = !open;
      }
    }


    for(auto it: str) cout << it;
    cout << endl;
  }
}
