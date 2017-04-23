#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

long long get_min(string S, int i) {
  for(int j = i + 1; j < S.length(); j++) {
    S[j] = S[i];
  }
  return stoll(S);
}

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    long long N; cin >> N;
    string S = to_string(N);
    int len = S.length();

    long long M = N;
    for(int i = 0; i < len - 1; i++) {
      if(N < get_min(S, i)) {
        if(S[i] == '1') {
          assert(i == 0);
          for(int j = 0; j < len - 1; j++) S[j] = '9';
          S.pop_back();
          M = stoll(S);
        }
        else {
          S[i] -= 1;
          for(int j = i + 1; j < len; j++) S[j] = '9';
        }
        M = stoll(S);
        break;
      }
    }

    cout << "Case #" << t << ": " << M << endl;
  }
}
