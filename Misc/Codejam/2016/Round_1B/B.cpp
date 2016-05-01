#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    string C, J;
    int N;

    cin >> C >> J;
    N = C.length();

    int a = 0, b = 0;
    for(int i = 0; i < N; i++) {
      if(C[i] == '?' && J[i] == '?') {
        if(a == b) {
          C[i] = J[i] = '0';
        }
        else if(a < b) {
          C[i] = '9';
          J[i] = '0';
        }
        else {
          C[i] = '0';
          J[i] = '9';
        }
      }
      else if(C[i] == '?') {
        C[i] = J[i];
      }
      else if(J[i] == '?') {
        J[i] = C[i];
      }
    }

    cout << "Case #" << t << ": " << C << " " << J << endl;
  }
}
