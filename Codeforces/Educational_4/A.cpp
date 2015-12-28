#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int N, P, Q; cin >> N >> P >> Q;
  string S; cin >> S;

  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= N; j++) {
      if(i * P + j * Q == N) {
        cout << i + j << endl;
        int ind = 0;
        for(int k = 0; k < i; k++) {
          for(int m = 0; m < P; m++) cout << S[ind++];
          cout << endl;
        }
        for(int k = 0; k < j; k++) {
          for(int m = 0; m < Q; m++) cout << S[ind++];
          cout << endl;
        }

        return 0;
      }
    }
  }

  cout << -1 << endl;
}
