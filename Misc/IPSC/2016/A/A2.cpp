#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    vector<string> A;
    string ans = "";
    for(int i = 0; i < 10; i++) {
      string S; cin >> S;
      A.push_back(S);
    }
    int a = -1, b = -1;
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
        if(i == j) continue;
        for(int k = 1; k <= 4; k++) {
          if(A[i].substr(4 - k) == A[j].substr(0, k)) {
            ans += A[i];
            for(int l = k; l < 4; l++) {
              ans += A[j][l];
            }
            a = i;
            b = j;
            break;
          }
        }
        if(a != -1) break;
      }
      if(a != -1) break;
    }

    for(int i = 0; i < 10; i++) {
      if(i == a || i == b) continue;
      ans += A[i];
    }

    while(ans.length() < 39) ans += 'A';
    assert(ans.length() == 39);
    cout << ans << endl;
  }
}
