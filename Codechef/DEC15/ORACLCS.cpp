#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    int a = INT_MAX, b = INT_MAX;
    while(N--) {
      int x = 0, y = 0;
      string s; cin >> s;
      for(char c: s) {
        if(c == 'a') x++;
        else y++;
      }
      a = min(a, x);
      b = min(b, y);
    }
    cout << min(a, b) << endl;
  }
}
