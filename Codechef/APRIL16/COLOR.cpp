#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    string S; cin >> S;

    int R = 0, G = 0, B = 0;
    for(char c: S) {
      if(c == 'R') R++;
      else if(c == 'G') G++;
      else B++;
    }

    cout << min(N - R, min(N - G, N - B)) << endl;
  }
}
