#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool done[26][26];

int main() {
  int T; cin >> T;

  while(T--) {
    memset(done, false, sizeof done);

    string S; cin >> S;
    int N = S.length();

    for(int i = 0; i < N - 1; i++) {
      done[S[i] - 'A'][S[i + 1] - 'A'] = true;
    }

    int cnt = 0;
    for(int i = 0; i < 26; i++) {
      for(int j = 0; j < 26; j++) {
        if(done[i][j]) cnt++;
      }
    }

    cout << cnt << endl;
  }
}
