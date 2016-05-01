#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

set<string> first, second;
set<pair<string, string> > total;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int cnt = 0;
    int N; cin >> N;
    while(N--) {
      string A, B; cin >> A >> B;
      if(first.count(A) > 0 && second.count(B) > 0) {
        if(total.count({A, B}) == 0) {
          cnt++;
        }
      }
      first.insert(A);
      second.insert(B);
      total.insert({A, B});
    }
    cout << "Case #" << t << ": " << cnt << endl;
  }
}
