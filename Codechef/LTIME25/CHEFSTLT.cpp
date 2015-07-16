// Chef and Two Strings 

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string A, B; cin >> A >> B;
    int min = 0, max = 0;

    int N = A.length();
    for(int i = 0; i < N; i++) {
      if(A[i] == '?' || B[i] == '?') max++;
      else if(A[i] != B[i]) {
        max++;
        min++;
      }
    }

    cout << min << " " << max << endl;
  }
}
