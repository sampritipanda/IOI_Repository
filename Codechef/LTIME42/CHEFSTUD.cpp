#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    int N = S.length();

    for(int i = 0; i < N; i++) {
      if(S[i] == '<') S[i] = '>';
      else if(S[i] == '>') S[i] = '<';
    }

    int ans = 0, i = 0;
    while(i < N) {
      if(i < N - 1 && S[i] == '>' && S[i + 1] == '<') {
        ans++;
        i++;
      }
      i++;
    }
    cout << ans << endl;
  }
}
