#include <iostream>
#include <algorithm>

using namespace std;

int C[101];

int main() {
  int N, D; cin >> N >> D;

  for(int i = 0; i < D; i++) {
    for(int j = 0; j < N; j++) {
      char c; cin >> c;
      if(c == '1') C[i]++;
    }
  }

  int ans = 0;
  for(int i = 0; i < D; i++) {
    for(int j = i; j < D; j++) {
      bool pos = true;
      for(int k = i; k <= j; k++) {
        if(C[k] == N) {
          pos = false;
          break;
        }
      }
      if(pos) ans = max(ans, j - i + 1);
    }
  }
  cout << ans << endl;
}
