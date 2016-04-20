#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    string S; cin >> S;
    int N = S.length();

    int ans = 0;
    while(true) {
      bool done = true;
      for(int i = 0; i < N; i++) {
        if(S[i] == '-') {
          done = false; break;
        }
      }
      if(done) break;

      ans++;

      int i;
      for(i = 0; i < N; i++) {
        if(S[i] != S[0]) break;
      }
      reverse(S.begin(), S.begin() + i);
      for(int j = 0; j < i; j++) {
        S[j] = (S[j] == '+' ? '-' : '+');
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
