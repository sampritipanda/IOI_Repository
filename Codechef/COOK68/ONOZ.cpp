#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool check(string S) {
  for(int i = 1; i < S.length(); i++) {
    if(S[0] != S[i]) return false;
  }
  return true;
}

int main() {
  int T; cin >> T;

  while(T--) {
    int H, M; cin >> H >> M;
    int ans = 0;
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < M; j++) {
        string S = to_string(i) + to_string(j);
        if(check(S)) ans++;
      }
    }
    cout << ans << endl;
  }
}
