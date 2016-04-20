#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  for(int i = 1; i <= T; i++) {
    int K, C, S; cin >> K >> C >> S;
    cout << "Case #" << i << ": ";
    for(int j = 1; j <= K; j++) {
      cout << j;
      if(j == K) cout << '\n';
      else cout << ' ';
    }
  }
}
